"""
m1_node.py —— M1 决策内核的 ROS 2 执行外壳（节点名 m1_control）

只做"套壳 + 接线"（任务书 (0)(2)），不含任何决策逻辑：
  订阅 /team4s/perception/snapshot → m1.on_snapshot(msg, now_s)
  timer 0.05s → 算 now_s/dt（规则见下）→ m1.tick(now_s, dt) → 读 m1.last_cmd
    → speed_to_duty(m/s → 占空比) → sink.write(steer, duty, source)
    → m1.publish_task_state(now_ns) 非 None 才 _fill_msg(TaskState(), ts) → publish
  订阅 /team4s/control/start（std_msgs/Bool，临时入口、不是遥控信号，可移除）
    → msg.data is True 时 m1.on_start_signal('topic')
  后台线程读 /dev/shm/2py_to_chassis.dat（厂家底盘脚本写的 motor_rpm）
    → timer 单线程取出 → m1.on_chassis(rpm) → tick() 回填 ctx.chassis.speed_rpm
    详情见 chassis_feedback.py；底盘没有 ROS2 节点，反馈只走共享内存。

dt 规则（任务书 (6)，外壳最容易写错处）：
  · 仅当上一拍 now_s 为 None（首拍）时 dt 取 nominal_dt（参数，默认 0.05）；
  · 其余所有拍 dt = 本拍 now_s − 上拍 now_s，用真实差值，绝不回退常量 0.05。

时钟（任务书 (6)）：订阅回调与 timer 统一取 self.get_clock().now()；
now_ns = stamp.nanoseconds，now_s 由 stamp.seconds_nanoseconds() 派生
（B 类：Foxy/Humble 的 rclpy.time.Time 无 .sec/.nanosec 属性，README 已注）。
TaskState.header.stamp 由内核用 publish_task_state(now_ns) 传入的 now_ns 填充
（内核 build() 负责，frame_id 固定 base_link）——外壳只传对 now_ns，不拼 stamp。

Ctrl-C（任务书 (10)(13) 坑 6）：先 sink.write(STEER_CENTER, 0.0, 'estop')（三参；
真实底盘无超时保护，退出前必须回中+零速），再 destroy_node() + rclpy.shutdown()。

Py3.8 兼容（Foxy 容器部署红线）：from future import annotations；X | Y 等新语法
只允许出现在注解位置；不用 match；不用 Humble 专有 API（按 Foxy 文档写）。
"""

from __future__ import annotations   # Py3.8 兼容：注解新语法降级为字符串（Foxy 容器 Py3.8）

import os
import sys

_HERE = os.path.dirname(os.path.abspath(__file__))
_ROOT = os.path.dirname(_HERE)
for _p in (_HERE, _ROOT):
    if _p not in sys.path:
        sys.path.insert(0, _p)

import rclpy  # noqa: E402
from rclpy.node import Node  # noqa: E402
from rclpy.qos import QoSProfile, ReliabilityPolicy, DurabilityPolicy, HistoryPolicy  # noqa: E402
from std_msgs.msg import Bool  # noqa: E402
from team4s_interfaces.msg import PerceptionSnapshot, TaskState  # noqa: E402

from contract import STEER_CENTER, speed_to_duty  # noqa: E402
# 裸 import：包内实际文件是 m1_without_ros2_node.py（Kimi 将 m1_node_v2.py 改名而来）。
# 不要用 team4s.src... 完整路径——install 后没有 team4s/src 这一层。
from m1_without_ros2_node import M1NodeV2, NodeCfg  # noqa: E402
from task_state_bridge import _fill_msg  # noqa: E402
from chassis_sink import LogSink, NullSink, SharedMemSink, DEFAULT_CMD_PATH  # noqa: E402
from chassis_feedback import FeedbackReader, DEFAULT_FEEDBACK_PATH  # noqa: E402

# QoS 必须显式声明，不许用默认值（任务书 (5)(13) 坑 1：QoS 不匹配是静默的，
# 只有一条 warning）。RELIABLE / VOLATILE / KEEP_LAST / depth 1，订阅发布同一口径。
BIZ_QOS = QoSProfile(
    depth=1,
    history=HistoryPolicy.KEEP_LAST,
    reliability=ReliabilityPolicy.RELIABLE,
    durability=DurabilityPolicy.VOLATILE,
)

