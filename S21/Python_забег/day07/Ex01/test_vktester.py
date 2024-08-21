"""
Testes for check VK-test class
"""

import os
import sys
import json
import pytest

src_path = os.path.abspath(os.path.join(os.getcwd(), "..", "Ex00"))
sys.path.append(src_path)
from voit_kampf_test import VoightKampffTester


def test_initialization_valid_file(tmp_path):
    """Test the initialization with a valid file."""
    json_data = [{"question": "Test?", "answers": ["Yes", "No"], "eval": [10, 0]}]
    file = tmp_path / "questions.json"
    file.write_text(json.dumps(json_data))
    tester = VoightKampffTester(str(file))
    assert len(tester.questions) == 1


def test_initialization_empty_file(tmp_path):
    """Test initialization with an empty JSON file."""
    file = tmp_path / "questions_0.json"
    file.write_text("")
    with pytest.raises(ValueError, match="The file is empty."):
        VoightKampffTester(str(file))


def test_initialization_invalid_json(tmp_path):
    """Test initialization with a file containing invalid JSON."""
    file = tmp_path / "questions.json"
    file.write_text("{not a json}")
    with pytest.raises(ValueError, match="The file does not contain valid JSON."):
        VoightKampffTester(str(file))


def test_initialization_not_list(tmp_path):
    """Test initialization with a JSON file that does not contain a list."""
    file = tmp_path / "questions.json"
    file.write_text(json.dumps({"question": "What is your name?"}))
    with pytest.raises(
        ValueError, match="The file does not contain a valid list of questions."
    ):
        VoightKampffTester(str(file))


def test_initialization_less_than_min_questions(tmp_path):
    """Test the initialization of the VoightKampffTester with less than min questions."""
    json_data = [{"question": "Test?", "answers": ["Yes", "No"], "eval": [10, 0]}]
    file = tmp_path / "questions.json"
    file.write_text(json.dumps(json_data))
    tester = VoightKampffTester(str(file), min_questions=5)
    assert tester.min_questions == 1


def test_iteration_and_callback(tmp_path):
    """Tests the iteration and callback functionality of the VoightKampffTester class."""
    json_data = [{"question": "Test?", "answers": ["Yes", "No"], "eval": [10, 0]}]
    file = tmp_path / "questions.json"
    file.write_text(json.dumps(json_data))
    tester = VoightKampffTester(str(file))

    question, answers, callback = next(tester)
    assert question == "Test?"
    assert answers == ["Yes", "No"]

    callback(0, 10, 60, 3, 5)
    assert tester.responses[0] == (0, 10, 60, 3, 5)


def test_evaluation_human(tmp_path):
    """Tests the evaluation functionality of the VoightKampffTester class."""
    json_data = [{"question": "Test?", "answers": ["Yes", "No"], "eval": [10, 0]}]
    file = tmp_path / "questions.json"
    file.write_text(json.dumps(json_data))
    tester = VoightKampffTester(str(file))

    _, _, callback = next(tester)
    callback(0, 10, 60, 3, 5)

    assert isinstance(tester.evaluate(), bool)


def test_evaluation_not_enough_answers(tmp_path):
    """Tests the evaluation functionality when there are not enough answers."""
    json_data = [{"question": "Test?", "answers": ["Yes", "No"], "eval": [10, 0]}]
    file = tmp_path / "questions.json"
    file.write_text(json.dumps(json_data))
    tester = VoightKampffTester(str(file), min_questions=2)

    with pytest.raises(ValueError):
        tester.evaluate()
