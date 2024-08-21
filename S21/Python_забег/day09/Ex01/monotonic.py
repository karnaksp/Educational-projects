import ctypes

CLOCK_MONOTONIC = 1


class Timespec(ctypes.Structure):
    _fields_ = [("tv_sec", ctypes.c_long), ("tv_nsec", ctypes.c_long)]


def monotonic():
    ts = Timespec()
    libc = ctypes.CDLL(None)
    clock_gettime = libc.clock_gettime
    clock_gettime.argtypes = [ctypes.c_int, ctypes.POINTER(Timespec)]
    clock_gettime.restype = ctypes.c_int
    if clock_gettime(CLOCK_MONOTONIC, ctypes.byref(ts)) != 0:
        raise OSError("Unable to get monotonic time")

    return ts.tv_sec + ts.tv_nsec / 1e9


if __name__ == "__main__":
    print("Monotonic time:", monotonic(), "seconds")
