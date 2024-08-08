import json
from typing import Callable, List, Tuple, Optional


class VoightKampffTester:
    """
    Class to conduct the Voight-Kampff test to determine
    if a respondent is a human or a replicant.
    """

    def __init__(self, path: str, min_questions: int = 5):
        """
        Initialize the Voight-Kampff tester with questions from a JSON file.

        Args:
            path (str): Path to the JSON file containing the questions.
            min_questions (int): Minimum number of questions that must be answered.
        """
        with open(path, "r") as f:
            self.questions = json.load(f)
        self.current_index = 0
        self.responses = [None] * len(self.questions)
        self.min_questions = min(min_questions, len(self.questions))

    def __iter__(self):
        return self

    def __next__(self) -> Tuple[str, List[str], Callable]:
        """
        Provides the next question and a callback function for handling responses.

        Returns:
            Tuple[str, List[str], Callable]: A tuple containing the question,
            list of possible answers, and a callback function.

        Raises:
            StopIteration: When there are no more questions.
        """
        if self.current_index < len(self.questions):
            question_data = self.questions[self.current_index]
            question_text = question_data["question"]
            answers = question_data["answers"]
            eval_scores = question_data["eval"]

            def callback(
                answer_index: int,
                respiration: int,
                heart_rate: int,
                blushing: int,
                pupil_diameter: int,
            ) -> Optional[str]:
                """
                Record the response data.

                Args:
                    answer_index (int): Index of the chosen answer.
                    respiration (int): Respiration rate in BPM.
                    heart_rate (int): Heart rate in BPM.
                    blushing (int): Blushing level (1-6).
                    pupil_diameter (int): Pupillary dilation in mm.
                """
                self.responses[self.current_index] = (
                    answer_index,
                    respiration,
                    heart_rate,
                    blushing,
                    pupil_diameter,
                )
                return None

            self.current_index += 1
            return question_text, answers, callback
        else:
            raise StopIteration("No more questions available.")

    def evaluate(self) -> bool:
        """
        Evaluate the test results to determine if the respondent is a human or a replicant.

        Returns:
            bool: True if the respondent is determined to be a human, False if a replicant.

        Raises:
            ValueError: If fewer than the minimum number of questions have been answered.
        """
        answered_count = sum(1 for response in self.responses if response is not None)
        if answered_count < self.min_questions:
            raise ValueError(
                f"Not enough questions answered. Minimum required: {self.min_questions}, answered: {answered_count}."
            )

        total_points = sum(
            self.questions[i]["eval"][response[0]]
            for i, response in enumerate(self.responses)
            if response is not None
        )
        total_respiration = sum(
            response[1] for response in self.responses if response is not None
        )
        total_heart_rate = sum(
            response[2] for response in self.responses if response is not None
        )
        total_blushing = sum(
            response[3] for response in self.responses if response is not None
        )
        total_pupil_diameter = sum(
            response[4] for response in self.responses if response is not None
        )

        score = (
            1 * total_points
            + 0.3 * total_respiration
            + 0.5 * total_heart_rate
            + 0.3 * total_blushing
            + 1 * total_pupil_diameter
        ) / answered_count

        return score > 53
