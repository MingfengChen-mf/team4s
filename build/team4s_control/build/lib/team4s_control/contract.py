"""
contract.py —— 智能小车规控系统消息契约 v1.0（机器可读版）
内容必须与 contract_v1.md 保持一致；改动契约需全员同意，两处同步改。

用法（不依赖 ROS，纯逻辑层可 import）：
    from contract import State, Ctx, Command, LAT_PRIORITY, LON_PRIORITY, ...
"""

from __future__ import annotations   # Py3.8 兼容：float | None / dict[str, ...] 等仅作字符串注解（Foxy 容器 Py3.8）

from dataclasses import dataclass, field
from enum import Enum, auto
import math

# =====================================================================
# 常量
# 逐项出处与可信度见 contract常量溯源.md（v2）。
# 权威优先级：车上源码 20251106V1 > 20261113 实车实测 > 场地参数推导 v2.0 > 早期通用脚本。
# =====================================================================
R_EFF = 0.032          # 有效滚动半径 m（几何 0.0325 不可用；实测反推约 0.0415，待复测）
GEAR_RATIO = 6.287     # 传动比（车上脚本，实测）
RPM2VEL = 2 * math.pi * R_EFF / (60 * GEAR_RATIO)   # ≈ 0.000533 m/s per rpm

DUTY_MAX, DUTY_MIN = 0.10, 0.0     # 占空比限幅（发布层语义）
# 修正（20261116）：0.2 → 0.10。依据 AI_HANDOFF_20261116 §1 actuator.duty_max_safe=0.10
# 及 §9 禁止事项 3：「|duty| ≤ 0.10，越界值底盘会忽略整帧，沿用上一帧速度继续跑」。
# 原上限 0.2 意味着任何映射越界帧都会被底盘丢弃——刹车指令失效属安全缺陷。
# 注：DUTY_MIN 刻意保持 0.0（可以倒车到 -0.2，但本任务不需要），卡死在 0 可保证
#     任何符号/换算错误都不会让车后退。要放开需全组同意。
# ⚠ 停车必须写**浮点 0.0**，禁止整数 0（AI_HANDOFF §9 禁止事项 2：整数会被底盘
#   当转速抬到 900 rpm）。本文件所有停车速度常量均为 0.0 浮点，发布层不得 cast 成 int。
RPM_MAX, RPM_MIN = 2500, 900       # 转速限幅（实测 2500；<900 会被底盘夹到 900）
STEER_MAX, STEER_MIN = 2200, 800   # 舵机限幅
STEER_CENTER = 1500                # 舵机中位（实测定标：指令 1500 → 反馈 1462）

# --- 舵机方向（20261113 实测定标，全项目以此为准，别在别处再猜）---
# 指令 1900 = 往车身右侧打，1100 = 往左侧打，即 **PWM 增大 → 车往右**。
# 推论：车偏右（track_err > 0，正值=偏右）要往左修正 → PWM 必须 **减小**。
#   正确： steer = STEER_CENTER - K * track_err     （K > 0）
#   错误： steer = STEER_CENTER + K * track_err     （正反馈，越调越偏）
STEER_RIGHT_PWM = 1900
STEER_LEFT_PWM = 1100

# --- 坐标与时效基准（20261116 感知 v2 坐标修订版）---
# base_link 的原点定义已由感知组改为「九点标定使用的车头正中地面投影」，X 向车头正前方、
# Y 向车左、Z 向上，单位米，**随车运动**（不是固定在赛道上的世界原点）。
# 出处：v2 包 01-正式接入规范.txt §四 + 坐标原点约定.json。
# 由此产生两条硬约束，M1 必须遵守：
#   ① offset_m 是**前方参考点**（metric_reference_x_m ≈ 0.5~1.0 m）处的横向偏差，
#      不是后轴处横向误差。M1 只透传，谁要用后轴坐标谁自己显式换算。
#   ② 若感知给的 metric_frame_id 不是 base_link，则那是别的原点，M1 不得当同一量用。
BASE_FRAME = 'base_link'

