"""
task_state_bridge.py —— contract.py 的内部 State → 感知组 TaskState 对外发布

感知组要求规控发布 /team4s/control/task_state (TaskState)。
本文件负责把 contract.py 的 7 态内部状态机映射到 TaskState 的 10 态 phase 枚举，
并填充 task_id / target_lane / control_mode 等对外字段。

⚠ 上一版有三处**会被感知组直接拒收**的缺陷，本版修掉（依据 v2 包 §三 + 他们随包
  交付的 task_context_review.py 的校验逻辑）：

1. sequence 用模块级全局 `_seq` 自增。
   → 同一进程里两个 publisher、或重置后重启，序号会跳变/回退。感知侧
     task_context_review.ingest() 对同 session 的 `sequence <= 上一条` 直接抛
     duplicate_task_sequence 并**整条丢弃**。改成实例级、只在真正发出的消息上自增。
2. header.stamp 恒填 {sec:0, nanosec:0}，注释写"ROS 节点里用 now 填"但没人填。
   → 感知侧要求 `now_ns - capture < task_receive_timeout (0.5s)`，全零时间戳
     等于"这帧是 1970 年的"，永远 expired（task_capture_not_fresh），一条也进不去。
     改成 build(now_ns=...) 由调用方注入车上 ROS 时间，缺省时明确报错而不是填 0。
3. 只有一个"来一条算一条"的 build 函数，没有发布节流。
   → 规范要求"持续发布目标 10Hz，任务变化也及时发送"。20Hz tick 全发会让
     TaskState 变成 20Hz（超出对接目标、且 sequence 涨幅与感知预期不符）；
     不发又没有心跳，感知 0.5s 就判接收超时。
     新增 TaskStatePublisher.offer()：10Hz 心跳 + 状态变化立即发。

用法（ROS 节点内）：
    from task_state_bridge import TaskStatePublisher
    pub = TaskStatePublisher(task_id=1, target_lane=1)      # 进任务时构造，session 由它生成
    ...
    def tick():
        msg = pub.offer(ctx, now_ns=self.now_ns(), lap_complete=m1.lap_complete,
                        reason=m1.reason_text())
        if msg is not None:
            self.pub.publish(TaskState(**msg))              # 或 _fill_msg(msg, m)
"""

from __future__ import annotations   # Py3.8 兼容（Foxy 容器 Py3.8）

import os
import time

from contract import State, Ctx, BASE_FRAME, TASK_STATE_PERIOD_S

# =====================================================================
# TaskState 枚举常量（对应 team4s_interfaces/msg/TaskState）
# =====================================================================
# task_id
TASK_NONE = 0
TASK_LAP = 1       # 任务一：单圈循迹
TASK_STRAIGHT = 2  # 任务二：直道行驶

# phase
PHASE_IDLE = 0
PHASE_WAIT_START = 1
PHASE_FOLLOW_LAP = 2
PHASE_FOLLOW_FIRST = 3
PHASE_AVOIDING = 4
PHASE_FOLLOW_SECOND = 5
PHASE_ZEBRA_SLOW = 6
PHASE_FINISH_APPROACH = 7
PHASE_STOPPED = 8
PHASE_FAULT = 9

# target_lane
LANE_UNKNOWN = 0
LANE_FIRST = 1
LANE_SECOND = 2

# control_mode
MODE_IDLE = 0
MODE_AUTO = 1
MODE_MANUAL = 2
MODE_PAUSED = 3
MODE_FINISHED = 4
MODE_FAULT = 5

# cone_state（用于判断出发条件，与 adapter_v2 一致）
CONE_REMOVED = 3

PHASE_NAMES = {0: 'IDLE', 1: 'WAIT_START', 2: 'FOLLOW_LAP', 3: 'FOLLOW_FIRST',
               4: 'AVOIDING', 5: 'FOLLOW_SECOND', 6: 'ZEBRA_SLOW',
               7: 'FINISH_APPROACH', 8: 'STOPPED', 9: 'FAULT'}
MODE_NAMES = {0: 'IDLE', 1: 'AUTO', 2: 'MANUAL', 3: 'PAUSED', 4: 'FINISHED', 5: 'FAULT'}
LANE_NAMES = {0: 'UNKNOWN', 1: 'FIRST', 2: 'SECOND'}


