"""
Exercise 01_01 Python Bootcamp
"""

import os
import sys
from typing import Tuple

src_path = os.path.abspath(os.path.join(os.getcwd(), "..", "Ex00"))
sys.path.append(src_path)
from purse import *


def split_booty(
    *purses: Dict[str, int]
) -> Tuple[Dict[str, int], Dict[str, int], Dict[str, int]]:
    """
    Split the gold ingots across multiple purses.
    """
    total_gold_ingots: int = 0
    for purse in purses:
        if "gold_ingots" in purse and (
            not isinstance(purse["gold_ingots"], int) or purse["gold_ingots"] < 0
        ):
            raise ValueError(
                "The number of gold ingots must be a non-negative integer."
            )
        if "gold_ingots" in purse:
            total_gold_ingots += purse.get("gold_ingots")

    purse1: Dict[str, int] = {}
    purse2: Dict[str, int] = {}
    purse3: Dict[str, int] = {}

    for _ in range(total_gold_ingots):
        if purse1.get("gold_ingots", 0) <= purse2.get("gold_ingots", 0) and purse1.get(
            "gold_ingots", 0
        ) <= purse3.get("gold_ingots", 0):
            purse1 = add_ingot(purse1)
        elif purse2.get("gold_ingots", 0) <= purse3.get("gold_ingots", 0):
            purse2 = add_ingot(purse2)
        else:
            purse3 = add_ingot(purse3)

    return purse1, purse2, purse3
