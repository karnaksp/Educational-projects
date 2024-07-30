"""
Exercise 01_00 Python Bootcamp
"""

import sys
from sys import stdin

NUM_THRESHOLD = 32


def blocks() -> list:
    """
    Reads lines from standard input and returns a list of
    valid lines that meet the following criteria:

    Returns:
        list: A list of valid lines.

    Raises:
        AttributeError: If the number of command line arguments is not equal to 2.
        ValueError: If the command line argument cannot be converted to an integer.
    """
    if len(sys.argv) != 2:
        print("Usage: python3 blocks.py <number of lines>")
        raise AttributeError("Invalid number of arguments")

    try:
        num_lines = int(sys.argv[1])
    except ValueError as exc:
        print("Please provide a valid number for <number of lines>")
        raise ValueError("Invalid number of lines argument") from exc

    valid_lines = []
    count_lines = 0

    for line in stdin:
        line = line.strip()
        if len(line) != NUM_THRESHOLD:
            continue
        if line.startswith("00000") and not line.startswith("000000"):
            valid_lines.append(line)
            count_lines = 1
        if count_lines >= num_lines:
            break

    for line in valid_lines:
        print(line)

    return valid_lines


if __name__ == "__main__":
    try:
        _ = blocks()
    except AttributeError as e:
        print(f"Error: {e}")
    except ValueError as e:
        print(f"Error: {e}")
