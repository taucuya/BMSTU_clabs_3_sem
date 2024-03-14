import ctypes
from typing import List

lib = ctypes.CDLL("../lib/lib.so")

_arr_fib = lib.fib
_arr_fib.argtypes = (
    ctypes.POINTER(ctypes.c_int),
    ctypes.c_int,
)

_entry = lib.first_entry
_entry.argtypes = (
    ctypes.POINTER(ctypes.c_int),
    ctypes.c_int,
    ctypes.POINTER(ctypes.c_int),
    ctypes.POINTER(ctypes.c_int),
)
_entry.restype = ctypes.c_int


def fib(n: int) -> List[int]:
    buffer = (ctypes.c_int * n)()
    _arr_fib(buffer, n)
    return list(buffer)

def first_entry_dcall(arr):
    buf_size = ctypes.c_int(0)
    arr_ptr = (ctypes.c_int * len(arr))(*arr)

    ec = _entry(arr_ptr, len(arr), None, buf_size)

    buffer = (ctypes.c_int * buf_size.value)()

    ec = _entry(arr_ptr, len(arr), buffer, buf_size)

    return list(buffer)


def first_entry_prealloc(arr):
    buf_size = ctypes.c_int(0)
    arr_ptr = (ctypes.c_int * len(arr))(*arr)

   # ec = filter_firsts(arr_ptr, len(arr), None, buf_size)

    buffer = (ctypes.c_int *len(arr))()

    ec = _entry(arr_ptr, len(arr), buffer, buf_size)

    return list(buffer)