# 时效参数出处：v2 包 initial_static_review.json 统一规定"首次静止联调"
# 采集年龄与接收超时均为 0.5 s、task_state 接收超时 0.5 s。
# ⚠ 该文件同时声明：这是初始静止联调参数，尚未按行驶速度/制动距离/最坏延迟验证，
#   不得据此宣称自动行驶条件通过。行驶配置须在延迟与制动验证后另存明确版本。
PERCEPTION_MAX_AGE_S = 0.5     # 子流采集年龄上限 s（静止联调值）
TASK_STATE_PERIOD_S = 0.1      # TaskState 发布周期 s（规范 §三：持续发布目标 10Hz）

NO_DETECTION = 99.0                # "未检出"统一取值
STALE_TIMEOUT = 0.5                # 消息过期判据 s
LINE_LOST_TIMEOUT = 0.5            # 循迹丢线判据 s（AVOID 中抑制）
AVOID_TIMEOUT = 8.0                # AVOID 兜底超时 s
JUNCTION_TIMEOUT = 3.0
SLOWDOWN_TIMEOUT = 5.0

# ⚠ 以下三个米制触发距离自 v2 起**不再参与状态转移**。原因有两个，都可复现：
#   ① 感知组不提供米制距离（zebra_dist / 终点的"距离"字段根本不存在于 v2 消息里）；
#   ② 旧版 bbox→距离 函数在可见像面能返回的最小值是 1.04 m，ZEBRA_TRIG=0.25 永远不可达
#      （00-M1改进建议.md 三①）。v2 改用 bbox 底边像素行做单调阈值（NodeCfg.*_y2）。
# 保留常量仅供旧脚本/pytest 引用，新代码不要再用它们判转移。
ZEBRA_TRIG = 0.25      # [已弃用于转移判定] 斑马线前减速触发距离 m
ZEBRA_EXIT = 1.5       # [已弃用于转移判定] 减速退出距离 m
OBST_TRIG = 1.2        # 避障触发距离 m（= 变道起点 1.80m 的提前量）；此项**仍在使用**，
                       # 因为障碍距离来自 RangeReading.distance_m 的真实米值，不是推算
START_TRIG = 1.0       # 绿锥启动距离 m（未使用：感知不提供锥桶距离）
END_TRIG = 0.5         # [已弃用于转移判定] 终点标记判定距离 m
# --- 速度：单位统一为 m/s（20261116 修正：换用满电三档实测标定）---
# 这里是**车速**，不是占空比。下发底盘前必须过 speed_to_duty()，行为模块不要自己算。
# 依据 AI_HANDOFF_20261116 §1 calibration（满电）：duty 0.06/0.08/0.10 → 0.186/0.385/0.604 m/s。
# 旧值（20261113 单点：duty 0.08 → 0.33）保留在行尾备查；满电标定待重复实验复测后敲定。
V_CRUISE = 0.385       # 巡航（20261116 满电实测 duty 0.08；旧值 0.33）
V_SLOW   = 0.25        # 减速目标，约巡航的 65%（降幅 35%；HANDOFF §10 T2 验收要求降幅≥30%）
V_AVOID  = 0.29        # 避障，维持原比例约巡航的 76%（旧 0.25/0.33）
BRAKE_TRIG = 0.10      # 终点前开始制动距离 m（HANDOFF §1：0.385m/s 总停车距离实测 0.10m；
                       # 旧值 0.19 按旧减速度 0.40m/s² 外推，会让车提前停 8~9cm，
                       # 过不了 ±5cm —— HANDOFF §0 结论二。实测制动距离 0.044m @duty 0.08）
E_LAT_LIMIT = 0.06     # 半车道余量 m（车宽 18cm、单车道 30cm：(30-18)/2 = 6cm）
BRANCH_REJECT_DEG = 25.0   # 支线拒绝角 |Δψ| 阈值（P1 用）

