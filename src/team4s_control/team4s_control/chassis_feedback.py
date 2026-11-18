"""chassis_feedback.py —— 底盘反馈共享内存读取（底盘 → M1 的唯一入口）。

数据来源（已核对厂家 handoff 脚本 20260624 版）：
  Python_4S_chassis_and_web_control_20260624V1.py
    SHM_FILE_FEEDBACK = "/dev/shm/2py_to_chassis.dat"
    DATA_FORMAT_FEEDBACK = 'f f f f H f f H f f B B i 4x'
  第 0 号字段 motor_rpm（float）即 M1 需要的原始转速；
  厂家写侧用 fcntl.flock(LOCK_EX)，本模块读侧用 LOCK_SH 配对。

⚠ 格式串必须一字不差：该串无字节序前缀，走 native 对齐，
  struct.calcsize() = 52；若改成 '<...' 小端会变 46 字节，字段全部错位。

边界（任务书 (7)(13)）：
  · 本模块只做"读字节 → 解析 rpm"，不碰内核、不调 on_chassis。
  · 线程把最新 rpm 放进带锁槽位；由 ROS timer 单线程取出后调 m1.on_chassis()。
    理由：Foxy 默认单线程 executor，所有内核调用必须串行，避免与 tick() 竞态。
  · 失联时不清零内核已存的速度（保留最后值比假报 0 更保守）。

Py3.8 兼容（Foxy 容器部署红线）。
"""
from __future__ import annotations

import os
import struct
import threading
import time

try:
    import fcntl
except ImportError:  # Windows 仿真环境无 fcntl；实车 Linux 必定存在
    fcntl = None

DEFAULT_FEEDBACK_PATH = '/dev/shm/2py_to_chassis.dat'
FEEDBACK_FORMAT = 'f f f f H f f H f f B B i 4x'
FEEDBACK_SIZE = struct.calcsize(FEEDBACK_FORMAT)   # native = 52，勿改小端
RPM_FIELD = 0                                      # motor_rpm
RPM_LIMIT = 10000.0                                # 明显越界视为无效帧


class FeedbackReader:
    """后台线程读底盘反馈共享内存，向 timer 线程投递最新 motor_rpm。"""

    def __init__(self, path: str = DEFAULT_FEEDBACK_PATH, hz: float = 20.0,
                 logger=None):
        self._path = path
        self._hz = float(hz)
        self._logger = logger
        self._lock = threading.Lock()
        self._stop = threading.Event()
        self._thread = None
        self._latest_rpm = None
        self._last_ok = 0.0
        self._last_log = 0.0

    @property
    def path(self) -> str:
        return self._path

    def _log(self, msg: str) -> None:
        """限频 1s：文件没接上时不要每 50ms 刷一条日志。"""
        now = time.monotonic()
        if now - self._last_log < 1.0:
            return
        self._last_log = now
        if self._logger is not None:
            self._logger(msg)
        else:
            print('[chassis_feedback] %s' % msg, flush=True)

    def read_once(self):
        """读一次共享内存，返回 motor_rpm；任何失败返回 None（不抛异常）。"""
        if not os.path.isfile(self._path):
            return None
        try:
            with open(self._path, 'rb') as f:
                locked = False
                if fcntl is not None:
                    try:
                        fcntl.flock(f.fileno(), fcntl.LOCK_SH | fcntl.LOCK_NB)
                        locked = True
                    except OSError:
                        locked = False   # 写侧正持锁，放弃本拍，等下一拍
                try:
                    data = f.read(FEEDBACK_SIZE)
                finally:
                    if locked:
                        fcntl.flock(f.fileno(), fcntl.LOCK_UN)
            if len(data) != FEEDBACK_SIZE:
                return None
            rpm = float(struct.unpack(FEEDBACK_FORMAT, data)[RPM_FIELD])
            if not (-RPM_LIMIT <= rpm <= RPM_LIMIT):
                return None
            return rpm
        except (OSError, struct.error, ValueError, TypeError):
            return None

    def take_rpm(self):
        """timer 单线程调用：取走待注入的转速并清空槽位（避免重复注入）。"""
        with self._lock:
            rpm = self._latest_rpm
            self._latest_rpm = None
        return rpm

    def start(self) -> None:
        """启动后台读线程；重复调用无副作用。"""
        if self._thread is not None:
            return
        self._stop.clear()
        self._thread = threading.Thread(
            target=self._run, name='chassis-feedback', daemon=True)
        self._thread.start()

    def _run(self) -> None:
        period = 1.0 / max(1.0, self._hz)
        while not self._stop.is_set():
            rpm = self.read_once()
            if rpm is None:
                self._log('no valid feedback at %s' % self._path)
            else:
                with self._lock:
                    self._latest_rpm = rpm
                self._last_ok = time.monotonic()
            self._stop.wait(period)

    def close(self) -> None:
        """停止线程（幂等）；join 有超时，不阻塞退出流程。"""
        self._stop.set()
        t = self._thread
        if t is not None and t.is_alive():
            t.join(timeout=1.0)
        self._thread = None


def write_feedback_frame(path: str, motor_rpm: float, **kwargs) -> None:
    """仅用于仿真/联调注入：按厂家 native 格式写一帧反馈。

    实车禁止调用——真实数据来源是厂家底盘脚本写 UART 读到的转速。
    """
    values = [0.0, 0.0, 0.0, 0.0, 1500, 0.0, 0.0, 1500, 0.0, 0.0, 0, 0, 0]
    values[RPM_FIELD] = float(motor_rpm)
    if 'encoder_rpm' in kwargs:
        values[11] = int(kwargs['encoder_rpm'])
    parent = os.path.dirname(os.path.abspath(path))
    if parent and not os.path.isdir(parent):
        os.makedirs(parent, exist_ok=True)
    with open(path, 'wb') as f:
        f.write(struct.pack(FEEDBACK_FORMAT, *values))