TOPIC_SNAPSHOT = '/team4s/perception/snapshot'
TOPIC_START = '/team4s/control/start'        # 临时入口，不是遥控信号（见 (5)(10)）
TOPIC_TASK_STATE = '/team4s/control/task_state'


class M1ControlNode(Node):
    """m1_control：感知 snapshot 入口 + 0.05s timer 节拍 + TaskState 心跳出口。"""

    def __init__(self):
        super().__init__('m1_control')

        # 必须先 declare 再 get（任务书 (13) 坑 4：顺序反了直接抛异常）。
        self.declare_parameter('task_id', 1)        # 1=单圈，2=直道
        self.declare_parameter('target_lane', 1)    # 1=FIRST 主路左，2=SECOND 主路右
        self.declare_parameter('nominal_dt', 0.05)  # 仅首拍 dt 用（任务书 (6)）
        self.declare_parameter('sink', 'log')       # 'log'=CSV留证 / 'shm'=真实下发 / 其他=NullSink
        self.declare_parameter('log_path', '')      # LogSink CSV 路径，空=cwd 下默认名
        self.declare_parameter('cmd_shm', DEFAULT_CMD_PATH)  # SharedMemSink 命令共享内存路径
        self.declare_parameter('feedback_enabled', True)      # 底盘反馈共享内存
        self.declare_parameter('feedback_shm', DEFAULT_FEEDBACK_PATH)
        self.declare_parameter('feedback_hz', 20.0)           # 读反馈频率
        task_id = int(self.get_parameter('task_id').value)
        target_lane = int(self.get_parameter('target_lane').value)
        self._nominal_dt = float(self.get_parameter('nominal_dt').value)
        sink_type = str(self.get_parameter('sink').value)
        log_path = str(self.get_parameter('log_path').value)

        self.m1 = M1NodeV2(task_id=task_id, target_lane=target_lane, cfg=NodeCfg())

        # 底盘反馈：厂家底盘脚本写共享内存（无 ROS2 节点可读），后台线程轮询。
        # 线程只投递 rpm，真正调 on_chassis 放在 timer 里，保证内核调用单线程串行。
        self._feedback = None
        if bool(self.get_parameter('feedback_enabled').value):
            self._feedback = FeedbackReader(
                path=str(self.get_parameter('feedback_shm').value),
                hz=float(self.get_parameter('feedback_hz').value))
            self._feedback.start()

        # TODO 未接线的内核入口（任务书 (7)，写明用途与将来触发方式，不许自行发明来源）：
        # · on_new_run(attempt, task_id, target_lane)：人工复位开新一轮用；将来由
        #   裁判/操作员的显式指令（终端/服务）触发。
        # · set_target_lane(lane)：任务二避障后切 SECOND 车道用。内核不会自动切，
        #   何时切属于任务策略，由全组拍板后另接。
        # · reset_estop()：故障复位，同上，由人工确认故障排除后的显式指令触发。

        if sink_type == 'log':
            self.sink = LogSink(log_path)   # log_path 为空时 LogSink 自选 cwd 默认名
        elif sink_type == 'shm':
            # 真实下发：厂家脚本轮询 servo_shared.dat（格式 'if'），详情见 chassis_sink.py
            self.sink = SharedMemSink(str(self.get_parameter('cmd_shm').value))
        else:
            self.sink = NullSink()

        self._last_now_s = None

        self.create_subscription(
            PerceptionSnapshot, TOPIC_SNAPSHOT, self._on_snapshot, BIZ_QOS)
        self.create_subscription(
            Bool, TOPIC_START, self._on_start, BIZ_QOS)
        # TaskState 发布端 QoS 由外壳在 create_publisher 时用 BIZ_QOS 声明
        # （内核零 ROS 端点、不声明 QoS，见任务书 (4)(5)）。
        self._pub_state = self.create_publisher(TaskState, TOPIC_TASK_STATE, BIZ_QOS)
        self.create_timer(0.05, self._on_timer)

        self.get_logger().info(
            'm1_control up: task_id=%d target_lane=%d qos=RELIABLE/VOLATILE/KEEP_LAST:1'
            % (task_id, target_lane))

    # ------------------------------------------------------------------
    def _now(self):
        """订阅回调与 timer 的统一时钟源（任务书 (6)）。

        B 类（README 已注）：rclpy.time.Time 在 Foxy/Humble 均无 .sec/.nanosec 属性
        （那是 builtin_interfaces/Time 消息字段），文档 (6) 的字面写法会 AttributeError；
        seconds_nanoseconds() 在两个发行版都可用，语义与文档公式一致。"""
        stamp = self.get_clock().now()
        sec, nsec = stamp.seconds_nanoseconds()
        return stamp.nanoseconds, sec + nsec * 1e-9

    def _on_snapshot(self, msg):
        # 回调里不做重活（任务书 (13) 坑 3：Foxy 默认单线程 executor，订阅回调与
        # timer 串行；在回调里跑状态机会拖慢心跳）——只存快照，状态机在 timer 里跑。
        _now_ns, now_s = self._now()
        self.m1.on_snapshot(msg, now_s)

    def _on_start(self, msg):
        # 临时入口，不是遥控信号：裁判/操作员通过终端注入一个 Bool（任务书 (5)(10)）。
        # ROS 侧没有其他遥控状态话题；此入口仅为可测，可随时移除。
        if msg.data is True:
            self.m1.on_start_signal('topic')

    def _on_timer(self):
        now_ns, now_s = self._now()

        # dt 规则（任务书 (6)）：仅首拍取 nominal_dt；其余一律真实差值，
        # 容器负载抖动时写死 0.05 会让超时判定失真。
        if self._last_now_s is None:
            dt = self._nominal_dt
        else:
            dt = now_s - self._last_now_s
        self._last_now_s = now_s

        # 反馈注入必须在 tick() 之前：tick 里才把 speed_rpm_fb 回填到
        # ctx.chassis.speed_rpm；放后面这一拍的 velocity 会是上一拍的旧值。
        rpm = self._feedback.take_rpm() if self._feedback is not None else None
        if rpm is not None:
            self.m1.on_chassis(rpm)

        self.m1.tick(now_s, dt)

        # 底盘下发：speed 单位 m/s，下发前必须过 speed_to_duty() 转成占空比
        # （执行器量纲换算，见任务书 (10)）；不能把 m/s 当占空比直接下发。
        cmd = self.m1.last_cmd
        duty = speed_to_duty(cmd.speed)
        self.sink.write(cmd.steer, duty, cmd.source)

        # TaskState：内核 offer() 节流（10Hz 心跳 + 状态变化立即发），返回 None =
        # 这拍不发。dict 已含全部 10 个字段（含内核用 now_ns 填的 header.stamp 与
        # frame_id=base_link），外壳不拼字段，只 _fill_msg 灌进消息对象后 publish。
        ts = self.m1.publish_task_state(now_ns)
        if ts is not None:
            self._pub_state.publish(_fill_msg(TaskState(), ts))

    def emergency_stop(self):
        """退出前安全停车：真实底盘没有超时保护，必须发一条回中+零速。"""
        self.sink.write(STEER_CENTER, 0.0, 'estop')
        # 先发急停再停读线程，避免关闭过程拖住安全命令。
        if self._feedback is not None:
            self._feedback.close()
        self.sink.close()


def main(args=None):
    rclpy.init(args=args)
    node = M1ControlNode()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        # 顺序不能反（任务书 (10)(13) 坑 6）：先发安全停车，再 destroy_node +
        # rclpy.shutdown()，否则 DDS 资源残留，下次同域启动会看到幽灵节点。
        node.emergency_stop()
        node.destroy_node()
        # B 类（README 已注）：Humble 的 rclpy.spin 在 SIGINT 时信号处理器会先把
        # default context 关掉，此处再无条件 shutdown 会抛 RCLError；Foxy 无此行为。
        # 用 rclpy.ok() 守护，两个发行版都走干净退出。
        if rclpy.ok():
            rclpy.shutdown()
