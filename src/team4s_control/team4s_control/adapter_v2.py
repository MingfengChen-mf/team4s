"""
adapter_v2.py —— 感知组 v2 snapshot → contract.Ctx 适配层
（20261116 坐标修订版对齐；本次修订逐条对应感知组 v2 包原文）

边界（按《规控组架构与分工说明》第 2、3 节）
------------------------------------------------
M1 / adapter 只做「翻译 + 有效性判定」，**不做标定、不做控制律、不做单位换算**。
所以本文件里没有 px→m 的系数、没有 bbox→距离的模型。理由：
  · 米制是感知组的产物（LaneObservation.offset_m / offset_m_valid / metric_reason）；
  · 感知组已明确 approved=false，真实米制未批准，M1 不得自行制造第二套米制；
  · 距离类事件（zebra / 终点）改用 bbox 底边像素行做「单调阈值」，只调一个像素数，
    不产生任何米制声明。

本次（20261116 坐标修订版）相对上一版的修订，逐条给出感知组依据
--------------------------------------------------------------
R1 坐标原点改为「车头正中地面投影」：offset_m 是**前方参考点**的偏差，不是后轴误差。
   → 新增 metric_frame_id 校验（不是 base_link 就拒绝，不猜）、metric_reference_x_m
     透传到 ctx.lane.ref_x_m、offset_m 与 metric_reference_y_m 的符号自洽校验。
   依据：01-正式接入规范.txt §四；LaneObservation.msg 注释
   「Positive right, at the projected reference point; NOT axle lateral error.」；
   坐标原点约定.json（front_origin=0, alignment_basis=same_origin_by_definition）。
R2 子观测有效性必须逐层查，不能只看 health：
   → 新增 _stream_check()：health.state → meta.valid → meta.stamp_source → 采集年龄，
     四层任一不过即判该路不可用，并记下具体原因（写进 extra 供答辩对账）。
   依据：§六「规控同时检查当前 run_id、对应 health、子观测 meta.valid 以及具体字段的
   有效标志；snapshot 整体的 header 时间不是所有子观测采集时间」。
R3 采集年龄的判定：优先用 TopicHealth.age_s（感知用自己的子流时间算好），
   health 未配置（max_age_s=0）或 age_unknown 时退回子流 meta.header.stamp，
   但仅当 meta.stamp_source 明确（READ_START / HARDWARE_SYNCED）才算——
   STAMP_UNKNOWN 表示"这张图的时间不可知"，拿它算年龄是编的。
   依据：§六 + SourceHeader.msg 的 STAMP_* 枚举 + TopicHealth.msg 的 age_known。
R4 车道候选不再"任意非支线兜底"：v2 明确定义 FIRST=主路左车道、SECOND=主路右车道，
   且"身份未可靠建立时，感知保持无效"。上一版兜底到任意候选，一旦感知身份错乱就会
   跟着跑错车道（弯道 30 分直接废）。现在只在"候选没有身份（route_lane=UNKNOWN）且
   唯一"时兜底，并标 unlabeled_fallback 降级。
   依据：§三 target_lane 定义；LaneCandidate.msg 的 route_lane 枚举。
R5 斑马线 / 红锥 / 绿锥事件按 (run_id, source_session_id, event_id) 判重，
   跨 run 必须清锁存；否则上一轮的终点锁存会把这一轮起步就判成到达终点。
   依据：§五「事件按 run_id、source_session_id、event_id 去重，持续看见同一事件不反复触发」。
R6 障碍读数逐条看 valid + reason，再叠加物理门限；"全被否掉"≠"前方清空"的语义
   用 ranging_state 表达，且 left/right_clear_known=false 时绝不给 clear 结论。
   依据：§五 + ObstacleObservation.msg「Unknown space must not be encoded as clear.」。
R7 snapshot 的 run_id 与本地 TaskState 的 run_id 不一致时要能被发现。
   依据：§三「正式数据的 run_id 须与当前 task_state 一致」。
   默认只告警不硬停（理由见 AdapterCfg.run_id_policy 注释）。

ctx.extra 承载所有新增信息，contract.py 只加了三个纯透传字段（unit / ref_x_m / calib_id）。
"""

from __future__ import annotations   # Py3.8 兼容：float | None 等仅作字符串注解（Foxy 容器 Py3.8）

import math
import os
import sys
from dataclasses import dataclass, field

_HERE = os.path.dirname(os.path.abspath(__file__))
_ROOT = os.path.dirname(_HERE)
for _p in (_HERE, _ROOT):
    if _p not in sys.path:
        sys.path.insert(0, _p)

from contract import Ctx, LaneError, NO_DETECTION, BASE_FRAME, PERCEPTION_MAX_AGE_S  # noqa: E402

HEALTH_MISSING, HEALTH_VALID, HEALTH_INVALID, HEALTH_STALE = 0, 1, 2, 3
HEALTH_NAMES = {0: 'MISSING', 1: 'VALID', 2: 'INVALID', 3: 'STALE', -1: 'ABSENT'}

CONE_UNKNOWN, CONE_PRESENT, CONE_LEAVING, CONE_REMOVED = 0, 1, 2, 3
COLOR_UNKNOWN, COLOR_GREEN, COLOR_RED = 0, 1, 2

# SourceHeader.stamp_source（对应 SourceHeader.msg 的 STAMP_* 枚举）
STAMP_UNKNOWN, STAMP_READ_START, STAMP_HARDWARE_SYNCED = 0, 1, 2
STAMP_NAMES = {0: 'unknown', 1: 'read_start', 2: 'hardware_synced'}