# ⚠ 20261116：该窗口以 zebra_dist（米制）为轴，而 v2 感知不提供该距离，
# adapter 恒填 NO_DETECTION=99.0，窗口永不命中。want_junction 已改为只认
# LaneCandidate.is_branch。此常量仅存档，勿再用于判转移。
JUNCTION_WINDOW = (-0.3, 1.0)   # [已弃用] JUNCTION 位置窗口


# =====================================================================
# 速度换算：m/s ↔ 占空比
# 20261116 满电三档实测标定（AI_HANDOFF_20261116 §1）：v = (duty - 0.041) * 10.5，
#   duty 0.06 / 0.08 / 0.10 → 0.186 / 0.385 / 0.604 m/s，三档行程与尺量吻合（±8%）。
#   反解：duty = 0.041 + v / 10.5。旧模型（死区 0.05、斜率按 0.08→0.33 单点外推）
#   已被三档数据取代，待重复实验复测后敲定。
# 为什么需要它：V_CRUISE 是 m/s，而底盘收 duty（0~0.10）。若把车速当 duty 下发，
#   越界帧会被底盘整帧忽略、沿用上一帧速度（HANDOFF §9 禁止事项 3）。
# =====================================================================
DUTY_DEADBAND = 0.041               # 满电实测死区（HANDOFF §1 duty_deadzone_measured_full_battery）
DUTY_PER_MS = 1.0 / 10.5            # ≈ 0.0952 duty per (m/s)，由标定模型 v=(duty-0.041)*10.5 反解


def speed_to_duty(v_ms):
    """车速 m/s → 底盘占空比。M1 发布 /cmd_speed 前调用；行为模块不要自己换算。

    发布层两条铁律（依据 AI_HANDOFF_20261116 §9 禁止事项 2/3）：
      ① 停车必须写浮点 0.0 —— 整数 0 会被底盘当转速抬到 900 rpm；
      ② 映射结果必须 |duty| ≤ 0.10 —— 越界整帧被忽略，车沿用上一帧速度继续跑。
    本函数返回值恒为浮点且已限幅到 [0.0, 0.10]，直接下发即可；勿在外层 cast int。
    """
    if v_ms is None or v_ms <= 0.0:
        return DUTY_MIN
    d = DUTY_DEADBAND + float(v_ms) * DUTY_PER_MS
    return max(DUTY_MIN, min(DUTY_MAX, d))


def duty_to_speed(duty):
    """占空比 → 车速 m/s。仅用于日志与自检（反算验证）。"""
    if duty is None or duty <= DUTY_DEADBAND:
        return 0.0
    return (float(duty) - DUTY_DEADBAND) / DUTY_PER_MS


# =====================================================================
# 状态机
# =====================================================================
class State(Enum):
    IDLE = auto()
    TRACK = auto()
    SLOWDOWN = auto()
    AVOID = auto()
    JUNCTION = auto()
    FINISH = auto()
    ESTOP = auto()


