# team4s M1 ROS 2 执行外壳

M1 决策内核（contract.py / adapter_v2.py / m1_without_ros2_node.py / task_state_bridge.py，外壳只读引用、运行时不改）
的 ROS 2 套壳：订阅感知聚合快照 → 驱动内核 → 发布 TaskState → 底盘命令经 ChassisSink 抽象落地；
底盘转速反馈经共享内存回读注入内核。

- 验证环境：WSL2 + ROS 2 Humble + Python 3.10
- 部署目标：车上容器 ROS 2 Foxy + Python 3.8.10（代码按 Foxy 文档写，见文末 B 类清单）
- 消息包：team4s_interfaces 0.2.0（未改动）
- 底盘 I/O：无 ROS 2 节点，双向共享内存（厂家脚本协议，见「底盘 I/O」节）
- 核心内核版本：2026-11-18（含 lint 整改 + 雷达不用适配，见「更新记录」）

## 文件清单

| 文件 | 说明 |
|---|---|
| `src/team4s_control/team4s_control/m1_node.py` | ROS 壳（本任务新写；节点名 m1_control）；含反馈线程调度、sink 选择、急停顺序 |
| `src/team4s_control/team4s_control/chassis_feedback.py` | 底盘转速反馈读取（读 `/dev/shm/2py_to_chassis.dat`）【11.18 新增】 |
| `src/team4s_control/team4s_control/chassis_sink.py` | 底盘输出抽象（NullSink / LogSink / SharedMemSink）【11.18 重写】 |
| `src/team4s_control/launch/m1.launch.py` | launch（ROS_DOMAIN_ID 参数化，默认 111） |
| `src/team4s_control/test/test_smoke.py` | 第一层自检③：无 ROS 冒烟测试 |
| `src/team4s_control/team4s_control/{contract,adapter_v2,m1_without_ros2_node,task_state_bridge}.py` | 四核心工作副本（**11.18 版**：lint 整改 + 雷达适配，与 m1-改进v2/ 基准一致；m1_node_v2.py 已改名 m1_without_ros2_node.py） |

另按（13）坑 5 补了 `package.xml` 的 `std_msgs` 依赖；`setup.py` 增加了
`m1_node` console_script 与 launch 安装。运行时产物：`m1_chassis_commands.csv`
（LogSink；`log_path` 可改，未传时落临时目录带时间戳并告警）。

## 构建与运行

```bash
cd ~/team4s
source /opt/ros/humble/setup.bash
colcon build --packages-select team4s_interfaces team4s_control
source install/setup.bash

# WSL 隔离域起节点（车上用 ROS_DOMAIN_ID=111）
# sink:=shm 走真实下发；不传默认 log（CSV 留证）
ROS_DOMAIN_ID=113 ros2 run team4s_control m1_node --ros-args \
  -p task_id:=1 -p target_lane:=1 -p sink:=shm

# 或 launch（domain_id 默认 111，WSL 传 113）
ros2 launch team4s_control m1.launch.py domain_id:=113 task_id:=1 target_lane:=1
```

参数（全部先 declare 再 get）：

| 参数 | 默认 | 说明 |
|---|---|---|
| `task_id` | — | 1=单圈，2=直道 |
| `target_lane` | — | 1=FIRST 主路左，2=SECOND 主路右 |
| `nominal_dt` | 0.05 | 仅首拍 dt 用 |
| `sink` | `log` | `log`=CSV 留证；`shm`=真实下发（`/dev/shm/servo_shared.dat`）；其他=NullSink |
| `log_path` | 空 | LogSink CSV 路径 |
| `cmd_shm` | `/dev/shm/servo_shared.dat` | 命令共享内存路径（`sink:=shm` 时生效） |
| `feedback_enabled` | `true` | 底盘反馈读取线程开关 |
| `feedback_shm` | `/dev/shm/2py_to_chassis.dat` | 反馈共享内存路径 |
| `feedback_hz` | 50 | 反馈读取限频（Hz） |

Ctrl-C 退出顺序：发 `steer=1500, duty=0.0, source=estop` → 停反馈线程 → `sink.close()`。