# =====================================================================
# 配置
# =====================================================================
@dataclass
class AdapterCfg:
    # --- 横向偏差单位策略 ---
    # 'auto'  : 有合法米值就用 cm；没有就透传像素并标记 unit='px'
    # 'px'    : 一律透传像素（M2 的增益按每像素调）
    # 'cm'    : 只接受米值，没有就判 track_valid=False（不猜）
    track_err_unit: str = 'auto'

    # --- 时效（R3）---
    # 默认取感知组 initial_static_review.json 的 0.5 s（**首次静止联调参数**）。
    # 该文件明说尚未按行驶速度/制动距离/最坏延迟验证，所以这是"联调可用"值，
    # 不是"自动行驶已验证"值；正式行驶配置要另存一版并在此替换。
    max_age_s: float = PERCEPTION_MAX_AGE_S

    # --- R2：子观测有效性 ---
    require_meta_valid: bool = True      # meta.valid=false 即判该路不可用
    # meta.valid 字段缺失时（离线回放 / 老数据没有这个 bool）不当作 false，
    # 只记 meta_valid_unreported。理由是"没报"不等于"报了无效"，误判会把整路数据废掉。

    # --- R1：米制口径校验 ---
    metric_frame_expected: str = BASE_FRAME
    # offset_m 的合理性上界：半车道 0.15 m，留足绕障余量到 0.5 m。
    # 超过这个数说明要么感知选错了候选、要么单位错了。此时**不拒绝整帧**，
    # 而是退回像素透传（保功能），同时记 metric_offset_implausible 供排查。
    metric_offset_max_m: float = 0.5
    # offset_m 与 metric_reference_y_m 的一致性容差（msg 定义 offset_m = -reference_y）
    metric_consistency_tol_m: float = 5e-3

    # 感知组 03/README「米制偏差定义」原话：
    #   「只有 offset_m_valid=true，且**标定ID、图像尺寸、frame_id、验证像素范围
    #   和地面距离范围匹配**时才能消费。」
    # 前两条我们原先只做了 frame_id，这里补齐另外几项。
    metric_require_calibration_id: bool = True
    metric_calibration_denylist: tuple = ('synthetic',)
    # 感知组自己声明「samples 里的 synthetic_only.json 也是假标定，不能用于真实车辆；
    # 代码拒绝把带 synthetic 标志的标定用于真实 source_id」（03/README L30）。
    # 他们守住了自己的入口，我们这边也要守出口：calibration_id 带 synthetic 水印
    # 说明这批米值来自假标定（例如 metric_synthetic.json 的 SYNTHETIC_ONLY_TEST），
    # 一旦有人把离线/合成源接进正式域，这是最后一道能拦住的地方。
    metric_image_size: tuple = (320, 240)
    # 九点支撑域（前向 m）。出处：base-front-origin-review.json 的
    #   front_ground_support_m = {forward:[0.5,1.0], left:[-0.1,0.1]}
    # 这是**标定取点覆盖的范围**，落在范围外的参考点等于外推。
    # §四「已验证范围之外不外推为有效结果」——所以这里拒，且退回像素保功能。
    # ⚠ 感知日后填了 validated_forward_range_m（更宽的实测范围）时，改这里对齐。
    metric_forward_support_m: tuple | None = (0.5, 1.0)

    # --- R4：车道身份 ---
    lane_identity_strict: bool = True    # True = 只认 route_lane == target_lane 的候选
    allow_single_unlabeled_candidate: bool = True
    # 感知可能还没建立主路身份（route_lane 全为 UNKNOWN=0）。此时如果只有一个非支线
    # 且 center_valid 的候选，用它并标 unlabeled_fallback（降级限速），而不是停车。
    # 依据：§八 明说"主路身份自动初始化仍待验证"——功能上必须能跑，溯源上必须标出来。

    # --- R7：run_id 一致性 ---
    # 'warn'  : 记 run_id_mismatch 进 extra.degraded（日志/答辩可见），**不改速、不停车** ← 默认
    # 'strict': 米值与像素都不采信（走丢线阶梯），用于接入验收
    # 'off'   : 完全不检查
    # 为什么默认 warn 而不降速：§八 明说"真实 task_state 接通仍待验证"，即感知侧还没
    # 证实会把收到的 run_id 回填到 snapshot。此时若按不一致就限速，整场比赛会一直
    # 以 V_SLOW 跑（附加分 3.1 用时直接吃亏），而基础分并不会因此提高。
    # 验收阶段（§九 第 3 条）应切 strict，让不对齐的数据真正被拒。
    run_id_policy: str = 'warn'

    # --- 测距可信门限（依据 06-测距原始证据；需感知组确认传感器语义）---
    # ⚠ 20261116 交接警示（AI_HANDOFF §5）：单点激光「物理有效性未通过」——
    #   实测 80cm 目标读 13cm。本层过滤只能拦垃圾帧（弱信号/死区/越界），
    #   拦不住系统性错读。评分规则 2.4 静态障碍绕行占 30 分，避障联调前
    #   必须先向感知组确认激光可信性，M1 不代替感知组背书。
    physical_gates: bool = True   # 关掉则只用 valid + reason（感知组的正式口径）
    signal_min: int = 10          # <10 = 弱回波（实测垃圾读数 signal 3~4，真值 19）
    dist_floor_m: float = 0.16    # 传感器死区/自检回波（实测 0.134~0.141）
    dist_ceil_m: float = 6.0
    status_invalid: tuple = (7,)  # 与弱信号垃圾读数同现，暂按无效
    obst_win: int = 3             # 时域 N 帧内 M 次一致
    obst_need: int = 2

    # --- 视觉锥桶障碍兜底（20261118：感知组确认激光雷达不使用）---
    # 背景：评分 2.4 静态障碍绕行 30 分，但 v2 消息里唯一的障碍源 ObstacleObservation
    #   来自 RangeReading[]（雷达），感知组已明确雷达不使用；视觉侧 cones[] 只有
    #   GREEN/RED 两色，且 RED 已被语义锁定为终点（red_finish_visible）。
    # 因此这里提供"视觉锥桶当障碍"的**可选**兜底，默认关闭，理由：
    #   ① 感知组从未定义"障碍锥"类别，也无自行车检测；M1 不得凭空发明语义；
    #   ② 若把终点红锥当障碍绕，会和 FINISH 判据直接冲突，任务一/二终点全丢。
    # 开启前提（三项同时满足，缺一不可）：
    #   · 感知组在 cones[] 里给出独立的障碍锥（如新增 color 值或 candidate_id 约定）；
    #   · 明确这些障碍锥与 red_finish_visible 指向的不是同一批；
    #   · 实车验证绕行+回归（评分 2.4），否则关闭。
    vision_obstacle_enabled: bool = False
    # 视觉锥桶→伪距离的锚点：用 bbox 底边行 y2 判"近"，不反推米值（沿用像素行阈值口径）。
    # 只有 y2 >= 该行才认为障碍进入绕行触发区；需按 320x240 图实测标定。
    vision_obstacle_y2_trig: int = 150
    # 绕行结束：锥桶离开视野（y2 变 None）或已确认终点时立即让位给常规判据。

    # 雷达永久不用后，optional 流缺失不再触发 DEGRADE 限速。
    # 依据：感知组已明确激光雷达不使用（20261118），该流将永远缺席；若继续按
    # "测距不可用→降速"处理，全程被压到 v_degrade(V_SLOW)，比巡航慢 35%，
    # 直接损失评分 3.1 有效用时加分，且不影响任何安全性（避障本就无数据源）。
    # 注意：只豁免"永久缺席（ABSENT/MISSING 且从未配置）"；若该流配置过又
    # 变 INVALID/STALE（真故障），仍按降级/故障处理，避免掩盖突发失效。
    missing_optional_no_degrade: bool = True

    # --- 事件 ---
    require_green_seen_for_start: bool = True
    red_latch: bool = True

    # --- 健康 ---
    required_streams: tuple = ('lane', 'scene')
    optional_streams: tuple = ('obstacles',)


