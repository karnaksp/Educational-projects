"""Tester - module, conducting testing

Typical usage example:
    tester = Tester("/some/path/to/json")\n
    question = next(tester)\n
    ...\n
    result = question[2](answer, resp, heart_rate, blushing, pupil)\n

"""

from json import load
from typing import Callable



class Tester(object):
    """
    Class, that conducts tests

    Use as iterable, to get tuple with
    (question: str, answers: list, callback with 5 int args)

    Use evaluate at the end, to get bool evaluation 
    (0: Replicant, 1: Human)
    """
    __test__ = False

    def __init__(self, path: str, min_quest: int = 5):
        with open(path, "r") as f:
            self.questions = load(f)
        self.current_question = 0
        self.responces = [None for i in range(len(self.questions))]
        self.min_quest = min(min_quest, len(self.questions))

    def __iter__(self):
        return self

    def __next__(self) -> tuple[str, list[str], Callable]:
        """
        Iterator function, that is the main way to conduct survey

        Yields:
            Tuple with (question: str, answers: list, callback with 5 int args)
            Callback args: 
            > answer position (int)
            > respiration rate (int)
            > heart rate (int)
            > blushing level (int)
            > pupillary dilation (int/mm)

            Callback returns:
            > None if everything is ok
            > String with problem description

        Raises:
            StopIteration: If there is no more questions

        """
        if self.current_question < len(self.questions):
            pos = self.current_question

            def callback(answer: int, resp: int,
                         heart_rate: int, blushing: int,
                         pupil: int) -> str | None:
                try:
                    self.check_answers([answer, resp, heart_rate, blushing, pupil], pos)
                    self.responces[pos] = [answer, resp, heart_rate, blushing, pupil]
                    return None
                except ValueError as err:
                    return str(err)
            self.current_question += 1
            return (self.questions[pos]["question"], self.questions[pos]["answers"], callback)
        else:
            raise StopIteration("")

    def check_answers(self, data: list, pos: str) -> None:
        if data[0] >= len(self.questions[pos]["eval"]):
            raise ValueError(f"Uncorrect answer number: {data[0]}")
        if data[1] > 30 or data[1] < 2:
            raise ValueError(f"Uncorrect respiration: {data[1]}, should be between 2 and 30")
        if data[2] > 150 or data[2] < 30:
            raise ValueError(f"Uncorrect heart rate: {data[2]}, should be between 30 and 150")
        if data[3] > 6 or data[3] < 1:
            raise ValueError(f"Uncorrect blush rate: {data[3]}, should be between 1 and 6")
        if data[4] > 8 or data[4] < 2:
            raise ValueError(f"Uncorrect pupil size: {data[4]}, should be between 2 and 8")

    def evaluate(self) -> bool:
        """
        Evaluates question answers and gives an answer
    
        Returns:
            bool: estimation is it Replicant (False) or Human (True)

        Raises:
            Exception: if there is less than n answers. (n is passable as arg in init)
        """
        answered_questions = sum([1 if i else 0 for i in self.responces])
        if answered_questions >= self.min_quest:
            answers_points = sum([self.questions[i[0]]['eval'][i[1][0]] for i in enumerate(self.responces)])
            resp = sum([i[1] for i in self.responces])
            heart_rate = sum([i[2] for i in self.responces])
            blushing = sum([i[3] for i in self.responces])
            pupil = sum([i[4] for i in self.responces])
            if (1 * answers_points
               + 0.3 * (resp)
               + 0.5 * (heart_rate)
               + 0.3 * (blushing)
               + 1 * (pupil)) / answered_questions \
               > 53:
                return True
            else:
                return False
        else:
            raise Exception(f"Not enough (< { self.min_quest }) questions is answered")
