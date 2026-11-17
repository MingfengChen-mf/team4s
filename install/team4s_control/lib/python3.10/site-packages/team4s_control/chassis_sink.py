"""
chassis_sink.py —— 底盘输出抽象（M1 外壳 → 底盘的唯一出口）

职责边界（任务书 (11)）：
  · 全文唯一接口签名 write(steer, duty, source) —— 三参。timer 路径与 Ctrl-C 路径
    必须用同一个三参签名，不许两参调用。
  · steer 是舵机脉宽（contract.STEER_CENTER=1500 为中位），duty 是车速占空比
    （contract.speed_to_duty 已限幅到 [0.0, 0.10]），source 是诊断字符串。
  · 本文件不实现真实下发：候选入口是共享内存文件（厂家底盘脚本 50ms 轮询读取），
    协议细节联调时定（TODO 见文件尾）。这里不要写死任何串口协议或话题名——
    遥控器直连底盘，ROS 侧没有遥控/底盘命令话题。

Py3.8 兼容（Foxy 容器）：from future import annotations；新语法只允许出现在注解位置。
"""

from __future__ import annotations   # Py3.8 兼容：注解新语法降级为字符串（Foxy 容器 Py3.8）

import csv
import os
import time


class ChassisSink:
    """底盘输出抽象基类。全文唯一接口：write(steer, duty, source)。"""

    def write(self, steer: int, duty: float, source: str) -> None:
        raise NotImplementedError


class NullSink(ChassisSink):
    """只打日志，不落地。用于无底盘的联调 / dry-run。"""

    def __init__(self, logger=None):
        # logger：可选的日志回调（如 node.get_logger().info），为空则 print。
        self._logger = logger

    def write(self, steer: int, duty: float, source: str) -> None:
        line = 'chassis_sink steer=%d duty=%.4f source=%s' % (
            int(steer), float(duty), source)
        if self._logger is not None:
            self._logger(line)
        else:
            print(line, flush=True)


class LogSink(ChassisSink):
    """追加写 CSV：时间戳、steer、duty、source。每行立即 flush，Ctrl-C 后可查。"""

    def __init__(self, path: str = ''):
        self._path = path or os.path.join(os.getcwd(), 'm1_chassis_commands.csv')
        need_header = (not os.path.exists(self._path)) \
            or os.path.getsize(self._path) == 0
        self._f = open(self._path, 'a', newline='')
        self._w = csv.writer(self._f)
        if need_header:
            self._w.writerow(['wall_time', 'steer', 'duty', 'source'])
            self._f.flush()

    @property
    def path(self) -> str:
        return self._path

    def write(self, steer: int, duty: float, source: str) -> None:
        self._w.writerow(['%.6f' % time.time(), int(steer),
                          '%.4f' % float(duty), str(source)])
        self._f.flush()

    def close(self) -> None:
        try:
            self._f.close()
        except Exception:
            pass

    def __del__(self):
        # 兜底：进程异常退出时尽量关掉文件句柄（不影响已 flush 的 CSV 内容）。
        self.close()


# TODO(真实底盘出口，任务书 (11))：候选入口是共享内存文件——厂家底盘脚本 50ms 轮询
# 读取某个文件/内存区作为最新指令。协议细节（文件路径、行格式、锁机制）与底盘方
# 联调时共同确定后，在这里新增 SharedMemSink(ChassisSink) 并实现三参 write()。
# 不要写死串口协议或 ROS 话题名。
