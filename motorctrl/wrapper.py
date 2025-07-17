import ctypes
import os
from pathlib import Path

# Load the shared library from the same directory as this file
lib_path = Path(__file__).with_name("libmotorctrl.so")
lib = ctypes.CDLL(str(lib_path))

# Set arg and return types
lib.MotorCtrl.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int, ctypes.c_int]
lib.MotorCtrl.restype = None

def call_motor_ctrl(motor_n, steps, lat, dir):
    lib.MotorCtrl(motor_n, steps, lat, dir)
