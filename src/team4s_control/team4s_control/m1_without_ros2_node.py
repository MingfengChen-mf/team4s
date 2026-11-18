"""
m1_node_v2.py —— M1 中枢（决策内核，无 ROS 依赖；套成 ROS2 节点只需接三个回调）

严格按《规控组架构与分工说明》的边界：
  M1 只做  ① 看门狗 ② 健康分级 ③ 适配 ④ 事件确认 ⑤ 状态转移 ⑥ 仲裁 ⑦ 发布
  M1 不做  横向控制律 / 避障方向选择 / 标定换算 / 速度曲线
行为模块通过构造参数注入（m2 / m3 / m4 都是 decide(ctx) -> (steer, speed)）。
模块没注入或返回 (None, None) 时 → 无赢家 → 零速铁律，**不做任何兜底速度**。

本轮（20261116 坐标修订版）修订清单，逐条给依据
------------------------------------------------
A. target_lane 语义纠正（**最重要**）
   v2 规范 §三：FIRST = 沿任务行驶方向的主路左车道，SECOND = 主路右车道，
   是**车道身份**；"不能按图像候选数组下标赋身份，也不能当成两条弯曲侧支线"。
   上一版在进 AVOID 时 `self.target_lane = 2`，把"避障后"当成 SECOND —— 这是 v1
   接口说明里的旧理解（"避障前第一车道/避障后第二车道"）。
   后果是双向的：① 感知按 target_lane=SECOND 去选右车道候选，车会往旁边车道偏；
   ② TaskState 报的车道身份与实车所在车道不符，感知侧米值全部算在错的车道上。
   已删除该赋值。避障绕行后回归的是**同一条**主车道。

B. 终点判据从"事件锁存"改成"当前帧可见 + 近距行阈值"
   上一版 `_end_cond()` = `ctx.events.end_seen and (y2 is None or y2 >= trig)`，
   而 end_seen 由 red_latch 锁存。任务一起点终点同位（任务书原文"起点和终点在同一
   位置"），发车瞬间红锥就在车旁 → 锁存立即为真 → 之后**只要 y2 为 None 就恒为真**
   → 过完斑马线（zebra_count≥1）立刻 FINISH 停车。
   实际后果：一圈跑不完，评分 2.1 的"到达终点 2 分 + 按要求停车 1 分"记 0，
   2.3 弯道 30 分因为提前停车也全部拿不到。
   现在：FINISH 必须 **当前帧** 红锥可见（或 confirmed）且底边行 ≥ end_trig_y2。
   锁存只保留为"本轮曾确认过终点事件"的记忆，写进 reason / 日志，不再参与判转移。

C. 圈数判定收紧（§三"lap_complete 由规控判断，仅再次看见斑马线不证明完成一圈"）
   任务一：zebra_count ≥ 1（过线事件）**且** 已到红锥终点 → 才置 lap_complete。
   任务二：直道没有"圈"的概念，**不置 lap_complete**，完成与否由
   control_mode=FINISHED 表达（上一版把任务二也置 lap_complete=True，语义错误，
   感知侧若拿它判"完成一圈"会得到假结论）。

D. 事件去重按 (run_id, source_session_id, event_id)（§五），并加斑马线冷却
   同一处斑马线在视野边界抖动时会反复进出 SLOWDOWN，把 zebra_count 计成 2、3，
   任务一就会"过第一条斑马线就以为完成一圈"。现在每次计数后有 zebra_cooldown_s
   冷却，且 run 切换时清空全部锁存与防抖计数。

E. TaskState 发布交给 TaskStatePublisher（§三）
   sequence 实例级严格递增、header.stamp 由调用方注入车上 ROS 时间、10Hz 心跳 +
   状态变化立即发。上一版有两套并行的 phase/mode 计算（本文件 task_state() 与
   task_state_bridge.build），口径已经漂移，现在只留 bridge 一处。

F. 适配层透传 now_s 与本地 run_id（§六/§三）
   adapter 需要当前时间判采集年龄、需要本地 run_id 判 snapshot 是否属于本轮。

保留的历史修正（不再重复说明，见 00-M1改进建议.md）：
  丢线不兜底成 V_CRUISE、事件防抖按子流 sequence、像素行阈值代替米制距离、
  底盘反馈只回填 speed_rpm、AVOID/JUNCTION 超时停车重试而非 ESTOP 锁存。
"""

