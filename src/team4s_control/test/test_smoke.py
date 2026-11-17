"""
test_smoke.py —— M1 ROS 2 外壳本地冒烟测试（任务书 (14) ③）

运行（无 ROS 环境直接跑，不 source ROS）：
    python3 ~/team4s/src/team4s_control/test/test_smoke.py

mock 最小面（以 (4) 核对结果为准）：四个附件实际 import 的 rclpy 符号 = 空集
（附件鸭子类型、零 rclpy import，grep 已确认）。因此 mock 只需覆盖外壳自身用到的
符号：rclpy / rclpy.node.Node / rclpy.qos 四件套 / std_msgs.msg.Bool /
team4s_interfaces.msg 的 PerceptionSnapshot + TaskState（空容器，字段可写），
在 import m1_node 之前注入 sys.modules。

断言内容：
  a. 构造节点（task_id=1, target_lane=1）→ 不抛异常
  b. 假 snapshot 回调一帧合法快照 → 不抛异常
  c. 驱动**外壳 timer 回调** 40 拍（不直接喂内核 tick）：mock clock 每拍推进
     递增步长，dt 由外壳按 (6) 自算（首拍 nominal_dt，其后真实差值）——spy 只
     记录 tick 的两参，不断言喂进去的常量形参
  d. publish_task_state 变化拍返回 dict、节流拍 None → 断言两个分支都走到
  e. speed_to_duty(m1.last_cmd.speed) ∈ [0.0, 0.10]
"""

from __future__ import annotations   # Py3.8 兼容：注解新语法降级为字符串

import os
import sys
import types
from types import SimpleNamespace

_HERE = os.path.dirname(os.path.abspath(__file__))
_PKG = os.path.join(os.path.dirname(_HERE), 'team4s_control')
if _PKG not in sys.path:
    sys.path.insert(0, _PKG)

_PERIOD_NS = 100000000        # 内核 TASK_STATE_PERIOD_S=0.1s 对应 ns
_NOMINAL_DT = 0.05


# =====================================================================
# MinimalMock：只覆盖外壳实际用到的符号
# =====================================================================
class MockTime:
    """对齐 rclpy.time.Time 的可用子集：nanoseconds 属性 + seconds_nanoseconds()。

    （Foxy/Humble 的 Time 没有 .sec/.nanosec 属性——B 类差异，见 README。）"""

    def __init__(self, sec, nanosec):
        self.sec = int(sec)
        self.nanosec = int(nanosec)

    @property
    def nanoseconds(self):
        return self.sec * 1000000000 + self.nanosec

    def seconds_nanoseconds(self):
        return self.sec, self.nanosec


