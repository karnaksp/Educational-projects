from tester import Tester
import pytest

def test_empty():
    tester = Tester("./empty.json")
    with pytest.raises(StopIteration):
        tester.__next__()


def test_one():
    tester = Tester("./test.json")
    next(tester)
    with pytest.raises(StopIteration):
        tester.__next__()


def test_wrong_input():
    tester = Tester("./test.json")
    assert next(tester)[2](0, 0, 0, 0, 0)


def test_correct_input():
    tester = Tester("./test.json")
    assert not next(tester)[2](1, 14, 80, 3, 3)


def test_replicant():
    tester = Tester("./test.json")
    next(tester)[2](0, 14, 60, 1, 2)
    assert not tester.evaluate()


def test_human():
    tester = Tester("./test.json")
    next(tester)[2](2, 30, 120, 6, 8)
    assert tester.evaluate()
