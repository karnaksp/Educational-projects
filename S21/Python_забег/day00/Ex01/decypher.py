"""
Exercise 01_01 Python Bootcamp
"""

import sys
from typing import List

import importlib_resources as ir
from symspellpy.symspellpy import SymSpell


def decypher(msg: str) -> str:
    """
    Decyphers a message by extracting first letter
    of each word and joining them together.
    """
    words: List[str] = msg.split()
    result: str = "".join(word[0] for word in words)
    return result


def split_text(text: str) -> str:
    """
    Split text into words using word segmentation.
    """
    sym_spell = SymSpell(max_dictionary_edit_distance=2, prefix_length=7)
    dictionary_path = ir.files("symspellpy").joinpath(
        "frequency_dictionary_en_82_765.txt"
    )
    sym_spell.load_dictionary(
        str(dictionary_path),
        term_index=0,
        count_index=1)
    suggestions = sym_spell.word_segmentation(text)
    return suggestions.corrected_string


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print('Attribute error! Usage: python decypher.py "<message>"')
        sys.exit(1)
    message = sys.argv[1]
    if not message or not isinstance(message, str) or message.isdigit():
        print('Attribute error! Usage: python decypher.py "<message>" in quotes')
        sys.exit(1)
    DECODED_STR = decypher(message)
    split_message = split_text(DECODED_STR)
    print(split_message)