class MockClock:
    """可控时钟：测试每拍 advance 一个递增步长，驱动外壳 timer 回调。"""

    def __init__(self, start_s=1000.0):
        self._ns = int(start_s * 1000000000)

    def now(self):
        return MockTime(self._ns // 1000000000, self._ns % 1000000000)

    def advance(self, dt_s):
        self._ns += int(round(dt_s * 1000000000))


class MockLogger:
    def __init__(self):
        self.infos, self.warns, self.errors = [], [], []

    def info(self, *a):
        self.infos.append(a[0] % a[1:] if len(a) > 1 else a[0])

    def warning(self, *a):
        self.warns.append(a[0])

    warn = warning

    def error(self, *a):
        self.errors.append(a[0])


class MockPublisher:
    def __init__(self):
        self.msgs = []

    def publish(self, msg):
        self.msgs.append(msg)


class MockNode:
    """外壳 Node 基类的最小实现：记录端点创建，参数走 declare→get。"""

    def __init__(self, name):
        self.node_name = name
        self._params = {}
        self.subscriptions = []      # (msg_type, topic, callback, qos)
        self.publishers = []         # (msg_type, topic, qos, pub)
        self.timers = []             # (period_sec, callback)
        self.clock = MockClock()
        self.logger = MockLogger()
        self.destroyed = False

    def declare_parameter(self, name, value):
        self._params[name] = value

    def get_parameter(self, name):
        return SimpleNamespace(value=self._params[name])

    def create_subscription(self, msg_type, topic, callback, qos_profile):
        self.subscriptions.append((msg_type, topic, callback, qos_profile))

    def create_publisher(self, msg_type, topic, qos_profile):
        pub = MockPublisher()
        self.publishers.append((msg_type, topic, qos_profile, pub))
        return pub

    def create_timer(self, period_sec, callback):
        self.timers.append((period_sec, callback))

    def get_clock(self):
        return self.clock

    def get_logger(self):
        return self.logger

    def destroy_node(self):
        self.destroyed = True


class MockQoSProfile:
    def __init__(self, depth=10, history=None, reliability=None, durability=None, **_kw):
        self.depth = depth
        self.history = history
        self.reliability = reliability
        self.durability = durability


class MockReliabilityPolicy:
    RELIABLE = 'reliable'
    BEST_EFFORT = 'best_effort'


class MockDurabilityPolicy:
    VOLATILE = 'volatile'
    TRANSIENT_LOCAL = 'transient_local'


class MockHistoryPolicy:
    KEEP_LAST = 'keep_last'
    KEEP_ALL = 'keep_all'


class MockBool:
    def __init__(self):
        self.data = False


class MockPerceptionSnapshot:
    pass


class MockTaskState:
    """TaskState 空容器：_fill_msg 读写的字段都在这里（10 个固定字段）。"""

    def __init__(self):
        self.header = SimpleNamespace(
            stamp=SimpleNamespace(sec=0, nanosec=0), frame_id='')
        self.run_id = ''
        self.controller_session_id = ''
        self.sequence = 0
        self.task_id = 0
        self.phase = 0
        self.target_lane = 0
        self.control_mode = 0
        self.lap_complete = False
        self.reason = ''


def install_mocks():
    rclpy_mod = types.ModuleType('rclpy')
    rclpy_mod.init = lambda args=None: None
    rclpy_mod.shutdown = lambda: None
    rclpy_mod.spin = lambda node: None
    rclpy_mod.ok = lambda: True

    node_mod = types.ModuleType('rclpy.node')
    node_mod.Node = MockNode
    qos_mod = types.ModuleType('rclpy.qos')
    qos_mod.QoSProfile = MockQoSProfile
    qos_mod.ReliabilityPolicy = MockReliabilityPolicy
    qos_mod.DurabilityPolicy = MockDurabilityPolicy
    qos_mod.HistoryPolicy = MockHistoryPolicy
    rclpy_mod.node = node_mod
    rclpy_mod.qos = qos_mod

    std_msgs_mod = types.ModuleType('std_msgs')
    std_msgs_msg_mod = types.ModuleType('std_msgs.msg')
    std_msgs_msg_mod.Bool = MockBool
    std_msgs_mod.msg = std_msgs_msg_mod

    ti_mod = types.ModuleType('team4s_interfaces')
    ti_msg_mod = types.ModuleType('team4s_interfaces.msg')
    ti_msg_mod.PerceptionSnapshot = MockPerceptionSnapshot
    ti_msg_mod.TaskState = MockTaskState
    ti_mod.msg = ti_msg_mod

    for name, mod in [('rclpy', rclpy_mod), ('rclpy.node', node_mod),
                      ('rclpy.qos', qos_mod), ('std_msgs', std_msgs_mod),
                      ('std_msgs.msg', std_msgs_msg_mod),
                      ('team4s_interfaces', ti_mod),
                      ('team4s_interfaces.msg', ti_msg_mod)]:
        sys.modules[name] = mod


# =====================================================================
# 一帧合法假快照（鸭子类型：adapter 用 g()/getattr 读字段，SimpleNamespace 即可）
# =====================================================================
def make_valid_snapshot():
    def meta(seq):
        return SimpleNamespace(
            header=SimpleNamespace(stamp=SimpleNamespace(sec=0, nanosec=0), frame_id=''),
            source_id='lane_src', source_session_id='sess1', run_id='',
            sequence=seq, stamp_source=0, valid=True, reason='')

    def health():
        return SimpleNamespace(state=1, reason='', age_known=True,
                               age_s=0.01, max_age_s=0.5)

    cand = SimpleNamespace(candidate_id='c1', route_lane=1, is_branch=False,
                           left_visible=True, right_visible=True, center_valid=True,
                           offset_px=0.0, reference_y_px=120,
                           heading_valid=False, heading_rad=0.0)
    lane = SimpleNamespace(meta=meta(1), image_width=320, image_height=240,
                           candidates=[cand], selected_candidate_id='',
                           offset_m_valid=False, offset_m=0.0, metric_reason='',
                           calibration_id='', metric_frame_id='',
                           metric_reference_x_m=0.0, metric_reference_y_m=0.0)
    scene = SimpleNamespace(meta=meta(1), cone_valid=False, cone_state=0,
                            cone_bbox_known=False, cone_bbox_xyxy=[0, 0, 0, 0],
                            zebra_valid=False, zebra_visible=False,
                            zebra_bbox_known=False, zebra_bbox_xyxy=[0, 0, 0, 0],
                            image_width=320, image_height=240,
                            cone_event_id=0,
                            cone_event_stamp=SimpleNamespace(sec=0, nanosec=0),
                            zebra_event_id=0,
                            zebra_event_stamp=SimpleNamespace(sec=0, nanosec=0),
                            zebra_event_confirmed=False,
                            cones_valid=False, cones_reason='', cones=[],
                            green_start_visible=False, red_finish_visible=False,
                            red_finish_confirmed=False, red_finish_event_id=0,
                            red_finish_event_stamp=SimpleNamespace(sec=0, nanosec=0))
    obstacles = SimpleNamespace(meta=meta(1), readings=[],
                                left_clear_known=False, left_clear=False,
                                right_clear_known=False, right_clear=False)
    return SimpleNamespace(
        header=SimpleNamespace(stamp=SimpleNamespace(sec=0, nanosec=0),
                               frame_id='perception'),
        aggregator_session_id='agg_test', run_id='t1_a1_smoke', sequence=1,
        lane=lane, lane_health=health(),
        obstacles=obstacles, obstacles_health=health(),
        scene=scene, scene_health=health())


def bool_msg(value):
    m = MockBool()
    m.data = value
    return m


# =====================================================================
# 断言框架
# =====================================================================
_CHECKS = []


def check(name, cond, detail=''):
    _CHECKS.append((name, bool(cond), detail))
    print('[%s] %s%s' % ('PASS' if cond else 'FAIL', name,
                         ('  -- ' + detail) if (detail and not cond) else ''))


def close(a, b, eps=1e-6):
    return abs(a - b) <= eps


# =====================================================================
def run():
    install_mocks()
    import m1_node                     # 必须在 mock 注入之后导入
    from contract import speed_to_duty   # 纯 Python，无 rclpy 依赖

    # -------- a. 构造节点（task_id=1, target_lane=1）→ 不抛异常 --------
    node = m1_node.M1ControlNode()
    check('a. 构造节点不抛异常（默认 task_id=1/target_lane=1）',
          node.node_name == 'm1_control' and node.m1.task_id == 1
          and node.m1.target_lane == 1,
          'node=%s task_id=%s target_lane=%s'
          % (getattr(node, 'node_name', '?'), node.m1.task_id, node.m1.target_lane))

    # QoS 必须显式声明（端点创建记录里的 BIZ_QOS 四要素）
    qos_ok = True
    qos_detail = ''
    for _t, _topic, _cb, q in node.subscriptions:
        if not (q.depth == 1 and q.reliability == 'reliable'
                and q.durability == 'volatile' and q.history == 'keep_last'):
            qos_ok, qos_detail = False, 'sub %s qos=%r' % (_topic, vars(q))
    pubs = [p for (_t, t, _q, p) in node.publishers
            if t == '/team4s/control/task_state']
    if len(pubs) != 1:
        qos_ok, qos_detail = False, 'task_state publisher 数量=%d' % len(pubs)
    else:
        q = [qq for (_t, t, qq, _p) in node.publishers
             if t == '/team4s/control/task_state'][0]
        if not (q.depth == 1 and q.reliability == 'reliable'
                and q.durability == 'volatile' and q.history == 'keep_last'):
            qos_ok, qos_detail = False, 'pub qos=%r' % vars(q)
    check('a. 三个端点 QoS 显式声明 RELIABLE/VOLATILE/KEEP_LAST/depth1', qos_ok, qos_detail)
    check('a. create_timer 周期 0.05',
          len(node.timers) == 1 and close(node.timers[0][0], 0.05),
          'timers=%r' % (node.timers,))

    subs = {t: cb for (_t, t, cb, _q) in node.subscriptions}
    check('a. 两个订阅端点（snapshot + 临时 start）',
          '/team4s/perception/snapshot' in subs and '/team4s/control/start' in subs)

    # -------- b. 假 snapshot 回调一帧合法快照 → 不抛异常 --------
    snap = make_valid_snapshot()
    snap_cb = subs['/team4s/perception/snapshot']
    start_cb = subs['/team4s/control/start']
    try:
        snap_cb(snap)
        b_ok = node.m1.snapshot is snap
    except Exception as exc:            # noqa: BLE001 —— 冒烟测试要抓一切异常
        b_ok, _ = False, repr(exc)
        print('    snapshot 回调异常: %r' % (exc,))
    check('b. 假 snapshot 回调一帧合法快照不抛异常', b_ok)

    # start 回调：False 不触发，True 触发 'topic'
    start_cb(bool_msg(False))
    check('b. start=False 不触发起步', node.m1.start_requested is False)

    # -------- c. 驱动外壳 timer 回调 40 拍 --------
    pub = pubs[0]
    timer_cb = node.timers[0][1]
    tick_calls = []
    orig_tick = node.m1.tick

    def spy_tick(now_s, dt):
        tick_calls.append((now_s, dt))
        return orig_tick(now_s, dt)

    node.m1.tick = spy_tick

    deltas = []
    changed_branch = {'seen': False}
    n_published_total = 0
    for i in range(1, 41):
        d = 0.09 if i == 1 else 0.05 + (i % 3) * 0.01   # 首步故意 ≠ nominal_dt
        deltas.append(d)
        node.clock.advance(d)
        if i == 5:
            snap_cb(snap)
        if i == 6:
            start_cb(bool_msg(True))
        before = len(pub.msgs)
        last_emit = node.m1.pub_state.last_emit_ns
        now_ns = node.clock.now().nanoseconds
        timer_cb()                                       # 驱动的是外壳 timer 回调
        if len(pub.msgs) > before:
            n_published_total += len(pub.msgs) - before
            if last_emit is None or (now_ns - last_emit) < _PERIOD_NS:
                changed_branch['seen'] = True            # 状态变化拍立即发（非节流）

    check('c. 外壳 timer 回调驱动 40 拍，内核 tick 收到 40 次两参调用',
          len(tick_calls) == 40, 'tick 次数=%d' % len(tick_calls))
    check('c. 首拍 dt=nominal_dt 0.05（而非时钟步长 0.09）',
          len(tick_calls) == 40 and close(tick_calls[0][1], _NOMINAL_DT),
          '首拍 dt=%r' % (tick_calls[0][1] if tick_calls else None))
    dt_real_ok = all(close(tick_calls[k][1], deltas[k]) for k in range(1, 40))
    check('c. 第 2..40 拍 dt = 真实时钟差值（不回退常量 0.05）', dt_real_ok,
          'dts=%s' % [round(t[1], 4) for t in tick_calls[1:6]])

    # -------- d. publish_task_state 两个分支都走到 --------
    n_none = 40 - n_published_total
    check('d. 节流拍返回 None（这拍不发）确实出现', n_none > 0,
          '发 %d 拍 / None %d 拍' % (n_published_total, n_none))
    check('d. 变化拍立即发（IDLE→TRACK sig 变化，不等 10Hz 节流）',
          changed_branch['seen'])

    # -------- 消息内容：内核用外壳传入的 now_ns 填 stamp / frame_id=base_link --------
    msgs = pub.msgs
    seqs = [m.sequence for m in msgs]
    content_ok = (all(m.header.stamp.sec > 0 for m in msgs)
                  and all(m.header.frame_id == 'base_link' for m in msgs)
                  and all(b == a + 1 for a, b in zip(seqs, seqs[1:]))
                  and all(isinstance(m.reason, str) and m.reason for m in msgs)
                  and all(m.task_id == 1 and m.target_lane == 1 for m in msgs)
                  and all(m.run_id and m.controller_session_id for m in msgs))
    check('消息内容：stamp 非 0、frame_id=base_link、sequence 严格递增、'
          '10 字段齐全', content_ok and len(msgs) > 0,
          'msgs=%d, seqs=%s' % (len(msgs), seqs[:8]))

    # -------- e. speed_to_duty(m1.last_cmd.speed) ∈ [0.0, 0.10] --------
    duty = speed_to_duty(node.m1.last_cmd.speed)
    check('e. speed_to_duty(last_cmd.speed=%r)=%.4f ∈ [0.0, 0.10]'
          % (node.m1.last_cmd.speed, duty), 0.0 <= duty <= 0.10)

    # -------- Ctrl-C 清理路径（三参 estop） --------
    from chassis_sink import NullSink
    node.sink = NullSink()
    node.emergency_stop()               # 不抛异常即可
    check('Ctrl-C 路径 emergency_stop() 三参调用不抛异常', True)
    node.destroy_node()
    check('destroy_node 生效', node.destroyed is True)

    print('-' * 60)
    failed = [n for n, ok, _d in _CHECKS if not ok]
    if failed:
        print('SMOKE TEST FAILED: %d 项未过' % len(failed))
        for n in failed:
            print('  FAIL: %s' % n)
        return 1
    print('SMOKE TEST PASSED: %d/%d 项通过' % (len(_CHECKS), len(_CHECKS)))
    return 0


if __name__ == '__main__':
    sys.exit(run())