## 底盘 I/O（共享内存，11.18 接通）

底盘无 ROS 2 节点，双向共享内存，协议取自厂家脚本
`Python_4S_chassis_and_web_control_20260624V1.py`：

| 方向 | 文件 | 格式（native） | 锁 | 实现 |
|---|---|---|---|---|
| 回传 底盘→M1 | `/dev/shm/2py_to_chassis.dat` | `'f f f f H f f H f f B B i 4x'`（**52 字节**），字段 0 = `motor_rpm` | 读 `LOCK_SH\|LOCK_NB` | `chassis_feedback.py` |
| 下发 M1→底盘 | `/dev/shm/servo_shared.dat` | `'if'`（8 字节：int 舵机脉宽 + float 占空比） | 写 `LOCK_EX`（配对厂家读侧 LOCK_SH） | `chassis_sink.SharedMemSink` |

- 格式串必须与厂家一字不差，**native 字节序**（改小端会变 46 字节、全字段错位）。
- 厂家脚本只检测命令文件存在、不创建，首帧由 M1 侧初始化并 `chmod 0666`（安全初值 1500/0.0）。
- 反馈：后台线程限频读取 → 带锁槽位投递 → timer 单线程在 `tick()` **之前**调 `on_chassis()` 注入内核（tick 内才回填 ctx，放后面慢一拍）。
- 下发：`last_cmd` → `speed_to_duty()`（限幅 [0.0, 0.10]）→ `SharedMemSink.write()`；`source` 不落 SHM（厂家只读两值），仅留诊断。
- 读写失败只记日志不抛异常；截断帧自动重建；`close()` 幂等；失联保留内核最后速度不清零。

## 第一层自检（14）（全部实际执行通过）

```bash
# ① 语法检查（含 chassis_feedback.py）
python3 -m py_compile ~/team4s/src/team4s_control/team4s_control/*.py \
  ~/team4s/src/team4s_control/launch/*.py
# ② 核心副本同步校验（基准 m1-改进v2/ 的 11.18 版；沿用旧哈希基线需重新采集）
cd ~/team4s/src/team4s_control/team4s_control && \
  sha256sum contract.py adapter_v2.py m1_without_ros2_node.py task_state_bridge.py
# ③ 冒烟测试（mock 最小面 = 外壳实际用到的符号；核心零 rclpy import）
python3 ~/team4s/src/team4s_control/test/test_smoke.py
# ④ 接口存在性抽查
grep -n "def on_snapshot\|def tick\|def publish_task_state\|def on_start_signal" \
  ~/team4s/src/team4s_control/team4s_control/m1_without_ros2_node.py
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

**验收结果（11.17 实测）**&#8203;：

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

## 底盘 I/O 仿真验收（11.18，Windows 侧三轮×2 组，全部通过）

| 组 | 轮次 | 项数 | 验证内容 |
|---|---|---|---|
| 反馈 | ① 格式 | 9 | 厂家原样 struct 互通、native 52 字节、字段偏移、异常帧不抛错 |
| 反馈 | ② 线程 | 11 | 锁配对、并发写读、失联不崩、日志限频、close 幂等 |
| 反馈 | ③ 集成 | 9 | 注入时序（tick 前）、新帧覆盖、失联保值、enabled=False 不启线程、急停顺序 |
| 下发 | ① 协议 | 13 | 8 字节互通、厂家原样 `struct.unpack('if')` 验证、覆盖写不追加、三 sink 三参签名 |
| 下发 | ② 并发 | 9 | EX/SH/UN 配对、并发无撕裂、截断自动重建、close 幂等、LogSink 并发 101 行无交错 |
| 下发 | ③ 集成 | 6 | `sink=shm` 全链路、急停后 SHM 回中零速、`sink=log` 无回归 |

过程中共 5 次失败，经定位**均为仿真夹具缺陷**（float32 精度比较、假 fcntl 只计数不互斥、
合法帧集合遗漏预置帧等），产品代码核实无误后修夹具通过。最终 `flake8(99)` 0 错误、
`py_compile` OK、四核心回归 **61/61**、LF 换行保持。

## 车端人工验收（部署到 Foxy 容器时执行）

同一套节点在 Foxy 容器、ROS_DOMAIN_ID=111 下重复「构建与运行」「验收」两步，
由真实感知 Aggregator 供数（不再伪造 snapshot 流）。重点复核：

1. Foxy 下 `rclpy.ok()` 守护的退出路径（B 类-2）与 `seconds_nanoseconds()`（B 类-1）行为一致。
2. **反馈链路**：厂家脚本确实在写 `/dev/shm/2py_to_chassis.dat`；
   `python3 -c "import struct; print(struct.calcsize('f f f f H f f H f f B B i 4x'))"` 输出 **52**；
   节点日志无持续 `no valid feedback` 告警。
3. **下发链路**：`sink:=shm` 起车，`/dev/shm/servo_shared.dat` 被厂家脚本轮询生效；
   Ctrl-C 后该文件内容为中位+零速。
4. `/dev/shm` 权限允许 0666 创建与跨进程读写（注意 SELinux/AppArmor）。
5. 真实 `motor_rpm` 量级与 `RPM2VEL` 换算核对（R_EFF 未验收，velocity 仅供参考）。

## 2026-11-18 更新记录

### 1. 核心四文件 lint 整改（逻辑零改动）

- 实测 flake8 46 条、pydocstyle 约 57 项，分类处理：死代码删除（`hstate`、`V_CRUISE`、`g`）、
  格式修复（E501/E114/E221/E261/E302/E128）、E402 加 `# noqa: E402` 精确豁免
  （任务书 (10) 强制 sys.path bootstrap，结构保留）。
