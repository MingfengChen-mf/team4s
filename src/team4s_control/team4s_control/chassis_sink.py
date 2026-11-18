"""chassis_sink.py —— 底盘输出抽象（M1 外壳 → 底盘的唯一出口）。

职责边界（任务书 (11)）：
  · 全文唯一接口签名 write(steer, duty, source) —— 三参。timer 路径与 Ctrl-C 路径
    必须用同一个三参签名，不许两参调用。
  · steer 是舵机脉宽（contract.STEER_CENTER=1500 为中位），duty 是车速占空比
    （contract.speed_to_duty 已限幅到 [0.0, 0.10]），source 是诊断字符串。
  · NullSink / LogSink 用于无底盘联调留证；SharedMemSink 是真实下发出口：
    厂家底盘脚本 command_listener() 50ms 轮询读 /dev/shm/servo_shared.dat，
    格式为 native 'if'（i 舵机脉宽, f 占空比），读侧 LOCK_SH，本模块写侧 LOCK_EX。
  · source 不写进 SHM（厂家只读 2 个值），仅保留在接口里做诊断，不丢签名。

Py3.8 兼容（Foxy 容器）：from future import annotations；新语法只允许出现在注解位置。
"""
from __future__ import annotations

import csv
import os
import struct
import tempfile
import threading
import time

try:
    import fcntl
except ImportError:  # Windows 仿真环境无 fcntl；实车 Linux 必定存在
    fcntl = None

DEFAULT_CMD_PATH = '/dev/shm/servo_shared.dat'
CMD_FORMAT = 'if'                              # 与厂家脚本 DATA_FORMAT_CMD 一字不差
CMD_SIZE = struct.calcsize(CMD_FORMAT)         # native = 8
CMD_INIT_STEER = 1500                          # 中位
CMD_INIT_DUTY = 0.0                            # 零速


class ChassisSink:
    """底盘输出抽象基类。全文唯一接口：write(steer, duty, source)。"""

    def write(self, steer: int, duty: float, source: str) -> None:
        raise NotImplementedError

    def close(self) -> None:
        """统一关闭契约，子类覆盖且必须幂等。"""
        return None


class NullSink(ChassisSink):
    """只打日志，不落地。用于无底盘的联调 / dry-run。"""

    def __init__(self, logger=None):
        self._logger = logger
        self._lock = threading.Lock()

    def write(self, steer: int, duty: float, source: str) -> None:
        line = 'chassis_sink steer=%d duty=%.4f source=%s' % (
            int(steer), float(duty), source)
        with self._lock:
            if self._logger is not None:
                self._logger(line)
            else:
                print(line, flush=True)


class LogSink(ChassisSink):
    """追加写 CSV：时间戳、steer、duty、source。每行立即 flush。"""

    def __init__(self, path: str = ''):
        if not path:
            path = os.path.join(
                tempfile.gettempdir(),
                'm1_chassis_commands_%s.csv' % time.strftime('%Y%m%d_%H%M%S'))
            print('[chassis_sink] WARNING: no explicit path, fallback to %s'
                  % path, flush=True)
        self._path = os.path.abspath(path)
        parent = os.path.dirname(self._path)
        if parent and not os.path.isdir(parent):
            os.makedirs(parent, exist_ok=True)
        need_header = (not os.path.exists(self._path)) \
            or os.path.getsize(self._path) == 0
        self._lock = threading.Lock()
        self._closed = False
        self._f = open(self._path, 'a', newline='')
        self._w = csv.writer(self._f)
        if need_header:
            self._w.writerow(['wall_time', 'steer', 'duty', 'source'])
            self._f.flush()

    @property
    def path(self) -> str:
        return self._path

    def write(self, steer: int, duty: float, source: str) -> None:
        with self._lock:
            if self._closed:
                return
            self._w.writerow(['%.6f' % time.time(), int(steer),
                              '%.4f' % float(duty), str(source)])
            self._f.flush()

    def close(self) -> None:
        with self._lock:
            if self._closed:
                return
            self._closed = True
            try:
                self._f.close()
            except Exception:
                pass

    def __del__(self):
        try:
            self.close()
        except Exception:
            pass


class SharedMemSink(ChassisSink):
    """真实下发出口：写厂家脚本轮询的命令共享内存。

    协议来自厂家 handoff 脚本 20260624 版：
      SHM_FILE_CMD    = "/dev/shm/servo_shared.dat"
      DATA_FORMAT_CMD = 'if'   (i 舵机脉宽 int, f 电机占空比 float)
    厂家 command_listener() 用 LOCK_SH 读，本类用 LOCK_EX 写，必须配对。
    厂家脚本只检测文件存在、不创建，因此首帧由本类初始化并 chmod 0666。
    """

    def __init__(self, path: str = DEFAULT_CMD_PATH, logger=None):
        self._path = path
        self._logger = logger
        self._closed = False
        parent = os.path.dirname(os.path.abspath(path))
        if parent and not os.path.isdir(parent):
            os.makedirs(parent, exist_ok=True)
        if not os.path.exists(path) or os.path.getsize(path) < CMD_SIZE:
            with open(path, 'wb') as f:
                f.write(struct.pack(CMD_FORMAT, CMD_INIT_STEER, CMD_INIT_DUTY))
            try:
                os.chmod(path, 0o666)
            except OSError:
                pass

    @property
    def path(self) -> str:
        return self._path

    def _log(self, msg: str) -> None:
        if self._logger is not None:
            self._logger(msg)

    def write(self, steer: int, duty: float, source: str) -> None:
        """三参写入；source 不落 SHM（厂家只读两值），仅透传给日志。"""
        if self._closed:
            return
        frame = struct.pack(CMD_FORMAT, int(steer), float(duty))
        try:
            with open(self._path, 'r+b') as f:
                locked = False
                if fcntl is not None:
                    try:
                        fcntl.flock(f.fileno(), fcntl.LOCK_EX)
                        locked = True
                    except OSError:
                        pass
                try:
                    f.seek(0)
                    f.write(frame)
                    f.flush()
                finally:
                    if locked:
                        fcntl.flock(f.fileno(), fcntl.LOCK_UN)
        except (OSError, struct.error) as exc:
            self._log('[chassis_sink] write failed: %s' % exc)

    def close(self) -> None:
        """幂等关闭；SHM 是裸文件，无需持有句柄，仅置关闭标志。"""
        self._closed = True
