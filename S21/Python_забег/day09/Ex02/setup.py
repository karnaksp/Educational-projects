from setuptools import setup
from Cython.Build import cythonize

setup(
    name="multiply",
    ext_modules=cythonize("multiply.pyx"),
    zip_safe=False,
)