from __future__ import annotations   # Py3.8 兼容：NodeCfg | None 等仅作字符串注解（Foxy 容器 Py3.8）

import os
import sys
from dataclasses import dataclass

_HERE = os.path.dirname(os.path.abspath(__file__))
_ROOT = os.path.dirname(_HERE)
for _p in (_HERE, _ROOT):
    if _p not in sys.path:
        sys.path.insert(0, _p)

from contract import (  # noqa: E402
    State, Ctx, Command, arbitrate, LAT_PRIORITY, LON_PRIORITY,
    STEER_CENTER, RPM2VEL,
    V_SLOW,
    LINE_LOST_TIMEOUT, AVOID_TIMEOUT, JUNCTION_TIMEOUT, SLOWDOWN_TIMEOUT,
    STALE_TIMEOUT, OBST_TRIG, TASK_STATE_PERIOD_S,
)
from adapter_v2 import Adapter, AdapterCfg, health_verdict, read_health  # noqa: E402
from task_state_bridge import (  # noqa: E402
    TaskStatePublisher,
    TASK_LAP, TASK_STRAIGHT, LANE_FIRST,
)


# =====================================================================
@dataclass
class NodeCfg:
    """M1 自己的参数。凡是标 PLACEHOLDER 的，都必须上车实测一次再定。"""
    # --- 事件确认 ---
    db_frames: int = 3            # 需要几张**新图**（按 scene.meta.sequence 计）
    # 时间下限默认为 0：因为"新图张数"本身已经与帧率无关。
    # 只有当你怀疑子流 sequence 不可信（比如上游伪造序号）时才启用它。
    db_min_time: float = 0.0
    # 斑马线事件冷却 s（修订 D）：同一处斑马线在视野边界抖动时会反复进出 SLOWDOWN，
    # 计成多次"过线事件"会让任务一提前判"完成一圈"。3.0 s 对应 0.385 m/s 下约 1.15 m，
    # 大于一处斑马线的可视纵深，能吞掉抖动又不会吞掉第二个真事件。
    zebra_cooldown_s: float = 3.0

    # --- 丢线安全阶梯（M1 的安全兜底，只允许降速，不允许提速）---
    lost_hold_s: float = 0.15     # < 此值：保持 M2 上一次的输出
    lost_stop_s: float = 0.40     # < 此值：停车等线；> LINE_LOST_TIMEOUT 走故障停车

    # --- 斑马线：像素行阈值（y2 越大越近）---
    zebra_trig_y2: float = 132.0      # PLACEHOLDER：把车停在"该开始减速"的位置读 y2
    zebra_exit_y2: float = 150.0      # 保留作兜底旋钮：若实测 y2 卡死不消失，可改回行阈值退出
    # 0.80→2.00（20261116）：依据 AI_HANDOFF §10 T2 验收「低速段 ≥ 0.5m」，
    # V_SLOW=0.25 m/s → 0.5/0.25 = 2.0s。旧值 0.8s 只覆盖约 0.17m，不满足验收。
    zebra_min_time: float = 2.00      # 进入后至少保持这么久（评分要"可观察到减速"+低速段）
    zebra_speed: float = V_SLOW       # 减速目标速度（M1 给上限，M4 可在其内再调）

    # --- 终点：像素行阈值 ---
    end_trig_y2: float = 120.0        # PLACEHOLDER：红锥该开始终点程序的行
    end_brake_y2: float = 145.0       # PLACEHOLDER：红锥该刹停的行

    # --- 避障 ---
    obst_clear_m: float = 1.60        # 退出滞环
    avoid_retry_stop_s: float = 1.2
    max_avoid_retry: int = 3
    # 视觉锥桶兜底避障的触发行（与 AdapterCfg.vision_obstacle_y2_trig 配套）。
    # 只有 adapter 明确给出 obstacle_source=='vision_cone' 时才用像素行判据；
    # 雷达正常时永远走 dist<OBST_TRIG 的米制判据，两条互不干扰。
    vision_avoid_y2: float = 150.0

    # --- 降级限速 ---
    # 取 V_SLOW：巡航 0.385（20261116 满电标定），V_SLOW 0.25 比它低 35%，降级可观察到。
    v_degrade: float = V_SLOW
    stale_timeout: float = STALE_TIMEOUT

    # --- TaskState 发布 ---
    task_state_period_s: float = TASK_STATE_PERIOD_S   # 10Hz 心跳（§三）
    task_state_stop_eps: float = 0.01                  # 判"停稳"的底盘速度阈值 m/s

    lane: AdapterCfg = None

    def __post_init__(self):
        if self.lane is None:
            self.lane = AdapterCfg()


