# team4s M1 ROS 2 执行外壳

M1 决策内核（contract.py / adapter_v2.py / m1_node_v2.py / task_state_bridge.py，**只读零改动**）
的 ROS 2 套壳：订阅感知聚合快照 → 驱动内核 → 发布 TaskState → 底盘命令经 ChassisSink 抽象落地。

- 验证环境：WSL2 + ROS 2 Humble + Python 3.10
- 部署目标：车上容器 ROS 2 Foxy + Python 3.8.10（代码按 Foxy 文档写，见文末 B 类清单）
- 消息包：team4s_interfaces 0.2.0（未改动）

## 文件清单

| 文件 | 说明 |
|---|---|
| `src/team4s_control/team4s_control/m1_node.py` | ROS 壳（本任务新写；节点名 m1_control） |
| `src/team4s_control/team4s_control/chassis_sink.py` | 底盘输出抽象（NullSink / LogSink；真实实现 TODO） |
| `src/team4s_control/launch/m1.launch.py` | launch（ROS_DOMAIN_ID 参数化，默认 111） |
| `src/team4s_control/test/test_smoke.py` | 第一层自检③：无 ROS 冒烟测试 |
| `src/team4s_control/team4s_control/{contract,adapter_v2,m1_node_v2,task_state_bridge}.py` | 四附件工作副本，与基准零差异 |

另按（13）坑 5 补了 `package.xml` 的 `std_msgs` 依赖；`setup.py` 增加了
`m1_node` console_script 与 launch 安装。运行时产物：`m1_chassis_commands.csv`
（LogSink，cwd 下，可用参数 `log_path` 改）。

## 构建与运行

```bash
cd ~/team4s
source /opt/ros/humble/setup.bash
colcon build --packages-select team4s_interfaces team4s_control
source install/setup.bash

# WSL 隔离域起节点（车上用 ROS_DOMAIN_ID=111）
ROS_DOMAIN_ID=113 ros2 run team4s_control m1_node --ros-args -p task_id:=1 -p target_lane:=1

# 或 launch（domain_id 默认 111，WSL 传 113）
ros2 launch team4s_control m1.launch.py domain_id:=113 task_id:=1 target_lane:=1
```

参数：`task_id`（1=单圈，2=直道）、`target_lane`（1=FIRST 主路左，2=SECOND 主路右）、
`nominal_dt`（仅首拍 dt 用，默认 0.05）、`sink`（`log`/其他）、`log_path`。
全部先 declare 再 get。Ctrl-C 退出前自动发一条 `steer=1500, duty=0.0, source=estop`。

## 第一层自检（14）（全部实际执行通过）

```bash
# ① 语法检查
python3 -m py_compile ~/team4s/src/team4s_control/team4s_control/*.py ~/team4s/src/team4s_control/launch/*.py
# ② 附件零差异（基准目录 m1-改进v2/ 缺失，走哈希轨，见"待人工确认"）
cd ~/team4s/src/team4s_control/team4s_control && sha256sum contract.py adapter_v2.py m1_node_v2.py task_state_bridge.py
# ③ 冒烟测试（mock 最小面 = 外壳实际用到的符号；附件零 rclpy import）
python3 ~/team4s/src/team4s_control/test/test_smoke.py        # 15/15 项通过
# ④ 接口存在性抽查
grep -n "def on_snapshot\|def tick\|def publish_task_state\|def on_start_signal" \
  ~/team4s/src/team4s_control/team4s_control/m1_node_v2.py
```

## 第二层集成自检（15）（WSL Humble，全部实际执行通过）

前提：`ros2 interface show team4s_interfaces/msg/PerceptionSnapshot` 已确认字段名。

```bash
cd ~/team4s && source /opt/ros/humble/setup.bash && source install/setup.bash
ROS_DOMAIN_ID=113 ros2 run team4s_control m1_node --ros-args -p task_id:=1 -p target_lane:=1
```

