from setuptools import setup, Extension

module1 = Extension("calculator", sources=["calculator.c", "float_operation.c"])

setup(
    name="CalculatorModule",
    version="1.0",
    description="A simple calculator module for float",
    ext_modules=[module1],
)