# =====================================================================
# 消息结构（与契约第 1 节逐字段对应；header.stamp 由 ROS 层注入）
# ---------------------------------------------------------------------
# ⚠ 本文件是**进程内数据结构**，不是对外接口。跟感知组共享的只有
#   team4s_interfaces 那 10 个 .msg；这里的类可以随便改，改了不影响互通。
#   但每个字段必须能回答"它从哪来"。四类来源（逐字段台账见 contract字段台账.md）：
#     ① 直译  —— 消息字段 1:1 改名（如 heading_rad ← LaneCandidate.heading_rad）
#     ② 换算  —— 消息字段 + 固定公式（如 track_err = offset_m × 100）
#     ③ 派生  —— 感知不给，规控用消息字段自己判（如 track_valid、junction）
#     ④ 占位  —— **没有来源**，v1 遗留。标 ⛔，禁止新代码消费。
#   标记 ⛔ 的字段留着只是不破坏旧脚本引用，不要读它们。
# =====================================================================
@dataclass
class LaneError:                    # 车道信息（adapter 从感知组 LaneObservation 填充）
    # --- contract_v1 原始字段（稳定，行为模块主要读这些）---
    track_err: float = 0.0          # cm，正=偏右，相对当前车道中心（② 来源见 unit）
    curvature: float = 0.0          # ⛔ ④ 无来源：感知组 v2 不提供曲率。
                                    #    恒 0，**不可当前馈用**。要算必须先有米值：
                                    #    在米域拟合多项式取 C2（单位 1/m），像素域的
                                    #    "图像曲率"差一个随距离变的透视因子，不能替代。
    track_valid: bool = False       # 丢线时保持最后有效值，不得清零

    # --- adapter 附加字段（来自感知组 LaneCandidate，非 contract_v1 原始定义）---
    heading_rad: float | None = None  # 车道方向角 rad（Stanley 方法用，adapter 从 heading_rad 存）
    is_branch: bool = False           # 当前候选是否为支线分叉（adapter 从 is_branch 存）
    route_lane: int = 0               # 当前候选所属车道编号 1=FIRST 2=SECOND（adapter 从 route_lane 存）

    # --- 20261116 新增：米制口径透传（只标注，不换算）---
    # 加这三个字段的理由：v2 修订版把 base_link 改到车头地面投影后，track_err 的
    # **物理含义和单位口径都变了**。M2 若仍按"cm、后轴误差"理解会直接把增益调错。
    # 字段全部是感知组消息里的原值，M1 不做任何运算：
    unit: str = 'cm'                  # 'cm'（感知批准米值）| 'px'（米制未批准，透传像素）
    ref_x_m: float | None = None      # 该横向偏差对应的**前方参考点**前向距离 m
                                      # （LaneObservation.metric_reference_x_m）
                                      # M2 做 Stanley / 前视补偿时必须知道这一点：
                                      # 0.5 m 处的偏差和 1.0 m 处的偏差不能套同一条增益
    calib_id: str = ''                # 标定版本号（LaneObservation.calibration_id），
                                      # 用于赛后对账：这一轮的成绩是哪版标定跑出来的


@dataclass
class EventFlags:                   # 场景事件（adapter 从感知组 SceneObservation 填充）
    # --- contract_v1 原始字段（稳定，M1 状态转移条件读这些）---
    start_seen: bool = False        # ③ 派生：cone_state==REMOVED 且本轮曾见绿锥（锁存）
    start_dist: float = NO_DETECTION   # ⛔ ④ 无来源：v2 消息里没有锥桶距离字段。
                                       #    恒 99.0，禁止消费；起步判据只看 start_seen。
    end_seen: bool = False          # ③ 派生：red_finish_confirmed 锁存 = "本轮曾确认过终点"。
                                    #    ⚠ 只作记忆/日志；**FINISH 判据用 extra.red_visible_now**
                                    #    （当前帧可见性），否则任务一起步就把起点红锥当终点。
    end_dist: float = NO_DETECTION  # ⛔ ④ 无来源：v2 没有终点距离字段。恒 99.0，禁止消费。
                                    #    终点判据 = 红锥 bbox 底边行阈值（NodeCfg.end_trig_y2）。
    zebra_dist: float = NO_DETECTION   # ⛔ ④ 无来源：v2 没有斑马线距离字段。恒 99.0，禁止消费。
                                       #    斑马线判据 = bbox 底边行阈值（NodeCfg.zebra_trig_y2）。
    junction: bool = False          # ③ 派生：lane.is_branch && lane.track_valid

    # --- adapter 附加字段（来自感知组 SceneObservation，非 contract_v1 原始定义）---
    cone_state: int = 0             # ① 直译：锥桶4态 0=UNKNOWN 1=PRESENT 2=LEAVING 3=REMOVED
    cone_valid: bool = False        # ① 直译：锥桶检测是否有效
    zebra_visible: bool = False     # ① 直译：斑马线是否在画面中（受 zebra_valid 门控）
    zebra_confirmed: bool = False   # ① 直译：斑马线事件是否已确认（事件去重用）
    zebra_event_id: int = 0         # ① 直译：斑马线事件 ID（与 run/session 组三元组去重）
    end_detection_unresolved: bool = False  # ⛔ ④ 空壳：从未被赋值。终点方案已定（红锥事件
                                            #    + 像素行阈值），此字段可以删。