**伪造 snapshot 流**（三路 health `state:1`=VALID、`max_age_s` 配置>0、meta `valid:true`、
`stamp_source:0`=STAMP_UNKNOWN 使静态消息不被判 stale；lane 给一个 `route_lane:1` 候选）：

```bash
ROS_DOMAIN_ID=113 ros2 topic pub -r 10 /team4s/perception/snapshot team4s_interfaces/msg/PerceptionSnapshot '{
  header: {stamp: {sec: 0, nanosec: 0}, frame_id: perception},
  aggregator_session_id: agg_smoke, run_id: t1_a1_smoke, sequence: 1,
  lane: {meta: {header: {stamp: {sec: 0, nanosec: 0}, frame_id: lane}, source_id: lane_src, source_session_id: s1, run_id: "", sequence: 1, stamp_source: 0, valid: true, reason: ""},
         image_width: 320, image_height: 240,
         candidates: [{candidate_id: c1, route_lane: 1, is_branch: false, left_visible: true, right_visible: true, center_valid: true, offset_px: 0.0, reference_y_px: 120, heading_valid: false, heading_rad: 0.0}],
         selected_candidate_id: "", offset_m_valid: false, offset_m: 0.0, metric_reason: "", calibration_id: "", metric_frame_id: "", metric_reference_x_m: 0.0, metric_reference_y_m: 0.0},
  lane_health: {state: 1, reason: "", age_known: true, age_s: 0.01, max_age_s: 0.5},
  obstacles: {meta: {header: {stamp: {sec: 0, nanosec: 0}, frame_id: obst}, source_id: obst_src, source_session_id: s2, run_id: "", sequence: 1, stamp_source: 0, valid: true, reason: ""},
              readings: [], left_clear_known: false, left_clear: false, right_clear_known: false, right_clear: false},
  obstacles_health: {state: 1, reason: "", age_known: true, age_s: 0.01, max_age_s: 0.5},
  scene: {meta: {header: {stamp: {sec: 0, nanosec: 0}, frame_id: scene}, source_id: scene_src, source_session_id: s3, run_id: "", sequence: 1, stamp_source: 0, valid: true, reason: ""},
          cone_valid: false, cone_state: 0, cone_bbox_known: false, cone_bbox_xyxy: [0,0,0,0],
          zebra_valid: false, zebra_visible: false, zebra_bbox_known: false, zebra_bbox_xyxy: [0,0,0,0],
          image_width: 320, image_height: 240, cone_event_id: 0, cone_event_stamp: {sec: 0, nanosec: 0},
          zebra_event_id: 0, zebra_event_stamp: {sec: 0, nanosec: 0}, zebra_event_confirmed: false,
          cones_valid: false, cones_reason: "", cones: [], green_start_visible: false,
          red_finish_visible: false, red_finish_confirmed: false, red_finish_event_id: 0,
          red_finish_event_stamp: {sec: 0, nanosec: 0}},
  scene_health: {state: 1, reason: "", age_known: true, age_s: 0.01, max_age_s: 0.5}
}'
```

**验收结果（本次实测）**：

| 项 | 结果 |
|---|---|
| `ros2 node list` | `/m1_control` 在 |
| `ros2 topic info -v` | RELIABLE + VOLATILE；History(Depth) 显示 UNKNOWN 为 Humble rmw 回读限制（默认 QoS 对照同样 UNKNOWN），KEEP_LAST/1 在代码显式声明 |
| `ros2 topic hz` | 约 7.4–8.3 Hz（机理与判定见 B 类-4） |
| `ros2 topic echo --once` | stamp 非 0、frame_id=base_link、sequence 严格递增、phase=IDLE |
| 起步话题 | `ros2 topic pub --once /team4s/control/start std_msgs/msg/Bool '{data: true}'` → phase 0→2（FOLLOW_LAP）、mode→AUTO，节点无异常 |
| Ctrl-C | CSV 有全程记录且尾行为 `1500,0.0000,estop`；日志无 traceback；同域重起 `ros2 node list` 仅一个 `/m1_control`（无幽灵节点） |