@dataclass
class Extra:
    """ctx 之外的新增信息（只在 M1 内部用；M2/M3 可读，不得写）。"""
    # --- R1 车道米制口径 ---
    track_err_px: float = 0.0
    track_err_unit: str = 'none'        # px | cm | none
    track_err_source: str = 'none'      # metric | pixel_passthrough | hold | none
    metric_reason: str = ''
    metric_ok: bool = False             # offset_m_valid 且本地校验全过
    metric_reject: str = ''             # 本地拒绝原因（frame/consistency/plausible/flag）
    calibration_id: str = ''
    metric_frame_id: str = ''
    ref_x_m: float | None = None        # 前方参考点前向距离（透传，M2 用）
    candidate_id: str = ''
    ref_y_px: float = 0.0
    lane_note: str = ''
    lane_unlabeled_fallback: bool = False

    # --- R2 溯源：这一拍到底用的是哪一帧 ---
    run_id: str = ''                    # snapshot.run_id
    aggregator_session_id: str = ''
    aggregator_seq: int = -1
    lane_source_id: str = ''
    lane_session_id: str = ''
    lane_seq: int = -1
    lane_stamp_src: int = -1
    lane_age_s: float | None = None
    scene_source_id: str = ''
    scene_session_id: str = ''
    scene_seq: int = -1
    scene_stamp_src: int = -1
    scene_age_s: float | None = None

    # --- 场景（像素行原值，供 M1 做单调阈值；不做米制换算）---
    zebra_y2: float | None = None
    zebra_visible_now: bool = False
    end_y2: float | None = None
    end_source: str = ''                # red_confirmed | red_visible | none
    red_visible_now: bool = False       # **当前帧**红锥可见（FINISH 判据用它，不用锁存）

    # --- 事件身份（R5：按 run/session/event 三元组去重）---
    green_seen_ever: bool = False
    red_confirmed_ever: bool = False
    red_event_id: int = 0
    red_event_key: tuple = ()
    zebra_event_id: int = 0
    zebra_event_key: tuple = ()

    # --- 测距 ---
    dist_trusted: bool = False
    ranging_state: str = 'no_data'      # ok | degraded | no_data | unconfigured | stale
    rejected: dict = field(default_factory=dict)
    obstacle_reason: str = ''
    obstacle_source: str = 'none'       # range | vision_cone | none——本拍障碍结论来自哪一路
    vision_obstacle_y2: float | None = None  # 视觉兜底选中的障碍锥底边行（仅诊断）
    # 为什么加这两项：雷达不用后必须能一眼看出"障碍结论从哪来"，否则答辩无法说明
    # 绕障依据；同时把视觉锥的行值留在诊断里，便于标定 vision_obstacle_y2_trig。

    health: dict = field(default_factory=dict)
    faults: list = field(default_factory=list)
    degraded: list = field(default_factory=list)

    def note(self, item: str):
        if item and item not in self.degraded:
            self.degraded.append(item)


def g(obj, key, default=None):
    """兼容 ROS 消息对象与离线 dict。"""
    if obj is None:
        return default
    if isinstance(obj, dict):
        return obj.get(key, default)
    return getattr(obj, key, default)


def _finite(v):
    try:
        f = float(v)
    except (TypeError, ValueError):
        return None
    return f if math.isfinite(f) else None


def _int_or(v, default=0):
    try:
        return int(v)
    except (TypeError, ValueError):
        return default


def stamp_seconds(meta):
    """子观测采集时间 → 秒。取的是 meta.header.stamp（**不是** snapshot.header）。"""
    hdr = g(meta, 'header')
    st = g(hdr, 'stamp')
    sec = _finite(g(st, 'sec'))
    nsec = _finite(g(st, 'nanosec'))
    if sec is None:
        return None
    return sec + (nsec or 0.0) * 1e-9


