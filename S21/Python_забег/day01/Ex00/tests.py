import unittest

from purse import *


class TestPurseFunctions(unittest.TestCase):

    def test_empty(self):
        purse = {"gold_ingots": 3}
        self.assertEqual(empty(purse), {})

    def test_add_ingot(self):
        purse = {"gold_ingots": 1}
        new_purse = add_ingot(purse)
        self.assertEqual(new_purse, {"gold_ingots": 2})
        self.assertEqual(purse, {"gold_ingots": 1})
        empty_purse = {}
        new_purse = add_ingot(empty_purse)
        self.assertEqual(new_purse, {"gold_ingots": 1})
        self.assertEqual(empty_purse, {})

    def test_get_ingot(self):
        purse = {"gold_ingots": 3}
        new_purse = get_ingot(purse)
        self.assertEqual(new_purse, {"gold_ingots": 2})
        self.assertEqual(purse, {"gold_ingots": 3})
        purse = {"gold_ingots": 1}
        new_purse = get_ingot(purse)
        self.assertEqual(new_purse, {})
        empty_purse = {}
        new_purse = get_ingot(empty_purse)
        self.assertEqual(new_purse, {})
        self.assertEqual(empty_purse, {})

    def test_compile(self):
        purse = {"gold_ingots": 3}
        new_purse = add_ingot(get_ingot(add_ingot(empty(purse))))
        self.assertEqual(new_purse, {"gold_ingots": 1})

    def test_other_purse(self):
        purse = {"stones_ingots": 3}
        new_purse = add_ingot(purse)
        self.assertEqual(new_purse, {"stones_ingots": 3, "gold_ingots": 1})

    def test_add_ingot_negative(self):
        purse = {"gold_ingots": -1}
        with self.assertRaises(ValueError) as cm:
            add_ingot(purse)
        self.assertEqual(
            str(cm.exception),
            "The number of gold ingots must be a non-negative integer.",
        )

    def test_add_ingot_non_integer(self):
        purse = {"gold_ingots": "abc"}
        with self.assertRaises(ValueError) as cm:
            add_ingot(purse)
        self.assertEqual(
            str(cm.exception),
            "The number of gold ingots must be a non-negative integer.",
        )

    def test_get_ingot_negative(self):
        purse = {"gold_ingots": -1}
        with self.assertRaises(ValueError) as cm:
            get_ingot(purse)
        self.assertEqual(
            str(cm.exception),
            "The number of gold ingots must be a non-negative integer.",
        )

    def test_get_ingot_non_integer(self):
        purse = {"gold_ingots": "abc"}
        with self.assertRaises(ValueError) as cm:
            get_ingot(purse)
        self.assertEqual(
            str(cm.exception),
            "The number of gold ingots must be a non-negative integer.",
        )


if __name__ == "__main__":
    unittest.main()
