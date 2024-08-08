"""

"""


def get_int_input(prompt: str, min_value: int, max_value: int) -> int:
    """
    Get an integer input from the user with validation.

    Args:
        prompt (str): The input prompt message.
        min_value (int): The minimum acceptable value.
        max_value (int): The maximum acceptable value.

    Returns:
        int: The validated integer input from the user.
    """
    while True:
        try:
            value = int(input(prompt))
            if min_value <= value <= max_value:
                return value
            else:
                print(f"\n!!! Value must be between {min_value} and {max_value}.\n")
        except ValueError:
            print("\nInvalid input. Please enter an integer.\n")


def get_user_input(answers: list) -> tuple[int, int, int, int, int]:
    """
    Collect and validate user inputs for the test.

    Args:
        answers (list): List of possible answers for the current question.

    Returns:
        tuple: Validated inputs (answer_index, respiration, heart_rate, blushing, pupil_diameter)
    """
    while True:
        try:
            answer_index = int(input("Select an answer (index): "))
            if 0 <= answer_index < len(answers):
                break
            else:
                print(
                    f"\nInvalid index. Please choose between 0 and {len(answers) - 1}.\n"
                )
        except ValueError:
            print("Invalid input. Please enter an integer.")

    respiration = get_int_input("Enter respiration rate (BPM, 2-30): ", 2, 30)
    heart_rate = get_int_input("Enter heart rate (BPM, 30-150): ", 30, 150)
    blushing = get_int_input("Enter blushing level (1-6): ", 1, 6)
    pupil_diameter = get_int_input("Enter pupillary dilation (mm, 2-8): ", 2, 8)

    return answer_index, respiration, heart_rate, blushing, pupil_diameter