# =====================================================================
# 内部 State → 对外 phase 映射
# =====================================================================
def state_to_phase(state: State, task_id: int, target_lane: int,
                   cone_state: int = -1, speed: float = 0.0) -> int:
    """
    把 contract.py 的 7 态内部状态映射到 TaskState 的 10 态 phase。

    映射规则：
      IDLE + 锥桶已移开 → PHASE_WAIT_START（锥桶已清，等待遥控启动指令）
      IDLE + 锥桶未移开 → PHASE_IDLE（锥桶还在，不具备起步条件）
      TRACK + task=1     → PHASE_FOLLOW_LAP（单圈循迹）
      TRACK + task=2 + lane=FIRST  → PHASE_FOLLOW_FIRST（主路左车道）
      TRACK + task=2 + lane=SECOND → PHASE_FOLLOW_SECOND（主路右车道）
      SLOWDOWN            → PHASE_ZEBRA_SLOW
      AVOID               → PHASE_AVOIDING
      JUNCTION            → 归入当前 TRACK 的对应子态（FOLLOW_LAP/FIRST/SECOND）
      FINISH + 速度>0     → PHASE_FINISH_APPROACH
      FINISH + 速度≈0     → PHASE_STOPPED
      ESTOP               → PHASE_FAULT

    ⚠ 20261116 坐标修订版对 target_lane 语义的更正（影响本函数的分支）：
       v2 明确 FIRST = 沿任务行驶方向的主路**左车道**，SECOND = 主路**右车道**，
       是**车道身份**，不是"避障前/避障后"的阶段编号，也不是图像候选数组下标。
       所以 FOLLOW_FIRST/FOLLOW_SECOND 只由 target_lane 决定，与是否绕过障无关；
       避障绕行后回归的是**同一条**主车道，target_lane 不变。
    """
    if state is State.ESTOP:
        return PHASE_FAULT

    if state is State.IDLE:
        if cone_state == CONE_REMOVED:
            return PHASE_WAIT_START  # 锥桶已移开，等遥控启动
        return PHASE_IDLE

    if state is State.SLOWDOWN:
        return PHASE_ZEBRA_SLOW

    if state is State.AVOID:
        return PHASE_AVOIDING

    if state is State.JUNCTION:
        # JUNCTION 归入当前任务+车道的循迹态（phase 枚举里没有 JUNCTION）
        if task_id == TASK_LAP:
            return PHASE_FOLLOW_LAP
        return PHASE_FOLLOW_SECOND if target_lane == LANE_SECOND else PHASE_FOLLOW_FIRST

    if state is State.FINISH:
        if abs(speed) < 0.01:
            return PHASE_STOPPED
        return PHASE_FINISH_APPROACH

    if state is State.TRACK:
        if task_id == TASK_LAP:
            return PHASE_FOLLOW_LAP
        return PHASE_FOLLOW_SECOND if target_lane == LANE_SECOND else PHASE_FOLLOW_FIRST

    return PHASE_IDLE  # 兜底


def state_to_mode(state: State, stopped: bool, lap_complete: bool = False,
                  manual_override: bool = False) -> int:
    """control_mode = 「此刻是否允许自动运动」。

    IDLE 一律 MODE_IDLE（含"锥桶已移开、等遥控启动"的 WAIT_START）——
    评分 2.1 要求自主起步以"接到允许的遥控启动指令"为前提，锥桶一移开就报
    MODE_AUTO 会让感知以为车该动了。
    FINISH 且已停稳 → MODE_FINISHED（无论任务一/二，也不依赖 lap_complete：
    "任务完成"和"这一圈是否算数"是两件事，前者由 control_mode 表达）。
    """
    if state is State.ESTOP:
        return MODE_FAULT
    if manual_override:
        return MODE_MANUAL
    if state is State.IDLE:
        return MODE_IDLE
    if state is State.FINISH and stopped:
        return MODE_FINISHED
    return MODE_AUTO


# =====================================================================
# run_id / controller_session_id 生成规则
# =====================================================================
def generate_run_id(task_id: int, attempt: int = 1, stamp: str | None = None) -> str:
    """
    run_id：**每轮任务生成新一个**（感知组按它做事件去重、数据对齐）。

    格式: t{task_id}_a{attempt}_{YYYYmmdd_HHMMSS}
    示例: t1_a1_20261116_201530

    上一版返回 "t1_a1"，注释说"ROS 节点里用 clock 填 timestamp"但没人填 ——
    结果是同一台车两天跑同一任务，run_id 一模一样，感知侧按 run_id 去重会把
    第二天的斑马线事件当成第一天的重复事件吞掉。这里把时间戳真正拼进去。
    """
    if stamp is None:
        stamp = time.strftime('%Y%m%d_%H%M%S', time.localtime())
    return f"t{int(task_id)}_a{int(attempt)}_{stamp}"


