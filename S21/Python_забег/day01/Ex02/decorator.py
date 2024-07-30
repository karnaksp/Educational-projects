"""
Exercise 01_02 Python Bootcamp
"""

import os
import sys
from typing import Any, Callable

src_path = os.path.abspath(os.path.join(os.getcwd(), "..", "Ex00"))
sys.path.append(src_path)
from purse import *


def squeaky_decorator(func: Callable[..., Any]) -> Callable[..., Any]:
    """
    Decorator that prints "SQUEAK" before calling the decorated function.
    """

    def wrapper(*args: Any, **kwargs: Any) -> Any:
        print("SQUEAK")
        return func(*args, **kwargs)

    return wrapper


empty = squeaky_decorator(empty)
add_ingot = squeaky_decorator(add_ingot)
get_ingot = squeaky_decorator(get_ingot)