预期行为提醒：无 snapshot 时 phase 停 IDLE 但 task_state 仍按节流发（心跳不查新鲜度）；
空 lane 下发 start 仍停 IDLE（内核要求 lane.track_valid，零速铁律）；伪造流的
reason 里 `deg:run_id_mismatch`（伪造 run_id≠节点 run_id，warn 策略）与 `cones_invalid`
均为降级备注，不影响心跳与状态转移。

## 车端人工验收（部署到 Foxy 容器时执行）

同一套节点在 Foxy 容器、ROS_DOMAIN_ID=111 下重复上面「构建与运行」「验收」两步，
由真实感知 Aggregator 供数（不再伪造 snapshot 流）。重点复核：Foxy 下 `rclpy.ok()`
守护的退出路径（B 类-2）与 `seconds_nanoseconds()`（B 类-1）行为一致。

## 待人工确认

### A 类（硬不符）

无。（4）核对表 9 项全部 grep 验证一致，未触发停止。

### B 类（存疑但已按 Foxy 文档最佳理解实现，代码注释已标注）

1. **rclpy.time.Time 无 `.sec/.nanosec`**：文档 (6) 字面公式 `stamp.sec + stamp.nanosec*1e-9`
   在 Foxy/Humble 的 `rclpy.time.Time` 上会 AttributeError（那是消息类型字段）。
   已改用 `stamp.seconds_nanoseconds()`（两发行版均可用，语义相同）。位置：m1_node.py `_now()`。
2. **Humble 的 SIGINT 信号处理器会先关 default context**：finally 里无条件
   `rclpy.shutdown()` 在 Humble 抛 RCLError（Foxy 无此行为）。已用 `if rclpy.ok():`
   守护，两版均干净退出。位置：m1_node.py `main()`。
3. **`ros2 topic info -v` 的 History(Depth) 回读 UNKNOWN**：Humble rmw 的 QoS 回读限制
   （默认 QoS 的 `ros2 topic pub` 对照同样 UNKNOWN），非外壳问题；RELIABLE/VOLATILE
   回读正确，KEEP_LAST/depth=1 已由冒烟测试断言。
4. **task_state 实测 7.4–8.3 Hz（<10Hz 节流上限）**：0.05s timer × 0.1s offer 节流的
   量化产物（发拍间隔 0.10/0.15s 交替，均值≈0.125s）。按 (15) 已排查 timer 周期与
   QoS 端点均正确；offer() 在内核附件内（零改动约束不可改）。感知新鲜度阈值 0.5s，
   8Hz 心跳无超时风险。若车端要求严格 10Hz，需内核把 period_s 调小（如 0.09s）或
   timer 调快——属内核范畴，待全组拍板。
5. **launch API 取 Foxy 可用子集**：DeclareLaunchArgument / SetEnvironmentVariable /
   launch_ros Node + parameters，未用 Humble 专有语法。

### 其他记录

- **附件基准目录缺失**：仓库内 `m1-改进v2/` 不存在，按 (1) 双轨制改用 (9) 的
  SHA-256 哈希基线，四文件逐一比对全等，视为零差异（开工时与交付前各校一次）。
- **Python 3.8 注解纪律**：新文件 m1_node.py / chassis_sink.py / m1.launch.py /
  test_smoke.py 均加 `from __future__ import annotations`；未用 match；**未在任何
  位置使用 X | Y、dict[str, int] 等 3.9+ 新语法**（比"仅注解位置"的底线更保守）。
- **`colcon test` 模板 linter 未纳入 DoD**：flake8/pep257 的失败全部来自四附件既有
  风格（零改动约束不可修）与 m1_node.py 的 E402（任务书 (10) 强制的 sys.path
  bootstrap 副作用，附件同样存在）；新文件本身的 F401 已修掉。
