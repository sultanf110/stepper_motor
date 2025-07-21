from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
from setuptools.command.build_py import build_py as _build_py
import subprocess
import os

class BuildPyWithC(_build_py):
    def run(self):
        # Compile the C file into a shared object
        import os
        c_file = os.path.join('motorctrl', 'motorctrl.c')
        output_file = os.path.join('motorctrl', 'libmotorctrl.so')
        self.announce('Compiling motorctrl.c into libmotorctrl.so', level=3)
        self.spawn(['gcc', '-shared', '-fPIC', c_file, '-o', output_file, '-lwiringPi'])

        # Proceed with regular build_py
        super().run()

setup(
    name='motorctrl',
    version='0.1.0',
    description='Python wrapper for MotorCtrl C function',
    packages=['motorctrl'],
    cmdclass={'build_py': BuildPyWithC},
    include_package_data=True,
    zip_safe=False,
)
