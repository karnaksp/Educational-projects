"""
Exercise 02_00 Python Bootcamp
"""

from typing import Any


class Key:
    def __init__(self) -> None:
        self.passphrase: str = "zax2rulez"

    def __len__(self) -> int:
        return 1337

    def __getitem__(self, index: int) -> int:
        if index == 404:
            return 3
        raise IndexError("None type of index")

    def __gt__(self, other: Any) -> bool:
        return 9000 <= other if isinstance(other, int) else NotImplemented

    def __str__(self) -> str:
        return "GeneralTsoKeycard"
