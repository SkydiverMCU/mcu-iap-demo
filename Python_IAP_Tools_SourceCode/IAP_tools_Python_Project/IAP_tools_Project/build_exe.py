try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

from Cython.Build import cythonize

setup(
    name='IAP Tools',
    ext_modules=cythonize(["IAP_tools.py", "IAP_tools_support.py", "Download.py"], language_level=3
        ),
)
