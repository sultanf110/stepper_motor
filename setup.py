from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import subprocess
import os

class BuildExtWithC(build_ext):
    def run(self):
        # Compile the C file into a shared object
        c_file = os.path.join('motorctrl', 'motorctrl.c')
        output_file = os.path.join('motorctrl', 'libmotorctrl.so')
        subprocess.check_call(['gcc', '-shared', '-fPIC', c_file, '-o', output_file])
        super().run()

setup(
    name='motorctrl',
    version='0.1.0',
    description='Python wrapper for MotorCtrl C function',
    packages=['motorctrl'],
    cmdclass={'build_ext': BuildExtWithC},
    include_package_data=True,
    zip_safe=False,
)