@dataclass
class ObstacleInfo:                 # 障碍信息（adapter 从感知组 ObstacleObservation 填充）
    # --- contract_v1 原始字段（稳定，M3 避障主要读这些）---
    dist: float = NO_DETECTION      # ② 换算：逐条过滤后中位数聚合；未检出=99.0
                                    #    必须同时看 ctx.extra.ranging_state=='ok' 才可信
    angle: float = 0.0              # ② 换算：bearing_rad×180/π，正=偏右；bearing_known=false 时为 0
    width: float = 0.0              # ⛔ ④ 无来源：感知组不提供障碍宽度。恒 0，禁止消费
                                    #    （M3 判断"能不能绕过"只能靠 left/right_clear + 重新勘测）
    present: bool = False           # ③ 派生：至少一条读数通过过滤 + 3 帧内 2 次一致

    # --- adapter 附加字段（来自感知组 ObstacleObservation，非 contract_v1 原始定义）---
    left_clear_known: bool = False  # ① 直译：左侧空间是否被真正检查过
    left_clear: bool | None = None  # ① 直译：左侧能否通行。None = **不知道**（不是"能走"）
    right_clear_known: bool = False # ① 直译：右侧空间是否被真正检查过
    right_clear: bool | None = None # ① 直译：右侧能否通行。None = **不知道**
    readings: list = field(default_factory=list)  # ① 直译：原始 RangeReading[]（M3 细节分析用）


@dataclass
class ChassisFeedback:              # /chassis_feedback
    speed_rpm: int = 0              # 电机转速（原始回传值，别再二次换算一遍）

    @property
    def velocity(self) -> float:
        """车速 m/s。**只准用于日志和"是否停稳"判断**（abs(v) < 0.01）。

        禁止用于：里程积分、停车距离、圈数判定。两个理由——
        ① `R_EFF` 未验收：现值 0.032，实测 478rpm ↔ 0.33m/s 反推约 0.0415；
        ② 更致命的是 rpm 本身会漂：CALIB_20261113 3.3 记录同一条指令下
           转速从 478 掉到 300（电压电流都正常），积分误差能到 20% 以上。
        """
        return self.speed_rpm * RPM2VEL


@dataclass
class Ctx:                          # M1 每拍填好，行为模块只读
    state: State = State.IDLE
    lane: LaneError = field(default_factory=LaneError)
    events: EventFlags = field(default_factory=EventFlags)
    obstacle: ObstacleInfo = field(default_factory=ObstacleInfo)
    chassis: ChassisFeedback = field(default_factory=ChassisFeedback)
    # adapter_v2.Extra：数据溯源与降级明细（run_id/子流序号/单位/拒绝原因/健康）。
    # 原来 adapter 直接 `ctx.extra = Extra()` 动态挂属性，dataclass 上没有这个字段，
    # 任何 `dataclasses.asdict()` / 序列化 / 拷贝都会把它丢掉（答辩录日志时会踩到）。
    # 这里正式声明：行为模块**可以读**（例如判断 ranging_state 是否可信），但不得写。
    extra: object = None


@dataclass
class Command:
    """仲裁输出 / 行为提案。speed=None 表示该通道无人接管（→ 零速铁律）。

    speed 单位统一为 **m/s**（与 V_CRUISE / V_SLOW 同一口径）。
    M1 下发底盘前调 speed_to_duty() 转占空比；行为模块返回 m/s 即可，不要自己转。
    """
    steer: int = STEER_CENTER
    speed: float | None = 0.0       # m/s；None = 无赢家 → 0.0
    source: str = "none"


# =====================================================================
# 双通道仲裁（契约第 4 节）
# =====================================================================
LAT_PRIORITY = {"ESTOP": 99, "AVOID": 50, "JUNCTION": 30, "TRACK": 10}
LON_PRIORITY = {"ESTOP": 99, "FINISH": 50, "SLOWDOWN": 30, "TRACK": 10, "AVOID": 10}