- pep257 的 52 条 D400 是「中文句号 `。` 不被英文 linter 识别」的误判，未改中文 docstring；
  ament_pep257 默认即忽略 D100–D107（缺 docstring 不算错）。
- 结果：`flake8(99)` **0 错误**、回归 **61/61**、diff 极小（adapter 6 / contract 51 /
  m1_node 13 / bridge 0 行）。原先「linter 失败零改动不可修」的结论**不成立**，已更正。
- 注：脚本曾把 LF 写成 CRLF 造成整文件 diff，已按字节恢复 LF。

### 2. 雷达不用适配（视觉兜底，默认关闭）

- 背景：感知组确认激光雷达不用；v2 消息唯一障碍源是 `ObstacleObservation`（雷达测距），
  视觉侧只有红/绿锥与斑马线，无通用障碍检测。
- 改动仅在适配层 + 状态机，**不碰 M3 控制律**（M3 仍占位）：
  - `AdapterCfg` 新增 `vision_obstacle_enabled`（默认 **False**）、`vision_obstacle_y2_trig=150`、
    `missing_optional_no_degrade=True`；`Extra` 新增 `obstacle_source` / `vision_obstacle_y2`；
  - `_adapt_obstacles` 增视觉兜底 `_vision_obstacle_fallback`（雷达不可用时从 cones[] 提取非终点锥）；
  - `health_verdict`：optional 流「从未配置且永久缺席」不再进 degraded——避免雷达永久缺失
    全程压 `V_SLOW=0.25`（比巡航慢 35%）吃掉用时附加分；「配置后失效（INVALID/STALE）」仍降速，不掩盖真故障；
  - TRACK↔AVOID 判据支持视觉像素行触发（与米制判据互斥，靠 `obstacle_source` 区分）。
- 终点隔离：排除绿起点锥；`red_finish_visible/confirmed` 为真时排除全部红锥；
  只置 `present`+行号，`dist` 保持 `NO_DETECTION`、`clear=None`，不伪造米值/可通行。
- 三轮迭代抓到 2 个真 bug 并修复：`COLOR_UNKNOWN` 未定义（F821）、`candidate_id` 是 string
  误用 `int()` 解析。12 项视觉仿真 + 健康分级 3 场景全过。
- **边界**：真绕障仍需 M3 队友实现（当前占位只减速不转向）；视觉兜底默认关闭，
  开启需感知组给出独立障碍锥语义、与终点锥可区分、实车绕行回归验证三条件同时满足。

### 3. 底盘反馈接线 + 命令下发接通（详见「底盘 I/O」节）

