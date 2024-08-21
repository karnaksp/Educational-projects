"""
Testes for check input
"""

import os
import sys
import pytest

src_path = os.path.abspath(os.path.join(os.getcwd(), "..", "Ex00"))
sys.path.append(src_path)
from check_input import *


@pytest.fixture
def mock_input(monkeypatch):
    """
    A fixture function that generates a mock input function for testing purposes.
    """

    def _mock_input(input_value):
        """
        A private helper function that
        generates a mock input function for testing purposes.
        """
        monkeypatch.setattr("builtins.input", lambda _: input_value)

    return _mock_input


@pytest.fixture
def mock_input_sequence(monkeypatch):
    """
    A fixture function that generates a mock input sequence function for testing purposes.
    """

    def _mock_input_sequence(inputs):
        """
        A private helper function that
        generates a mock input sequence function for testing purposes.
        """
        input_iter = iter(inputs)
        monkeypatch.setattr("builtins.input", lambda _: next(input_iter))

    return _mock_input_sequence


def test_get_int_input_valid(mock_input, capsys):
    mock_input("5")
    result = get_int_input("Enter a number", 1, 10)
    assert result == 5
    captured = capsys.readouterr()
    assert captured.out == ""


def test_get_int_input_below_min(mock_input_sequence, capsys):
    mock_input_sequence(["-1", "5"])
    result = get_int_input("Enter a number", 1, 10)
    captured = capsys.readouterr()
    assert result == 5
    assert "!!! Value must be between 1 and 10." in captured.out


def test_get_int_input_above_max(mock_input_sequence, capsys):
    mock_input_sequence(["11", "1"])
    result = get_int_input("Enter a number", 1, 10)
    captured = capsys.readouterr()
    assert result == 1
    assert "Value must be between 1 and 10." in captured.out


def test_get_int_input_invalid_type(mock_input_sequence, capsys):
    mock_input_sequence(["abc", "1"])
    result = get_int_input("Enter a number", 1, 10)
    captured = capsys.readouterr()
    assert result == 1
    assert "Invalid input. Please enter an integer." in captured.out


def test_get_user_input_valid(mock_input_sequence, capsys):
    mock_input_sequence(["0", "10", "60", "3", "5"])
    answers = ["Yes", "No"]
    result = get_user_input(answers)
    assert result == (0, 10, 60, 3, 5)
    captured = capsys.readouterr()
    assert captured.out == ""


def test_get_user_input_invalid_answer_index(mock_input_sequence, capsys):
    mock_input_sequence(["3", "0", "10", "60", "3", "5"])
    answers = ["Yes", "No"]

    result = get_user_input(answers)
    captured = capsys.readouterr()
    assert result == (0, 10, 60, 3, 5)
    assert "Invalid index. Please choose between 0 and 1." in captured.out