def generate_controller_session_id() -> str:
    """
    controller_session_id：**进程启动时生成一次，存活期间不变**。

    格式: ctrl_{pid}_{monotonic_ns 末 6 位}
    为什么要加 monotonic_ns：pid 会被操作系统复用。只用 pid 的话，"进程崩了重启"
    很可能拿到同一个 pid → session 不变 → 感知侧 retired 集合认不出这是新会话，
    反而按"同 session 但 sequence 回退"把消息当重复丢掉（duplicate_task_sequence）。
    """
    return f"ctrl_{os.getpid()}_{time.monotonic_ns() % 1000000:06d}"


# =====================================================================
# 发布器：10Hz 心跳 + 状态变化立即发
# =====================================================================
class TaskStatePublisher:
    """一个任务一个实例。进程启动生成 session，任务切换生成新 run。

    感知侧接收端（随包 task_context_review.py）会对以下情况**整条拒收**，
    本类逐条对齐：
      · run_id / controller_session_id 为空          → 构造时就保证非空
      · task_id ∈ {1,2}、target_lane ∈ {0,1,2}       → 构造与 set_target_lane 校验
      · phase ∈ 0..9、control_mode ∈ 0..5            → 枚举常量限定
      · 采集时间不新鲜（>0.5s）                      → offer() 必须传 now_ns
      · 同 session sequence 不严格递增               → 每次真正发出才 +1
      · 旧 controller_session 复活                    → session 只在 __init__ 生成
    """

    def __init__(self, task_id: int = TASK_LAP, target_lane: int = LANE_FIRST,
                 run_id: str | None = None, attempt: int = 1,
                 period_s: float = TASK_STATE_PERIOD_S,
                 controller_session_id: str | None = None):
        if task_id not in (TASK_LAP, TASK_STRAIGHT):
            raise ValueError('task_id must be TASK_LAP(1) or TASK_STRAIGHT(2)')
        if target_lane not in (LANE_UNKNOWN, LANE_FIRST, LANE_SECOND):
            raise ValueError('target_lane must be 0/1/2')
        self.task_id = int(task_id)
        self.target_lane = int(target_lane)
        self.run_id = run_id or generate_run_id(self.task_id, attempt)
        self.controller_session_id = controller_session_id or generate_controller_session_id()
        self.period_ns = int(max(0.0, float(period_s)) * 1e9)
        self.sequence = 0
        self.last_emit_ns = None
        self.last_sig = None
        self.last_error = ''

    # ------------------------------------------------------------------
    def new_run(self, run_id: str | None = None, task_id: int | None = None,
                target_lane: int | None = None, attempt: int = 1):
        """开新一轮任务：换 run_id（sequence 继续递增，session 不变）。"""
        if task_id is not None:
            if task_id not in (TASK_LAP, TASK_STRAIGHT):
                raise ValueError('task_id must be 1 or 2')
            self.task_id = int(task_id)
        if target_lane is not None:
            if target_lane not in (LANE_UNKNOWN, LANE_FIRST, LANE_SECOND):
                raise ValueError('target_lane must be 0/1/2')
            self.target_lane = int(target_lane)
        self.run_id = run_id or generate_run_id(self.task_id, attempt)
        self.last_sig = None      # 强制下一拍立即发
        return self.run_id

    def set_target_lane(self, lane: int):
        """切目标车道。感知侧要求"目标切换需要新消息"——这里只改字段，
        下一次 offer() 因 sig 变化会**立即**发一条，不会等到 10Hz 心跳。"""
        if lane not in (LANE_UNKNOWN, LANE_FIRST, LANE_SECOND):
            raise ValueError('target_lane must be 0/1/2')
        self.target_lane = int(lane)
        self.last_sig = None

    # ------------------------------------------------------------------
    def build(self, ctx: Ctx, now_ns: int, lap_complete: bool = False,
              manual_override: bool = False, reason: str = '') -> dict:
        """无条件构造一条 TaskState（并消耗一个 sequence）。"""
        if now_ns is None or int(now_ns) <= 0:
            # 明确报错，不再静默填 0 —— 填 0 会被感知判 task_capture_not_fresh
            raise ValueError('now_ns (车上 ROS 时间) is required for TaskState.header.stamp')

        cone_state = getattr(ctx.events, 'cone_state', -1)
        stopped = abs(float(getattr(ctx.chassis, 'velocity', 0.0) or 0.0)) < 0.01
        phase = state_to_phase(ctx.state, self.task_id, self.target_lane,
                               cone_state, float(getattr(ctx.chassis, 'velocity', 0.0)))
        mode = state_to_mode(ctx.state, stopped, lap_complete, manual_override)

        self.sequence += 1
        ns = int(now_ns)
        return {
            'header': {
                'stamp': {'sec': ns // 1000000000, 'nanosec': ns % 1000000000},
                'frame_id': BASE_FRAME,
            },
            'run_id': self.run_id,
            'controller_session_id': self.controller_session_id,
            'sequence': self.sequence,
            'task_id': self.task_id,
            'phase': phase,
            'target_lane': self.target_lane,
            'control_mode': mode,
            'lap_complete': bool(lap_complete),
            'reason': self._reason(ctx, phase, mode, reason),
        }

    # ------------------------------------------------------------------
    def offer(self, ctx: Ctx, now_ns: int, lap_complete: bool = False,
              manual_override: bool = False, reason: str = '') -> dict | None:
        """按 10Hz 节流；状态或任务参数变化时立即发。返回 None 表示这一拍不发。"""
        now_ns = int(now_ns)
        cone_state = getattr(ctx.events, 'cone_state', -1)
        stopped = abs(float(getattr(ctx.chassis, 'velocity', 0.0) or 0.0)) < 0.01
        phase = state_to_phase(ctx.state, self.task_id, self.target_lane,
                               cone_state, float(getattr(ctx.chassis, 'velocity', 0.0)))
        mode = state_to_mode(ctx.state, stopped, lap_complete, manual_override)
        sig = (self.task_id, self.target_lane, phase, mode, bool(lap_complete))

        due = (self.last_emit_ns is None) or (now_ns - self.last_emit_ns >= self.period_ns)
        changed = (sig != self.last_sig)
        if not (due or changed):
            return None

        msg = self.build(ctx, now_ns, lap_complete, manual_override, reason)
        self.last_emit_ns = now_ns
        self.last_sig = sig
        return msg

    # ------------------------------------------------------------------
    def _reason(self, ctx, phase, mode, extra_reason='') -> str:
        """reason 填"当前状态或失效原因"（§三）。拼接顺序：阶段 → 降级 → 故障 → 备注。"""
        parts = [PHASE_NAMES.get(phase, str(phase)), MODE_NAMES.get(mode, str(mode))]
        parts.append('lane=' + LANE_NAMES.get(self.target_lane, '?'))
        ex = getattr(ctx, 'extra', None)
        note = getattr(ex, 'lane_note', '') if ex else ''
        if note:
            parts.append('lane:' + str(note)[:40])
        deg = getattr(ex, 'degraded', None) if ex else None
        if deg:
            parts.append('deg:' + ','.join(str(d) for d in deg[:4])[:60])
        faults = getattr(ex, 'faults', None) if ex else None
        if faults:
            parts.append('fault:' + ','.join(str(f) for f in faults[:3])[:50])
        if extra_reason:
            parts.append(str(extra_reason)[:40])
        return '|'.join(parts)[:180]


# =====================================================================
# 兼容旧调用的薄封装（全局单例；新代码请直接用 TaskStatePublisher）
# =====================================================================
_DEFAULT = None


def build_task_state(ctx: Ctx, task_id: int, target_lane: int,
                     run_id: str, controller_session_id: str,
                     lap_complete: bool = False,
                     manual_override: bool = False,
                     reason: str = "",
                     now_ns: int | None = None) -> dict:
    """保留旧签名（脚本/旧测试在用）。**不节流**，每次调用都产出一条并自增 seq。

    now_ns 缺省时会用 time.time_ns() 兜底并写进 reason，方便一眼看出这条是
    "离线造的"而不是车上真实时间——但正式发布路径必须显式传车上 ROS 时间。
    """
    global _DEFAULT
    if _DEFAULT is None or _DEFAULT.controller_session_id != controller_session_id:
        _DEFAULT = TaskStatePublisher(task_id, target_lane, run_id=run_id,
                                      controller_session_id=controller_session_id)
    _DEFAULT.task_id = int(task_id)
    _DEFAULT.target_lane = int(target_lane)
    _DEFAULT.run_id = run_id
    if now_ns is None:
        now_ns = time.time_ns()
        reason = (reason + '|offline_time' if reason else 'offline_time')
    return _DEFAULT.build(ctx, now_ns, lap_complete, manual_override, reason)


def _fill_msg(msg, data: dict):
    """把 build() 的 dict 灌进 ROS 消息对象（不 import rclpy，鸭子类型）。"""
    for k, v in data.items():
        if k == 'header':
            msg.header.frame_id = v.get('frame_id', '')
            st = v.get('stamp', {})
            msg.header.stamp.sec = int(st.get('sec', 0))
            msg.header.stamp.nanosec = int(st.get('nanosec', 0))
        else:
            setattr(msg, k, v)
    return msg


# =====================================================================
# 反向：从 TaskState 推断是否允许运动
# =====================================================================
def is_motion_allowed(task_state: dict) -> bool:
    """感知模块或其他订阅方判断当前是否允许自动运动。"""
    mode = task_state.get('control_mode', MODE_IDLE)
    return mode == MODE_AUTO