- 新增 `chassis_feedback.py`；重写 `chassis_sink.py`（加锁、幂等 close、`SharedMemSink`）；
  `m1_node.py` 增反馈线程调度、`sink:=shm`、`cmd_shm` 参数，急停顺序固化。
- 双向对称：回传 `2py_to_chassis.dat` → `on_chassis()`；下发 `last_cmd` → `servo_shared.dat`。
- 顺手修既有坏 import：改裸 `from m1_without_ros2_node import M1NodeV2, NodeCfg`
  （完整路径 install 后失效），10 行 E402 加精确豁免。

### 验证总览（11.18）

| 项目 | 结果 |
|---|---|
| flake8(99)（核心四文件 + 外壳三文件） | 0 错误 |
| 四核心回归 replay_check.py | 61/61 |
| py_compile / LF 换行 | 通过 / 保持 |
| 三轮仿真累计 | 反馈 29 + 下发 28 + 视觉 12 项，全过 |

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
4. **task_state 实测 7.4–8.3 Hz（<10Hz 节流上限）**&#8203;：0.05s timer × 0.1s offer 节流的
   量化产物（发拍间隔 0.10/0.15s 交替，均值≈0.125s）。按 (15) 已排查 timer 周期与
   QoS 端点均正确；offer() 在内核内（本轮 lint 整改未改其逻辑）。感知新鲜度阈值 0.5s，
   8Hz 心跳无超时风险。若车端要求严格 10Hz，需内核把 period_s 调小（如 0.09s）或
   timer 调快——属内核范畴，待全组拍板。
5. **launch API 取 Foxy 可用子集**：DeclareLaunchArgument / SetEnvironmentVariable /
   launch_ros Node + parameters，未用 Humble 专有语法。

### C 类（实车共享内存待核对，11.18 新增）

1. 车上实跑厂家脚本的 SHM 路径/格式是否与 handoff 版（20260624）一致；不一致用
   `cmd_shm` / `feedback_shm` 参数覆盖，不必改代码。
2. `struct.calcsize('f f f f H f f H f f B B i 4x')` 在车上 Python 是否为 **52**（native）。
3. `fcntl.flock` 在容器内行为正常；日志持续 `no valid feedback` 时先查路径与格式再查权限。
4. `/dev/shm` 允许 0666 创建、跨进程读写（厂家脚本用 `LOCK_SH` 读命令、`flock` 写反馈）。
5. `RPM2VEL` 的 `R_EFF` 未验收 → `velocity` 量级仅供参考；不影响零速铁律
  （命令由状态机决定，无速度闭环）。

## 其他记录

- **核心副本同步**：基准是 Windows 侧 `m1-改进v2/`（11.18 版）；包内四文件哈希应与基准一致
  （自检②）。原「仓库内 m1-改进v2/ 缺失走哈希轨」的旧基线已过期，需重新采集。
- **Python 3.8 注解纪律**：新文件 m1_node.py / chassis_feedback.py / chassis_sink.py /
  m1.launch.py / test_smoke.py 均加 `from __future__ import annotations`；未用 match；
  **未在任何位置使用 X | Y、dict[str, int] 等 3.9+ 新语法**（比"仅注解位置"的底线更保守）。
- **linter（11.18 更新）**&#8203;：核心四文件已整改完毕，`flake8(99)` **0 错误**（原「零改动不可修」
  结论作废）；E402 以 `# noqa: E402` 精确豁免（任务书 (10) 强制的 sys.path bootstrap 副作用，
  核心与外壳同此处理）。pep257 已在 `test/test_pep257.py` 用 `--add-ignore D400,D415,
  D213,D205,D209,D204,D403` 豁免（11.18 实测 220 条全属此类）：D400/D415 是中文句号「。」/「）」
  误判，不改中文 docstring；D213/D205/D209/D204/D403 是 docstring 版式，核心四文件需与
  Windows 基准 m1-改进v2/ 哈希一致（自检②），保持现状。colcon test 现全绿（flake8/pep257 过，
  copyright 按模板默认 skip）。壳层新文件 F401/F841 已清零。