# =====================================================================
class Adapter:
    def __init__(self, cfg: AdapterCfg | None = None):
        self.cfg = cfg or AdapterCfg()
        self.expected_run_id = ''      # M1 每次任务写入（R7）
        self._green_latch = False
        self._red_latch = False
        self._red_event_id = 0
        self._obs_hist = []

    # ------------------------------------------------------------------
    def reset_events(self):
        """新一轮任务：清事件锁存与防抖历史。

        依据 §五「事件按 run_id、source_session_id、event_id 去重」。不清的话，
        任务一在起点看到的红锥（起点终点同位）会把锁存带到整圈，起步即判"已到终点"。
        """
        self._green_latch = False
        self._red_latch = False
        self._red_event_id = 0
        self._obs_hist = []

    # ------------------------------------------------------------------
    def to_ctx(self, snapshot, target_lane: int, prev_ctx: Ctx | None = None,
               now_s: float | None = None) -> Ctx:
        """now_s：ROS 当前时间（秒）。传 None 表示离线回放、不做采集年龄判定。"""
        ctx = Ctx()
        if prev_ctx is not None:
            ctx.state = prev_ctx.state
        ctx.extra = Extra()

        ex = ctx.extra
        ex.run_id = str(g(snapshot, 'run_id', '') or '')
        ex.aggregator_session_id = str(g(snapshot, 'aggregator_session_id', '') or '')
        ex.aggregator_seq = int(g(snapshot, 'sequence', -1) or -1)
        self._check_run_id(ex)

        self._adapt_lane(snapshot, target_lane, ctx, prev_ctx, now_s)
        self._adapt_scene(snapshot, ctx, now_s)
        self._adapt_obstacles(snapshot, ctx, now_s)
        ex.health = read_health(snapshot)
        return ctx

    # ------------------------------------------------------------------
    def _check_run_id(self, ex):
        """R7：snapshot.run_id 应等于本地 TaskState.run_id（§三）。"""
        policy = self.cfg.run_id_policy
        if policy == 'off':
            return
        local = self.expected_run_id
        if not local or not ex.run_id:
            return                      # 任一侧为空 → 无从比较，不判错
        if ex.run_id != local:
            ex.note('run_id_mismatch')
            if policy == 'strict':
                ex.note('run_id_strict_reject')

    def _run_id_strict(self):
        return self.cfg.run_id_policy == 'strict' and bool(self.expected_run_id)

    # ------------------------------------------------------------------
    def _stream_check(self, snapshot, name, now_s) -> tuple[bool, str, float | None]:
        """R2/R3：子流四层有效性。返回 (可用, 原因码, 采集年龄s)。

        层次：① 有数据 ② TopicHealth.state==VALID ③ meta.valid ④ 采集年龄。
        任何一层不过都返回原因码（不返回 bool 了事），原因码会进 extra.degraded，
        答辩时可以逐条解释"这一拍为什么不用它"。
        """
        sub = g(snapshot, name)
        h = g(snapshot, name + '_health')
        if sub is None:
            return False, f'{name}_absent', None

        hstate = int(g(h, 'state', HEALTH_MISSING) or 0)
        if hstate != HEALTH_VALID:
            return False, f'{name}_health_{HEALTH_NAMES.get(hstate, hstate).lower()}', None

        meta = g(sub, 'meta')
        if meta is not None and self.cfg.require_meta_valid:
            mv = g(meta, 'valid', None)
            if mv is False:
                why = str(g(meta, 'reason', '') or '')
                return False, f'{name}_meta_invalid' + (f':{why}' if why else ''), None

        # ---- 采集年龄 ----
        # 两个来源都算，取**更保守**的那个：
        #   · TopicHealth.age_s 是感知用自己的子流时间算好的（正常情况下就够）；
        #   · 子流 meta.header.stamp 是原始采集时间，但只有 stamp_source 明确时才可用。
        # 两者都可用却互相矛盾，说明其中一路在拿缓存/旧帧冒充新帧，按较老的那个判。
        # 依据：§六「收到消息不等于业务有效」「snapshot 整体的 header 时间不是所有子流
        # 采集时间」——所以必须落到**子流**自己的时间上，而不是只看聚合时间。
        limit = _finite(g(h, 'max_age_s')) or 0.0
        if limit <= 0:
            limit = self.cfg.max_age_s          # health 未配置（0 = unconfigured）→ 用联调值

        age_h = _finite(g(h, 'age_s')) if bool(g(h, 'age_known', False)) else None

        age_m = None
        if now_s is not None and meta is not None:
            src = g(meta, 'stamp_source', None)
            st = stamp_seconds(meta)
            # STAMP_UNKNOWN = 这张图的时间不可知，拿它算年龄是编的
            if src is not None and int(src) != STAMP_UNKNOWN and st is not None:
                age_m = now_s - st

        if age_m is not None and age_m > limit:
            return False, f'{name}_stale_stamp{age_m:.2f}s', age_m
        if age_h is not None and age_h > limit:
            return False, f'{name}_stale_age{age_h:.2f}s', age_h
        if age_h is not None and age_m is not None and abs(age_h - age_m) > limit:
            return True, f'{name}_age_disagree({age_h:.2f}/{age_m:.2f})', max(age_h, age_m)
        worst = max([a for a in (age_h, age_m) if a is not None], default=None)
        return True, '', worst

    # ---------------------------------------------------------------
    def _adapt_lane(self, snapshot, target_lane, ctx, prev_ctx, now_s):
        ex = ctx.extra
        lane = g(snapshot, 'lane')
        ok, code, age = self._stream_check(snapshot, 'lane', now_s)
        meta = g(lane, 'meta') if lane is not None else None
        if meta is not None:
            ex.lane_source_id = str(g(meta, 'source_id', '') or '')
            ex.lane_session_id = str(g(meta, 'source_session_id', '') or '')
            ex.lane_seq = int(g(meta, 'sequence', -1) or -1)
            ex.lane_stamp_src = _int_or(g(meta, 'stamp_source'), -1)
        ex.lane_age_s = age

        if not ok:
            self._hold_or_clear(ctx, prev_ctx, code)
            return
        if code:
            ex.note(code)        # 可用但有保留（例如 health 与子流时间戳互相矛盾）

        # 验收模式：run_id 不对齐的数据整路不采信（规范 §三 / §九-3）
        if self._run_id_strict() and 'run_id_mismatch' in ex.degraded:
            self._hold_or_clear(ctx, prev_ctx, 'run_id_strict_reject')
            return

        # 采样与图像几何的一致性：像素坐标基于输入原图（§四），尺寸变了说明管线变了
        w = int(g(lane, 'image_width', 0) or 0)
        hh = int(g(lane, 'image_height', 0) or 0)
        if (w, hh) not in ((0, 0), (320, 240)):
            ex.note(f'lane_image_size_{w}x{hh}_not_320x240')

        chosen, why = self._pick_candidate(lane, target_lane)
        if chosen is None:
            self._hold_or_clear(ctx, prev_ctx, why)
            return
        if why:
            ex.note(why)
        ex.lane_unlabeled_fallback = (why == 'unlabeled_fallback')

        ex.track_err_px = _finite(g(chosen, 'offset_px')) or 0.0
        ex.ref_y_px = _finite(g(chosen, 'reference_y_px')) or 0.0
        ex.candidate_id = str(g(chosen, 'candidate_id', '') or '')
        ctx.lane.heading_rad = (_finite(g(chosen, 'heading_rad'))
                                if bool(g(chosen, 'heading_valid', False)) else None)
        ctx.lane.is_branch = bool(g(chosen, 'is_branch', False))
        ctx.lane.route_lane = int(g(chosen, 'route_lane', 0) or 0)
        ctx.lane.curvature = 0.0     # 感知组不提供；前馈是 M2 的事

        # ---- R1：米制口径校验（只校验，不换算）----
        metric_ok, metric_val, reject = self._check_metric(lane, w, hh)
        ex.metric_ok = metric_ok
        ex.metric_reject = reject
        ex.metric_reason = str(g(lane, 'metric_reason', '') or '')
        ex.calibration_id = str(g(lane, 'calibration_id', '') or '')
        ex.metric_frame_id = str(g(lane, 'metric_frame_id', '') or '')
        ex.ref_x_m = _finite(g(lane, 'metric_reference_x_m'))
        ctx.lane.calib_id = ex.calibration_id

        mode = self.cfg.track_err_unit
        if metric_ok and mode != 'px':
            ctx.lane.track_err = metric_val * 100.0
            ctx.extra.track_err_unit = 'cm'
            ctx.extra.track_err_source = 'metric'
            ctx.lane.track_valid = True
            ctx.lane.unit = 'cm'
            ctx.lane.ref_x_m = ex.ref_x_m
            return

        if mode == 'cm':
            # 只接受米值。拿不到就不猜——让 M2 让位、M1 走丢线阶梯。
            ctx.lane.track_err = 0.0
            ctx.extra.track_err_unit = 'none'
            ctx.extra.track_err_source = 'none'
            ctx.lane.track_valid = False
            ctx.lane.unit = 'none'
            ctx.lane.ref_x_m = None
            ctx.extra.lane_note = f'metric_unavailable:{reject or "no_metric"}'
            ex.note('metric_unavailable')
            return

        # 像素透传：语义上是"像素偏差"，不是厘米。单位写进 extra/lane 让 M2 按增益用。
        ctx.lane.track_err = ctx.extra.track_err_px
        ctx.extra.track_err_unit = 'px'
        ctx.extra.track_err_source = 'pixel_passthrough'
        ctx.lane.track_valid = True
        ctx.lane.unit = 'px'
        ctx.lane.ref_x_m = None      # 像素偏差没有米制参考点，不要给 M2 一个假的前视距离
        # flag_false 是"米制未批准"的常态（感知 approved=false），不算降级；
        # 只有"报了 valid 却被本地校验否掉"才值得进 degraded 供排查。
        if reject and reject != 'flag_false':
            ex.note(f'metric_rejected:{reject}')
        if not ex.metric_reason:
            ex.metric_reason = reject or 'calibration_unverified'

    # ---------------------------------------------------------------
    def _check_metric(self, lane, img_w=0, img_h=0) -> tuple[bool, float, str]:
        """R1：米值能不能用。返回 (可用, 米值, 拒绝原因)。

        校验顺序按"越基础越前面"排：有效标志 → 标定版本 → 图像尺寸 → 坐标系
        → 数值有限 → 值域 → 前向支撑域 → 符号自洽。
        任何一项不过都**退回像素透传**（不是停车），因为像素观测不依赖标定，
        功能不受影响；但拒绝原因会进 extra.degraded，赛后能说清每一拍为什么不用米值。
        """
        if not bool(g(lane, 'offset_m_valid', False)):
            return False, 0.0, 'flag_false'

        # ① 标定版本：空 = 无法溯源；带 synthetic = 假标定（感知组自述不能用于真车）
        calib = str(g(lane, 'calibration_id', '') or '')
        if self.cfg.metric_require_calibration_id:
            if not calib:
                return False, 0.0, 'calibration_id_missing'
            low = calib.lower()
            for bad in self.cfg.metric_calibration_denylist:
                if str(bad).lower() in low:
                    return False, 0.0, f'calibration_{bad}'

        # ② 图像尺寸：标定矩阵是按 320x240 原始图拟合的，换分辨率/裁剪即失效
        if (self.cfg.metric_image_size
                and (img_w, img_h) not in ((0, 0), tuple(self.cfg.metric_image_size))):
            return False, 0.0, f'image_size_{img_w}x{img_h}'

        m = _finite(g(lane, 'offset_m'))
        if m is None:
            return False, 0.0, 'not_finite'

        # ③ 坐标系
        frame = str(g(lane, 'metric_frame_id', '') or '')
        # 空 frame_id = 感知没报口径。不当场拒绝（否则整条链路停摆），但记 missing_frame
        # 由调用方降级；报了别的坐标系则**直接拒绝**——那是另一个原点的数，混用必然偏。
        if frame and frame != self.cfg.metric_frame_expected:
            return False, 0.0, f'frame_{frame}_not_{self.cfg.metric_frame_expected}'
        if not frame:
            return False, 0.0, 'frame_missing'

        # ④ 值域
        if abs(m) > self.cfg.metric_offset_max_m:
            return False, 0.0, 'implausible'

        # ⑤ 前向支撑域：参考点必须在九点标定覆盖到的前向范围内
        ref_x = _finite(g(lane, 'metric_reference_x_m'))
        if self.cfg.metric_forward_support_m and ref_x is not None:
            lo, hi = self.cfg.metric_forward_support_m
            if not (lo - 1e-6 <= ref_x <= hi + 1e-6):
                return False, 0.0, f'ref_x{ref_x:.2f}_outside_support'

        # ⑥ 符号自洽：msg 定义 offset_m = -metric_reference_y_m（Y 左正 / 右正偏差）
        ref_y = _finite(g(lane, 'metric_reference_y_m'))
        if ref_y is not None and abs(m + ref_y) > self.cfg.metric_consistency_tol_m:
            return False, 0.0, f'sign_inconsistent({m:.3f} vs -{ref_y:.3f})'
        return True, m, ''

    # ---------------------------------------------------------------
    def _pick_candidate(self, lane, target_lane) -> tuple[object | None, str]:
        """R4：选候选。返回 (候选, 说明)。说明非空表示"用了但有保留"。

        v2 语义（§三）：FIRST = 沿任务行驶方向的主路左车道，SECOND = 主路右车道；
        不能按图像候选数组下标赋身份。所以身份**只能**靠 route_lane 对齐，
        不能用"数组里第一个"。
        """
        cands = list(g(lane, 'candidates', []) or [])
        if not cands:
            return None, 'no_candidates'

        def usable(c):
            return (not bool(g(c, 'is_branch', False))) and bool(g(c, 'center_valid', False))

        sel = str(g(lane, 'selected_candidate_id', '') or '')
        if sel:
            for c in cands:
                if str(g(c, 'candidate_id', '')) != sel:
                    continue
                # 感知把 selected 指到支线 → 不跟随（评分 2.2：驶入侧向支路本项 0 分）
                if bool(g(c, 'is_branch', False)):
                    break
                if not bool(g(c, 'center_valid', False)):
                    break
                rl = int(g(c, 'route_lane', 0) or 0)
                if target_lane and rl and rl != target_lane:
                    break       # selected 与本地目标车道冲突 → 身份未可靠建立，不盲从
                return c, ('selected_lane_unlabeled' if (target_lane and not rl) else '')
            # selected 不可用则继续按身份匹配，不直接失败

        if target_lane:
            for c in cands:
                if int(g(c, 'route_lane', 0) or 0) == target_lane and usable(c):
                    return c, ''

        labeled = [c for c in cands if int(g(c, 'route_lane', 0) or 0) in (1, 2)]
        if target_lane and labeled:
            # 有身份候选但没有一个对得上目标车道：宁可丢线让位，也不跟错车道。
            return None, 'target_lane_not_found'

        plain = [c for c in cands if usable(c)]
        if not target_lane and plain:
            return plain[0], 'target_lane_unknown_pick_first'
        if self.cfg.allow_single_unlabeled_candidate and len(plain) == 1:
            return plain[0], 'unlabeled_fallback'
        return None, 'no_usable_candidate'

    # ---------------------------------------------------------------
    def _hold_or_clear(self, ctx, prev_ctx, reason):
        """丢线：保持最后有效值但标记不可信（契约约定 4）。"""
        if prev_ctx is not None and getattr(prev_ctx.lane, 'track_valid', False):
            ctx.lane = LaneError(
                track_err=prev_ctx.lane.track_err,
                curvature=prev_ctx.lane.curvature,
                track_valid=False,
                heading_rad=getattr(prev_ctx.lane, 'heading_rad', None),
                is_branch=getattr(prev_ctx.lane, 'is_branch', False),
                route_lane=getattr(prev_ctx.lane, 'route_lane', 0),
                unit=getattr(prev_ctx.lane, 'unit', 'none'),
                ref_x_m=getattr(prev_ctx.lane, 'ref_x_m', None),
                calib_id=getattr(prev_ctx.lane, 'calib_id', ''),
            )
            pe = getattr(prev_ctx, 'extra', None)
            ctx.extra.track_err_px = getattr(pe, 'track_err_px', 0.0)
            ctx.extra.track_err_unit = getattr(pe, 'track_err_unit', 'none')
            ctx.extra.track_err_source = 'hold'
            ctx.extra.ref_y_px = getattr(pe, 'ref_y_px', 0.0)
            ctx.extra.candidate_id = getattr(pe, 'candidate_id', '')
        else:
            ctx.lane = LaneError(track_valid=False)
        ctx.extra.lane_note = reason
        ctx.extra.note(reason)

    # ---------------------------------------------------------------
    def _adapt_scene(self, snapshot, ctx, now_s):
        ex = ctx.extra
        scene = g(snapshot, 'scene')
        ok, code, age = self._stream_check(snapshot, 'scene', now_s)
        meta = g(scene, 'meta') if scene is not None else None
        if meta is not None:
            ex.scene_source_id = str(g(meta, 'source_id', '') or '')
            ex.scene_session_id = str(g(meta, 'source_session_id', '') or '')
            ex.scene_seq = int(g(meta, 'sequence', -1) or -1)
            ex.scene_stamp_src = _int_or(g(meta, 'stamp_source'), -1)
        ex.scene_age_s = age

        if not ok:
            # 不可用就**不给**任何事件证据（不保留上一帧的可见性），
            # 但也不清锁存——锁存是"曾经确认过"的记忆，属于另一回事。
            ctx.events.zebra_dist = NO_DETECTION
            ctx.events.end_dist = NO_DETECTION
            ex.red_visible_now = False
            ex.zebra_visible_now = False
            ex.note(code)
            return
        if code:
            ex.note(code)

        # --- 绿锥起点（v2：legacy cone_* 字段只指绿色起点锥）---
        cone_state = int(g(scene, 'cone_state', CONE_UNKNOWN) or 0)
        cone_valid = bool(g(scene, 'cone_valid', False))
        green_visible = bool(g(scene, 'green_start_visible', False))
        ctx.events.cone_state = cone_state
        ctx.events.cone_valid = cone_valid
        if cone_valid and (cone_state in (CONE_PRESENT, CONE_LEAVING) or green_visible):
            self._green_latch = True
        ex.green_seen_ever = self._green_latch

        removed = cone_valid and cone_state == CONE_REMOVED
        ctx.events.start_seen = bool(removed and (self._green_latch
                                                  or not self.cfg.require_green_seen_for_start))

        # --- 红锥终点（事件锁存 + **当前帧可见性**）---
        red_confirmed = bool(g(scene, 'red_finish_confirmed', False))
        red_visible = bool(g(scene, 'red_finish_visible', False))
        red_level = bool(g(scene, 'cones_valid', False))
        if red_confirmed or red_visible:
            eid = int(g(scene, 'red_finish_event_id', 0) or 0)
            if eid:
                self._red_event_id = eid
        ex.red_event_id = self._red_event_id
        ex.red_event_key = (ex.run_id, ex.scene_session_id, self._red_event_id)
        if red_confirmed and self.cfg.red_latch:
            self._red_latch = True
        ex.red_confirmed_ever = self._red_latch or red_confirmed
        ex.red_visible_now = bool(red_visible or red_confirmed)
        # end_seen 是"本轮确认过终点事件"的记忆，只用于日志与 reason；
        # **FINISH 判据必须用 red_visible_now**，否则任务一起步就把起点红锥当终点：
        #   起点终点同位 → 发车瞬间红锥就在车旁 → 锁存立刻为真 → 过完斑马线就停车，
        #   "到达终点/按要求停车"两项 0 分 + 弯道 30 分全部跑不完。
        # 依据：任务书「完整绕行一圈后回到起点并停车」；评分 2.1「未完成一圈记 0 分」。
        ctx.events.end_seen = bool(ex.red_confirmed_ever)
        ex.end_y2, ex.end_source = self._cone_y2(scene, COLOR_RED)
        if not red_level:
            ex.note('cones_invalid')
        # end_dist 保持 NO_DETECTION：v2 消息里没有终点距离字段，M1 不造

        # --- 斑马线（只取像素行 + 事件身份）---
        if bool(g(scene, 'zebra_valid', False)):
            ctx.events.zebra_visible = bool(g(scene, 'zebra_visible', False))
            ctx.events.zebra_confirmed = bool(g(scene, 'zebra_event_confirmed', False))
            ctx.events.zebra_event_id = int(g(scene, 'zebra_event_id', 0) or 0)
            ex.zebra_event_id = ctx.events.zebra_event_id
            ex.zebra_event_key = (ex.run_id, ex.scene_session_id, ex.zebra_event_id)
            ex.zebra_visible_now = ctx.events.zebra_visible
            if ctx.events.zebra_visible and bool(g(scene, 'zebra_bbox_known', False)):
                box = g(scene, 'zebra_bbox_xyxy', [0, 0, 0, 0])
                ex.zebra_y2 = _finite(box[3]) if len(box) >= 4 else None
        else:
            # zebra_valid=false：图案证据不成立（§五：未完成主路关联时只放诊断）。
            # 这是**常态**（画面里没有斑马线时本就如此），所以不进 degraded，
            # 只把本帧当作"没有斑马线证据"，SLOWDOWN 退出交给超时兜底。
            pass
        ctx.events.zebra_dist = NO_DETECTION     # 同上：不造假距离

        # --- 分叉 ---
        ctx.events.junction = bool(ctx.lane.is_branch) and bool(ctx.lane.track_valid)

    def _cone_y2(self, scene, color):
        """取指定颜色锥桶 bbox 的底边行（y2 越大越近，单调可用作阈值）。"""
        best = None
        for c in (g(scene, 'cones', []) or []):
            if int(g(c, 'color', 0) or 0) != color:
                continue
            if not bool(g(c, 'bbox_known', False)):
                continue
            box = g(c, 'bbox_xyxy', [0, 0, 0, 0])
            if len(box) < 4:
                continue
            y2 = _finite(box[3])
            if y2 is None:
                continue
            if best is None or y2 > best:
                best = y2
        if best is None:
            return None, 'none'
        vis = bool(g(scene, 'red_finish_visible', False))
        return best, ('red_visible' if vis else 'red_confirmed')

    # ---------------------------------------------------------------
    def _adapt_obstacles(self, snapshot, ctx, now_s):
        ex = ctx.extra
        obs = g(snapshot, 'obstacles')
        h = g(snapshot, 'obstacles_health')
        max_age = _finite(g(h, 'max_age_s')) or 0.0
        ex.ranging_state = 'unconfigured' if max_age == 0 else 'no_data'
        ex.obstacle_source = 'none'
        ex.vision_obstacle_y2 = None

        ok, code, age = self._stream_check(snapshot, 'obstacles', now_s)
        if not ok:
            # §五：无回波 / 传感器超时 / 没有覆盖 **都不等于无障碍**。
            # 所以这里只声明"我不知道"，绝不给出 clear 结论（present=False 表示
            # "没有可信障碍读数"，M3 必须看 ranging_state 才能决定敢不敢走）。
            ctx.obstacle.present = False
            ctx.obstacle.dist = NO_DETECTION
            ctx.obstacle.left_clear_known = False
            ctx.obstacle.right_clear_known = False
            ctx.obstacle.left_clear = None
            ctx.obstacle.right_clear = None
            ex.obstacle_reason = code
            ex.ranging_state = 'stale' if 'stale' in code else (
                'unconfigured' if max_age == 0 else 'no_data')
            ex.note(code)
            # 雷达不可用 → 尝试视觉锥桶兜底（默认关；开时也要排除终点锥）。
            self._vision_obstacle_fallback(snapshot, ctx)
            return
        if code:
            ex.note(code)

        readings = list(g(obs, 'readings', []) or [])
        accepted = []
        rejected = {'invalid': 0, 'weak_signal': 0, 'near_floor': 0,
                    'status': 0, 'out_of_range': 0, 'checksum': 0}
        reasons = {}
        for r in readings:
            # §五「距离须逐条检查 valid 与 reason」——先看感知自己的判定，再看本地门限
            if not bool(g(r, 'valid', False)):
                rejected['invalid'] += 1
                rs = str(g(r, 'reason', '') or 'unspecified')
                reasons[rs] = reasons.get(rs, 0) + 1
                continue
            if not bool(g(r, 'checksum_ok', True)):
                rejected['checksum'] += 1
                continue
            d = _finite(g(r, 'distance_m'))
            if d is None:
                rejected['invalid'] += 1
                continue
            if self.cfg.physical_gates:
                sig = g(r, 'signal_strength', 0) or 0
                st = g(r, 'device_status_raw', 0) or 0
                if st in self.cfg.status_invalid:
                    rejected['status'] += 1
                    continue
                if d < self.cfg.dist_floor_m:
                    rejected['near_floor'] += 1
                    continue
                if sig < self.cfg.signal_min:
                    rejected['weak_signal'] += 1
                    continue
                if d > self.cfg.dist_ceil_m:
                    rejected['out_of_range'] += 1
                    continue
            accepted.append((d, _finite(g(r, 'bearing_rad', 0.0)) or 0.0,
                             bool(g(r, 'bearing_known', False))))

        ex.rejected = rejected
        if reasons:
            ex.rejected['valid_false_reason'] = reasons

        if accepted:
            ds = sorted(a[0] for a in accepted)
            ctx.obstacle.dist = ds[len(ds) // 2]      # 中位聚合，抗单点跳变
            ctx.obstacle.present = True
            self._obs_hist.append(True)
            brg = next((a for a in accepted if a[2]), None)
            ctx.obstacle.angle = math.degrees(brg[1]) if brg else 0.0
            ex.ranging_state = 'ok'
            ex.dist_trusted = True
        else:
            ctx.obstacle.present = False
            ctx.obstacle.dist = NO_DETECTION
            self._obs_hist.append(False)
            ex.ranging_state = 'degraded' if readings else 'no_data'
            ex.dist_trusted = False
            if readings:
                ex.note('ranging_degraded')
        self._obs_hist = self._obs_hist[-self.cfg.obst_win:]

        if ctx.obstacle.present and len(self._obs_hist) >= self.cfg.obst_need:
            if sum(1 for p in self._obs_hist if p) < self.cfg.obst_need:
                ctx.obstacle.present = False
                ex.note('obst_unconfirmed')

        ctx.obstacle.left_clear_known = bool(g(obs, 'left_clear_known', False))
        ctx.obstacle.left_clear = (bool(g(obs, 'left_clear', False))
                                   if ctx.obstacle.left_clear_known else None)
        ctx.obstacle.right_clear_known = bool(g(obs, 'right_clear_known', False))
        ctx.obstacle.right_clear = (bool(g(obs, 'right_clear', False))
                                    if ctx.obstacle.right_clear_known else None)
        ctx.obstacle.readings = readings

    # ---------------------------------------------------------------
    def _vision_obstacle_fallback(self, snapshot, ctx):
        """雷达不可用时的视觉锥桶兜底（默认关闭，见 AdapterCfg.vision_obstacle_enabled）。

        不越界声明：感知组从未定义"障碍锥"类别，cones[] 只有 GREEN/RED，且 RED 已被
        语义锁定为终点。所以本方法：
          · 只在显式开启时才生效；默认不改任何东西，行为与纯无雷达一致；
          · 只认"既不是绿起点锥、也不属于当前红终点事件"的锥（按颜色 + 终点语义字段；
            ConeDetection.candidate_id 是 string 帧内标识，无法与 uint64 事件 id 对应，
            故不做候选级排除）；
          · 只产出 present + 像素行 y2 诊断，**不伪造 dist 米值、不伪造 clear**；
            dist 保持 NO_DETECTION，靠 y2 单调阈值触发避障，符合既有像素口径。
        这样即便开启，也不会把终点红锥当障碍绕、不会污染 FINISH 判据。
        """
        if not self.cfg.vision_obstacle_enabled:
            return
        ex = ctx.extra
        scene = g(snapshot, 'scene')
        if not bool(g(scene, 'cones_valid', False)):
            return

        # 终点事件身份：与 _adapt_scene 同一口径；属该事件的锥一律不当障碍。
        red_ev = int(g(scene, 'red_finish_event_id', 0) or 0)
        red_visible = bool(g(scene, 'red_finish_visible', False))
        red_confirmed = bool(g(scene, 'red_finish_confirmed', False))
        # 感知组若给出候选级事件 id（未来扩展）则按 id 排除；当前 msg 没有，
        # 退化为"红锥事件存在时排除全部 RED 锥"——宁可漏绕，不可误绕终点。
        exclude_red = red_visible or red_confirmed or red_ev != 0

        best_y2 = None
        for c in (g(scene, 'cones', []) or []):
            if not bool(g(c, 'bbox_known', False)):
                continue
            color = int(g(c, 'color', COLOR_UNKNOWN) or 0)
            if color == COLOR_GREEN:
                continue                      # 绿锥=起点，不是障碍
            if color == COLOR_RED and exclude_red:
                continue                      # 红锥=终点事件，不是障碍
            # 注：ConeDetection.candidate_id 是 string（帧内候选标识），与
            # red_finish_event_id(uint64) 类型不同、无法对应，故不做 id 级排除；
            # 终点锥的隔离完全依赖颜色 + red_finish_* 语义字段（见上方 exclude_red）。
            box = g(c, 'bbox_xyxy', [0, 0, 0, 0])
            if len(box) < 4:
                continue
            y2 = _finite(box[3])
            if y2 is None or y2 < self.cfg.vision_obstacle_y2_trig:
                continue
            if best_y2 is None or y2 > best_y2:
                best_y2 = y2

        if best_y2 is None:
            ex.note('vision_obstacle_none')
            return

        # 视觉兜底命中：只置 present + 诊断行值，dist 仍为 NO_DETECTION。
        # ranging_state 用专用值，M3/答辩据此知道这是像素级兜底而非可信测距。
        ctx.obstacle.present = True
        ctx.obstacle.dist = NO_DETECTION
        ctx.obstacle.angle = 0.0
        ctx.obstacle.left_clear_known = False
        ctx.obstacle.right_clear_known = False
        ctx.obstacle.left_clear = None
        ctx.obstacle.right_clear = None
        ex.vision_obstacle_y2 = best_y2
        ex.obstacle_source = 'vision_cone'
        ex.ranging_state = 'vision_cone'
        ex.dist_trusted = False
        ex.obstacle_reason = 'vision_cone_fallback'
        ex.note('vision_cone_fallback')


# =====================================================================
def read_health(snapshot) -> dict:
    """把三路 TopicHealth 摊平成 dict（含 age 明细，便于判定与日志）。"""
    out = {}
    for name in ('lane', 'scene', 'obstacles'):
        h = g(snapshot, name + '_health')
        if h is None:
            out[name] = {'state': -1, 'name': 'ABSENT', 'reason': 'absent',
                         'age_s': None, 'age_known': False,
                         'max_age_s': 0.0, 'configured': False}
            continue
        state = int(g(h, 'state', HEALTH_MISSING) or 0)
        max_age = _finite(g(h, 'max_age_s')) or 0.0
        out[name] = {'state': state, 'name': HEALTH_NAMES.get(state, state),
                     'reason': str(g(h, 'reason', '') or ''),
                     'age_s': _finite(g(h, 'age_s')),
                     'age_known': bool(g(h, 'age_known', False)),
                     'max_age_s': max_age,
                     'configured': max_age > 0}
    return out


def health_verdict(health: dict, cfg: AdapterCfg) -> tuple[str, list, list]:
    """('OK'|'DEGRADE'|'FAULT', faults, degraded)

    FAULT  = 必需流不可用 → 停车（可恢复，不锁存）
    DEGRADE= 仅测距不可用 / 仅参数未配置 → 降速继续，但**不推断前方安全**

    分级依据（架构文档 §2 + v2 规范 §六）：
      · lane/scene 缺失或无效 → 没有横向输入、没有事件证据，必须停；
      · obstacles 缺失 → 只是"不知道有没有障碍"，可降速走（雷达当前就坏着，
        一律 ESTOP 会让车停在起点，评分 0 分）。
    """
    faults, degraded = [], []
    for name in cfg.required_streams:
        h = health.get(name, {})
        st = h.get('state', -1)
        if st in (HEALTH_MISSING, HEALTH_INVALID, -1):
            faults.append(f'{name}_{h.get("name", "MISSING").lower()}')
        elif st == HEALTH_STALE:
            faults.append(f'{name}_stale')
        elif not h.get('configured', False):
            degraded.append(f'{name}_max_age_unconfigured')
        elif not h.get('age_known', False):
            degraded.append(f'{name}_age_unknown')
        elif (h.get('age_s') or 0.0) > (h.get('max_age_s') or cfg.max_age_s):
            # health 自己说 VALID 但年龄超了 —— 以年龄为准（收到消息 ≠ 业务有效）
            faults.append(f'{name}_stale_age')
    for name in cfg.optional_streams:
        h = health.get(name, {})
        st = h.get('state', -1)
        # 永久缺席豁免：从未配置且状态是 ABSENT/MISSING —— 视为该路根本没启用，
        # 不算降级（雷达不用场景），但仍在 degraded 里留一条 only-log 标记供答辩可见。
        perm_absent = (cfg.missing_optional_no_degrade
                       and st in (HEALTH_MISSING, -1)
                       and not h.get('configured', False))
        if st in (HEALTH_MISSING, HEALTH_INVALID, HEALTH_STALE, -1):
            if not perm_absent:
                degraded.append(f'{name}_{h.get("name", "MISSING").lower()}')
        elif not h.get('configured', False):
            degraded.append(f'{name}_max_age_unconfigured')
    if faults:
        return 'FAULT', faults, degraded
    return ('DEGRADE' if degraded else 'OK'), faults, degraded


_default = Adapter()


def snapshot_to_ctx(snapshot, target_lane, prev_ctx=None, now_s=None):
    return _default.to_ctx(snapshot, target_lane, prev_ctx, now_s)


def check_health(snapshot):
    verdict, faults, degraded = health_verdict(read_health(snapshot), _default.cfg)
    if verdict == 'FAULT':
        return True, ','.join(faults)
    return False, ','.join(degraded)
