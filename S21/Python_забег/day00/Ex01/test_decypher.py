import pytest
from decypher import decypher


def test_decypher_regular_sentence():
    message = "Have you delivered eggplant pizza at restored keep"
    assert decypher(message) == "Hydepark"


def test_decypher_with_punctuation():
    message = "Quick, bring me a xylophone!"
    assert decypher(message) == "Qbmax"


def test_decypher_with_numbers():
    message = "1 apple a day keeps 2 doctors away"
    assert decypher(message) == "1aadk2da"


def test_decypher_single_word():
    message = "Hello"
    assert decypher(message) == "H"


def test_decypher_empty_string():
    message = ""
    assert decypher(message) == ""


def test_decypher_mixed_case():
    message = "United States of America"
    assert decypher(message) == "USoA"


if __name__ == "__main__":
    pytest.main()
