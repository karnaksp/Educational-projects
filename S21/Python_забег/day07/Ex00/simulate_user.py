import subprocess
import random
import time
import json


def load_questions(filename: str):
    with open(filename, "r") as file:
        return json.load(file)


def simulate_user_input(question_count: int, questions):
    """
    Generate simulated user inputs as a single string with questions and answers.
    """
    inputs = []

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


def run_test_with_simulation(question_count: int, questions):
    user_inputs = simulate_user_input(question_count, questions)
    process = subprocess.Popen(
        ["python3", "main.py"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True,
    )
    _, stderr = process.communicate(input=user_inputs)
    # print(stdout)
    if stderr:
        print(stderr)


if __name__ == "__main__":
    question_count = 10
    question_path = "questions.json"
    run_test_with_simulation(question_count, load_questions(question_path))
