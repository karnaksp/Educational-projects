"""
main function to start V-K test
"""

from check_input import get_user_input
from voit_kampf_test import VoightKampffTester


def main():
    """
    The main function to start the Voight-Kampff test.

    It initializes the test with a set of questions from a JSON file,
    iterates over the questions, and gets user input for each question.
    The user's answers are then evaluated to determine whether they are human or a replicant.
    """
    json_path = "questions.json"
    tester = VoightKampffTester(json_path)
    for question, answers, callback in tester:
        print(question)
        for idx, answer in enumerate(answers):
            print(f"{idx}: {answer}")

        answer_index, respiration, heart_rate, blushing, pupil_diameter = (
            get_user_input(answers)
        )

        error = callback(
            answer_index, respiration, heart_rate, blushing, pupil_diameter
        )
        if error:
            print(f"Error: {error}")

    try:
        result = tester.evaluate()
        print(f"Decision: {'Human' if result else 'Replicant'}")
    except ValueError as e:
        print(f"Evaluation error: {e}")


if __name__ == "__main__":
    main()
