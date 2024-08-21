"""
Simulate user behavior
"""

import subprocess
import random
import time
import json


def load_questions(filename: str) -> list[dict[str, list | int]]:
    """
    Load questions from the JSON file.
    """
    with open(filename, "r") as file:
        return json.load(file)


def simulate_user_input(questions):
    """
    Generate simulated user inputs as a single string with questions and answers.
    """
    inputs = []
    question_count = len(questions)

    for i in range(question_count):
        inner_inputs = []
        question = questions[i]["question"]
        prompt = [
            question,
            "Enter respiration rate (BPM, 2-30): ",
            "Enter heart rate (BPM, 30-150): ",
            "Enter blushing level (1-6): ",
            "Enter pupillary dilation (mm, 2-8): ",
        ]
        answer_index = random.randint(0, 2)
        respiration = random.randint(2, 30)
        heart_rate = random.randint(30, 150)
        blushing = random.randint(1, 6)
        pupil_dilation = random.randint(2, 8)

        inner_inputs.append(f"{answer_index}\n")
        inner_inputs.append(f"{respiration}\n")
        inner_inputs.append(f"{heart_rate}\n")
        inner_inputs.append(f"{blushing}\n")
        inner_inputs.append(f"{pupil_dilation}\n")

        for j, input_str in enumerate(inner_inputs):
            print(prompt[j])
            time.sleep(0.1)
            print(input_str)
        inputs.extend(inner_inputs)
    return "".join(inputs)


def run_test_with_simulation(questions):
    """
    Runs a simulation test with the given questions.

    Args:
        questions (list): A list of dictionaries representing the questions.
            Each dictionary should have a "question" key with the question text.

    Returns:
        None
    """
    user_inputs = simulate_user_input(questions)
    process = subprocess.Popen(
        ["python", "main.py"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    stdout, stderr = process.communicate(input=user_inputs)
    if stderr:
        print(stderr)
    if stdout:
        for line in stdout.splitlines():
            if "Decision:" in line:
                print("Decision:", line.split("Decision:")[1].strip())


if __name__ == "__main__":
    question_path = "questions.json"
    questions = load_questions(question_path)
    run_test_with_simulation(questions)