# =====================================================================
class M1NodeV2:
    """
    用法（ROS2 节点里）:
        node.m1 = M1NodeV2(task_id=1, m2=m2_track.decide,
                           m3=m3_avoid.decide, m4=m4_slowdown.decide)
        # 订阅回调
        def on_msg(msg):
            node.m1.on_snapshot(msg, node.now_s())
        # timer 0.05
        def tick():
            node.m1.tick(node.now_s(), dt)
            node.cmd_pub.publish(to_cmd(node.m1.last_cmd))
            ts = node.m1.publish_task_state(node.now_ns())     # 10Hz 心跳，返回 None 表示这拍不发
            if ts is not None:
                node.ts_pub.publish(fill(TaskState(), ts))
    """

    def __init__(self, task_id: int = TASK_LAP, target_lane: int = LANE_FIRST,
                 cfg: NodeCfg | None = None, m2=None, m3=None, m4=None):
        self.cfg = cfg or NodeCfg()
        self.adapter = Adapter(self.cfg.lane)
        self.task_id = task_id

        # TaskState 发布器（session 在这里生成一次，进程存活期间不变）
        self.pub_state = TaskStatePublisher(task_id=task_id, target_lane=target_lane,
                                            period_s=self.cfg.task_state_period_s)
        self.target_lane = self.pub_state.target_lane
        self.run_id = self.pub_state.run_id
        self.adapter.expected_run_id = self.run_id

        # 行为模块（纯函数，由外部注入；None = 未就位）
        self.m2, self.m3, self.m4 = m2, m3, m4

        self.ctx = Ctx(state=State.IDLE)
        self.prev_ctx = None

        self.snapshot = None
        self.last_snapshot_time = None
        self.stale = False

        self.start_requested = False
        self.start_source = ''

        self.s = 0.0                 # 仅用于日志/兜底上限，不参与成败判定
        self.speed_rpm_fb = 0        # 底盘原始转速，原样填回 ctx.chassis
        self.speed_fb = 0.0          # 同上的 m/s 视图（R_EFF 未验收，只看量级）

        self.now = 0.0
        self.line_lost_age = 0.0
        self.state_timer = 0.0
        self.estop_since = None
        self.retry_stop = 0.0
        self.avoid_retry = 0

        self._db = {}
        self.zebra_count = 0
        self.zebra_last_t = None
        self.lap_complete = False

        self.last_cmd = Command(steer=STEER_CENTER, speed=0.0, source='INIT')
        self.log = []

    # ---------------------------------------------------------------
    # 外部接口
    # ---------------------------------------------------------------
    def on_snapshot(self, snapshot, now_s):
        self.snapshot = snapshot
        self.last_snapshot_time = now_s
        self.stale = False

    def on_chassis(self, speed_rpm: float):
        """底盘回传转速。原始 rpm 原样留存（tick 里填回 ctx.chassis），
        m/s 视图另外存一份，只给日志看。"""
        self.speed_rpm_fb = int(round(float(speed_rpm)))
        self.speed_fb = float(speed_rpm) * RPM2VEL

    def on_start_signal(self, source: str = 'unknown'):
        """出发信号。来源必须是真实的：
        · 底盘节点发布的遥控/启动状态话题（推荐，需底盘方加 publisher）
        · 感知组"起点区域清空"确认
        没有来源就别调；M1 会一直停在 IDLE。

        依据评分 2.1「接到允许的遥控启动指令后，小车自主起步并进入主车道」——
        "允许"这一步只有外部知道（遥控直连底盘，M1 读不到），所以入口必须显式。
        """
        self.start_requested = True
        self.start_source = source

    def on_new_run(self, attempt: int = 1, task_id: int | None = None,
                   target_lane: int | None = None):
        """开新一轮任务：换 run_id、清事件锁存与防抖、复位圈数与计时。

        §三「每轮任务生成新 run_id」；§五「事件按 run_id … 去重」——新一轮必须清，
        否则上一轮的红锥锁存会把这一轮起步就判成到达终点（修订 B 的同一类坑）。
        """
        self.run_id = self.pub_state.new_run(attempt=attempt, task_id=task_id,
                                             target_lane=target_lane)
        if task_id is not None:
            self.task_id = int(task_id)
        self.target_lane = self.pub_state.target_lane
        self.adapter.expected_run_id = self.run_id
        self.adapter.reset_events()
        self._db.clear()
        self.zebra_count = 0
        self.zebra_last_t = None
        self.lap_complete = False
        self.start_requested = False
        self.start_source = ''
        self.line_lost_age = 0.0
        self.estop_since = None
        self.avoid_retry = 0
        self.retry_stop = 0.0
        self.s = 0.0
        self.ctx.state = State.IDLE
        return self.run_id

    def set_target_lane(self, lane: int):
        """切换目标车道（任务指定，不是自动推断）。

        §三「单圈任务固定指定目标车道」+ 感知侧「目标切换需要新消息」：
        这里只改字段，下一拍 offer() 会因状态签名变化**立即**发一条新的 TaskState。
        """
        self.pub_state.set_target_lane(lane)
        self.target_lane = self.pub_state.target_lane

    def reset_estop(self):
        self.estop_since = None

    # ---------------------------------------------------------------
    def tick(self, now_s: float, dt: float):
        dt = max(0.0, min(dt, 0.1))
        self.now = now_s

        # ① 看门狗（接收超时，与感知组元数据无关的本地兜底）
        if self.last_snapshot_time is None:
            self.stale, reason = True, 'snapshot_never_received'
        else:
            age = now_s - self.last_snapshot_time
            self.stale = age > self.cfg.stale_timeout
            reason = f'snapshot_stale_{age:.2f}s' if self.stale else ''
        if self.stale:
            self._emit(0.0, STEER_CENTER, reason or 'WATCHDOG')
            return

        # ② 健康分级
        health = read_health(self.snapshot)
        verdict, faults, degraded = health_verdict(health, self.cfg.lane)

        # ③ 适配（传 now_s 判采集年龄，传本地 run_id 判是否本轮数据）
        self.prev_ctx = self.ctx
        self.ctx = self.adapter.to_ctx(self.snapshot, self.target_lane,
                                       self.prev_ctx, now_s=now_s)
        # 底盘反馈回填：velocity 是 contract.py 的只读 @property（由 speed_rpm 派生），
        # 给 property 赋值会 AttributeError；只需回填 speed_rpm。
        # 不回填的后果：task_state_bridge 用 velocity<0.01 判"停稳"，恒 0 = 永远判已停稳。
        self.ctx.chassis.speed_rpm = self.speed_rpm_fb
        self.ctx.extra.faults = faults
        for d in degraded:
            self.ctx.extra.note(d)

        if verdict == 'FAULT':
            self.ctx.state = State.ESTOP
            self.estop_since = now_s if self.estop_since is None else self.estop_since
            self._emit(0.0, STEER_CENTER, 'FAULT:' + ','.join(faults))
            return
        if self.ctx.state is State.ESTOP:
            if self.ctx.lane.track_valid and (now_s - (self.estop_since or now_s)) >= 1.0:
                self.ctx.state = State.TRACK
                self.estop_since = None
                self.line_lost_age = 0.0
            else:
                self._emit(0.0, STEER_CENTER, 'ESTOP_HOLD')
                return

        # ④ 事件确认（按子流 sequence）
        ex = self.ctx.extra
        zebra_on = self._confirm('zebra', self._zebra_cond(), ex.scene_seq, now_s)
        end_on = self._confirm('end', self._end_cond(), ex.scene_seq, now_s)
        branch_on = self._confirm('branch', self.ctx.events.junction, ex.lane_seq, now_s)

        # ⑤ 状态转移
        self.state_timer += dt
        self._transition(dt, zebra_on, end_on, branch_on, verdict == 'DEGRADE')

        # ⑥ 行为 + 仲裁 + ⑦ 输出
        cmd = self._run_behaviors(verdict == 'DEGRADE', dt)
        self._emit(float(cmd.speed or 0.0), int(cmd.steer), cmd.source)
        self.s += max(0.0, float(cmd.speed or 0.0)) * dt

    # ---------------------------------------------------------------
    def _confirm(self, key, cond, seq, now_s):
        """按**子流序号变化**计数：同一张图（sequence 不变）不重复计。

        为什么不用 tick 也不用 snapshot.sequence：
          tick 20Hz 而相机 8.5fps → 3 拍 ≈ 1.3 张图，"3 帧确认"实际只有 1 张图；
          snapshot.sequence 是聚合器的**发布**计数器（10Hz 定时自增），与画面无关。
          只有子流自己的 meta.sequence 与"是否换了一张图"一一对应（上游还专门
          挡了重复/乱序）。详见 00-M1改进建议.md 二.4。
        """
        st = self._db.setdefault(key, {'n': 0, 'seq': None, 't0': None, 'on': False})
        if cond:
            if st['seq'] != seq:          # 只有新数据才计一次
                st['n'] += 1
                st['seq'] = seq
                if st['t0'] is None:
                    st['t0'] = now_s
            st['on'] = st['n'] >= self.cfg.db_frames and \
                (now_s - (st['t0'] or now_s)) >= self.cfg.db_min_time
        else:
            st.update(n=0, seq=None, t0=None, on=False)
        return st['on']

    def _zebra_cond(self):
        y2 = self.ctx.extra.zebra_y2
        return y2 is not None and y2 >= self.cfg.zebra_trig_y2

    def _end_cond(self):
        """到达终点（修订 B）。

        三个条件同时成立：
          ① 当前帧红锥可见（red_finish_visible / confirmed）——不是"曾经锁存过"；
          ② 底边行 ≥ end_trig_y2（越近 y2 越大，单调，像素级阈值，不造米制）；
          ③ bbox 未知时退回事件确认（red_finish_confirmed），这是感知给的事件口径。
        为什么不能用锁存：任务一起点终点同位，发车瞬间就锁存 → 整轮恒真。
        """
        ex = self.ctx.extra
        if not ex.red_visible_now:
            return False
        if ex.end_y2 is None:
            return bool(self.ctx.events.end_seen)     # 无 bbox，只能用事件确认兜底
        return ex.end_y2 >= self.cfg.end_trig_y2

    # ---------------------------------------------------------------
    def _transition(self, dt, zebra_on, end_on, branch_on, degraded):
        s = self.ctx.state

        if s in (State.TRACK, State.JUNCTION):
            self.line_lost_age = 0.0 if self.ctx.lane.track_valid else self.line_lost_age + dt
        else:
            self.line_lost_age = 0.0

        if s is State.ESTOP:
            return

        if s is State.IDLE:
            if self.start_requested and self.ctx.lane.track_valid:
                self._enter(State.TRACK, f'start:{self.start_source}')
            return

        if s is State.TRACK:
            if self.line_lost_age > LINE_LOST_TIMEOUT:
                self._enter(State.ESTOP, 'line_lost_timeout')
                return
            if zebra_on:
                # 修订 D：冷却窗口内不重复计同一处斑马线（视野边界抖动会把一次过线
                # 计成多次，任务一就"过第一条斑马线即完成一圈"）。
                if (self.zebra_last_t is None
                        or self.now - self.zebra_last_t >= self.cfg.zebra_cooldown_s):
                    self.zebra_count += 1
                    self.zebra_last_t = self.now
                self._enter(State.SLOWDOWN)
                return
            # 障碍触发：雷达米制判据优先；雷达不用时走视觉锥桶像素行兜底。
            # 两路都要求 adapter 已确认 present，且来源口径明确，避免"不知道被当成有障碍"。
            ex = self.ctx.extra
            range_hit = (ex.obstacle_source != 'vision_cone'
                         and self.ctx.obstacle.present
                         and self.ctx.obstacle.dist < OBST_TRIG)
            vision_hit = (ex.obstacle_source == 'vision_cone'
                          and self.ctx.obstacle.present
                          and ex.vision_obstacle_y2 is not None
                          and ex.vision_obstacle_y2 >= self.cfg.vision_avoid_y2)
            if range_hit or vision_hit:
                # 修订 A：**不再**把 target_lane 改成 2。绕障后回归的是同一条主车道；
                # FIRST/SECOND 是车道身份（左/右），不是"避障前/后"。
                self.avoid_retry = 0
                self._enter(State.AVOID)
                return
            # 任务一 FINISH 门控：必须已过 ≥1 次斑马线事件（"完整绕行一圈"的事件证据），
            # 否则起步时起点红锥一旦满足行阈值就会立刻刹停（评分 2.1 起步/终点/停车全丢）。
            # 依据：任务书「完整绕行一圈后回到起点并停车」；评分 2.1「未完成一圈记 0 分」。
            if end_on and (self.task_id == TASK_STRAIGHT or self.zebra_count >= 1):
                self._enter(State.FINISH)
                return
            if branch_on:
                self._enter(State.JUNCTION)
            return

        if s is State.SLOWDOWN:
            # 退出判据：斑马线整体离开视野（车已驶过）+ 最短保持时间。
            # 只认 zebra_y2 is None，不用"> zebra_exit_y2"——依据评分 2.5「通过速度（4 分）：
            # 通过斑马线时车速明显低于接近时，且在斑马线内未明显恢复到接近速度」。
            # y2 刚超过行阈值时车头才到斑马线近缘，此时回 TRACK 恢复巡航 = 在斑马线内
            # 提速，直接丢 4 分。SLOWDOWN_TIMEOUT 兜底不变。
            gone = self.ctx.extra.zebra_y2 is None
            if (gone and self.state_timer >= self.cfg.zebra_min_time) \
                    or self.state_timer >= SLOWDOWN_TIMEOUT:
                self._enter(State.TRACK)
            return

        if s is State.AVOID:
            ex = self.ctx.extra
            if ex.obstacle_source == 'vision_cone':
                # 视觉兜底退出：障碍锥离开视野（本拍不再命中）即认为已绕过，
                # 或终点红锥已出现（避免把终点当障碍一直绕，直接让位给 FINISH）。
                cone_gone = (not self.ctx.obstacle.present)
                at_finish = bool(ex.red_visible_now)
                if cone_gone or at_finish:
                    self._enter(State.TRACK)
                    return
            else:
                clear = (not self.ctx.obstacle.present) \
                    or self.ctx.obstacle.dist > self.cfg.obst_clear_m
                if clear:
                    self._enter(State.TRACK)
                    return
            if self.state_timer > AVOID_TIMEOUT:
                self.avoid_retry += 1
                if self.avoid_retry > self.cfg.max_avoid_retry:
                    self._enter(State.ESTOP, 'avoid_retry_exhausted')
                else:
                    self.retry_stop = self.cfg.avoid_retry_stop_s
                    self._enter(State.TRACK, f'avoid_timeout_retry{self.avoid_retry}')
            return

        if s is State.JUNCTION:
            if not self.ctx.events.junction or self.state_timer > JUNCTION_TIMEOUT:
                self._enter(State.TRACK)
            return

        if s is State.FINISH:
            # 修订 C：任务一 = 过线事件 ≥1 且已到终点 → 一圈完成。
            # 这是**事件证据**，不是几何圈数（不用里程：弯道内外轮速差 + 打滑，
            # 一圈累计误差几十厘米，判成败是错的）。
            # 任务二（直道）没有"圈"，不置 lap_complete，完成由 control_mode=FINISHED 表达。
            if self.task_id == TASK_LAP and self.zebra_count >= 1:
                self.lap_complete = True

    def _enter(self, state, reason=''):
        if state is self.ctx.state:
            return
        self.log.append((round(self.s, 3), self.ctx.state.name, state.name, reason))
        self.ctx.state = state
        self.state_timer = 0.0

    # ---------------------------------------------------------------
    def _run_behaviors(self, degraded, dt):
        """按状态激活一个行为模块，然后双通道仲裁。M1 不产生控制律。"""
        s = self.ctx.state
        cands = {}

        fn, name = None, None
        if s in (State.TRACK, State.JUNCTION):
            fn, name = self.m2, 'TRACK'
        elif s is State.AVOID:
            fn, name = self.m3, 'AVOID'
        elif s is State.SLOWDOWN:
            fn, name = self.m4, 'SLOWDOWN'

        if fn is not None:
            try:
                steer, speed = fn(self.ctx)
            except Exception as exc:                      # 行为模块异常 → 当让位处理
                self.log.append((round(self.s, 3), s.name, 'BEHAVIOR_EXC', repr(exc)))
                steer, speed = None, None
            if steer is not None or speed is not None:
                cands[name] = Command(
                    steer=int(steer) if steer is not None else STEER_CENTER,
                    speed=float(speed) if speed is not None else None,
                    source=f'{name}',
                )

        # M1 自己的纵向上限/兜底（只降不升，且不改横向）
        cap = self._speed_cap(degraded)

        if s is State.FINISH:
            # 直接零速即「自主减速」：实测减速度 1.6~2.0 m/s²（AI_HANDOFF §1），
            # 0.385 m/s 刹停距离仅 4~5cm、总停车距离 0.10m，无需斜坡。
            # 停车精度（评分 2.1「停车区内停稳」/ 附加分 3.2 ±5cm）取决于 end_trig_y2
            # 标定（PLACEHOLDER，上车实测后定）。
            return Command(steer=self.last_cmd.steer, speed=0.0, source='FINISH_BRAKE')
        if s is State.ESTOP:
            return Command(steer=STEER_CENTER, speed=0.0, source='ESTOP')
        if s is State.IDLE:
            return Command(steer=STEER_CENTER, speed=0.0, source='IDLE')
        if self.retry_stop > 0:
            self.retry_stop -= dt
            return Command(steer=self.last_cmd.steer, speed=0.0,
                           source='AVOID_RETRY_STOP')

        lat = arbitrate({k: v for k, v in cands.items() if k in LAT_PRIORITY}, LAT_PRIORITY)
        lon = arbitrate({k: v for k, v in cands.items() if k in LON_PRIORITY}, LON_PRIORITY)

        speed = lon.speed
        if speed is not None and cap is not None:
            speed = min(speed, cap)
        if speed is None:                       # 零速铁律：没有赢家就不走
            return Command(steer=lat.steer, speed=0.0, source='NO_WINNER')
        return Command(steer=lat.steer, speed=speed,
                       source=f'lat:{lat.source}/lon:{lon.source}')

    def _speed_cap(self, degraded):
        s = self.ctx.state
        if not self.ctx.lane.track_valid:
            if self.line_lost_age < self.cfg.lost_hold_s:
                return V_SLOW                    # 短期丢线：不许超过慢速
            return 0.0                           # 等线
        if s is State.SLOWDOWN:
            return self.cfg.zebra_speed
        if degraded:
            return self.cfg.v_degrade
        return None

    def _emit(self, speed, steer, source):
        self.last_cmd = Command(steer=int(steer), speed=float(speed or 0.0),
                                source=source or self.ctx.state.name)
        return self.last_cmd

    # ---------------------------------------------------------------
    # TaskState（唯一口径：交给 TaskStatePublisher）
    # ---------------------------------------------------------------
    def publish_task_state(self, now_ns: int):
        """ROS 节点 timer 里调：10Hz 心跳 + 状态变化立即发。返回 None 表示这拍不发。

        now_ns 必须是车上 ROS 当前时间（node.get_clock().now().nanoseconds）——
        感知侧按 `now - header.stamp < 0.5s` 判新鲜，填 0 或离线时间会被整条拒收。
        """
        return self.pub_state.offer(self.ctx, now_ns,
                                    lap_complete=self.lap_complete)

    def task_state(self, now_ns: int | None = None) -> dict:
        """兼容旧调用：无条件构造一条（不节流）。"""
        if now_ns is None:
            now_ns = int(max(self.now, 0.001) * 1e9)
        return self.pub_state.build(self.ctx, now_ns, lap_complete=self.lap_complete)
