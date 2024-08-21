from setuptools import setup, Extension

module1 = Extension("calculator", sources=["calculator.c", "int_operation.c"])

setup(
    name="CalculatorModule",
    version="1.0",
    description="A simple calculator module for int",
    ext_modules=[module1],
)
