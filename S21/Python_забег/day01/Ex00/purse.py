"""
Exercise 00_01 Python Bootcamp
"""

from typing import Dict


def empty(purse: Dict[str, int]) -> Dict[str, int]:
    """
    Empty the purse.
    """
    return {}


def add_ingot(purse: Dict[str, int]) -> Dict[str, int]:
    """
    Add a gold ingot to the purse.
    """
    if "gold_ingots" in purse and (not isinstance(
            purse["gold_ingots"], int) or purse["gold_ingots"] < 0):
        raise ValueError(
            "The number of gold ingots must be a non-negative integer.")
    new_purse: Dict[str, int] = purse.copy()
    if "gold_ingots" in new_purse:
        new_purse["gold_ingots"] += 1
    else:
        new_purse["gold_ingots"] = 1
    return new_purse


def get_ingot(purse: Dict[str, int]) -> Dict[str, int]:
    """
    Get a gold ingot from the purse.
    """
    if "gold_ingots" in purse and (
        not isinstance(purse["gold_ingots"], int) or purse["gold_ingots"] < 0
    ):
        raise ValueError(
            "The number of gold ingots must be a non-negative integer.")
    new_purse: Dict[str, int] = purse.copy()
    if "gold_ingots" in new_purse and new_purse["gold_ingots"] > 0:
        new_purse["gold_ingots"] -= 1
        if new_purse["gold_ingots"] == 0:
            del new_purse["gold_ingots"]
    return new_purse