def arbitrate(candidates: dict[str, Command], table: dict[str, int]) -> Command:
    """candidates: {行为名: Command}，按 table 优先级取赢家。
    铁律：无赢家/全 None → 零速，不沿用上一拍。"""
    valid = {k: c for k, c in candidates.items()
             if c.speed is not None and k in table}
    if not valid:
        return Command(speed=0.0, source="NO_WINNER")
    winner = max(valid, key=lambda k: table[k])
    return valid[winner]


# =====================================================================
# 转移条件（契约第 5 节的机器可读版；纯函数，便于 pytest）
# ---------------------------------------------------------------------
# ⚠ 20261116 说明：want_track / want_avoid / want_finish 用的是**米制距离**阈值，
#   而 v2 感知不提供斑马线/终点的米制距离（消息里没有这个字段），M1NodeV2 实际
#   只用自己的像素行判据（NodeCfg.zebra_trig_y2 / end_trig_y2）判转移。
#   因此这三个函数只作"契约语义参考 + 旧脚本兼容"保留，**不是** M1 的实际判据，
#   改阈值要改 NodeCfg，别改这里。want_junction 已按下述修掉，它是真在用的语义。
# =====================================================================
def want_track(ctx: Ctx, zebra_db: bool, zebra_frames: int) -> bool:
    """TRACK -> SLOWDOWN：防抖由调用方维护，此处只判阈值。（参考实现，见上方说明）"""
    return ctx.state is State.TRACK and zebra_db and ctx.events.zebra_dist < ZEBRA_TRIG

def want_avoid(ctx: Ctx, obst_db: bool) -> bool:
    """TRACK -> AVOID。障碍距离是真实米值（RangeReading.distance_m），此项仍有效。"""
    return ctx.state is State.TRACK and obst_db and ctx.obstacle.present \
        and ctx.obstacle.dist < OBST_TRIG

def want_finish(ctx: Ctx, end_db: bool) -> bool:
    """TRACK -> FINISH（参考实现）。真实判据见 NodeCfg.end_trig_y2 + 红锥当前可见。"""
    return ctx.state is State.TRACK and end_db and ctx.events.end_dist < END_TRIG

def want_junction(ctx: Ctx) -> bool:
    """TRACK -> JUNCTION。

    20261116 修正：原实现要求 JUNCTION_WINDOW[0] <= zebra_dist <= JUNCTION_WINDOW[1]，
    但 v2 感知不提供斑马线距离，adapter 恒填 NO_DETECTION=99.0，窗口 (-0.3, 1.0)
    永远不成立 —— 这个函数**从来没返回过 True**，JUNCTION 态实际由
    m1_node_v2 的 branch_on（lane.is_branch 防抖）触发。
    现在改成只认分叉候选本身（LaneCandidate.is_branch），不再拿一个不存在的
    米制距离当门；同时排除 AVOID 期间（避障时不判分叉，评分 2.4 允许短暂跨线）。
    """
    return (ctx.state is not State.AVOID) and ctx.events.junction

def snapshot_stale(last_recv_age: float, timeout: float = STALE_TIMEOUT) -> bool:
    """snapshot 接收超时看门狗（感知组文档明文要求）。

    聚合器节点崩溃后不会主动发 INVALID——health 停在最后一个值
    （可能还是 VALID），必须靠 M1 自己计时兜底。

    参数:
        last_recv_age: 距上次收到 snapshot 的时间 s（节点用 ROS 时钟算）
        timeout: 超时阈值 s（默认 STALE_TIMEOUT=0.5）

    返回: True = snapshot 断流，应进 ESTOP
    """
    return last_recv_age > timeout


def want_estop(ctx: Ctx, line_lost_age: float, msg_stale: bool) -> bool:
    """① 丢线超时（AVOID 中抑制）② snapshot 断流 ③ 任一消息过期。
    msg_stale 由 snapshot_stale() 计算。评委急停为硬件直通，不在此列。"""
    if msg_stale:
        return True
    if ctx.state in (State.TRACK, State.JUNCTION) and line_lost_age > LINE_LOST_TIMEOUT:
        return True
    return False
