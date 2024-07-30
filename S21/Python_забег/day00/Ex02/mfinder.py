"""
Exercise 01_02 Python Bootcamp
"""

import sys
from typing import List


def read_file(filename: str) -> List[str]:
    """Reads the content of the file and returns it as a list of lines."""
    try:
        with open(filename, "r", encoding="utf8") as file:
            return [line.rstrip() for line in file]
    except IOError as e:
        raise RuntimeError("Error reading file.") from e


def is_valid_pattern(image: List[str]) -> bool:
    """
    Checks if the given image matches the M pattern and ensures
    that all other characters are not asterisks.
    """
    if len(image) != 3 or any(len(line) != 5 for line in image):
        raise ValueError("Invalid number of lines or incorrect line length")

    line1, line2, line3 = image

    pattern_match = (
        line1[0] == "*"
        and line1[4] == "*"
        and line2[0] == "*"
        and line2[1] == "*"
        and line2[3] == "*"
        and line2[4] == "*"
        and line3[0] == "*"
        and line3[2] == "*"
        and line3[4] == "*"
    )

    if not pattern_match:
        return False

    non_pattern_positions = [(0, 1), (0, 2), (0, 3), (1, 2), (2, 1), (2, 3)]

    for i, j in non_pattern_positions:
        if image[i][j] == "*":
            return False

    return True


def main() -> None:
    if len(sys.argv) != 2:
        raise AttributeError(
            "Invalid number of arguments! \nUsage: python mfinder.py <filename>"
        )

    filename = sys.argv[1]
    try:
        image = read_file(filename)
        try:
            if is_valid_pattern(image):
                print("True")
            else:
                print("False")
        except ValueError as e:
            print(f"Pattern Error: {e}")
    except RuntimeError as e:
        print(f"File Error: {e}")


if __name__ == "__main__":
    main()
