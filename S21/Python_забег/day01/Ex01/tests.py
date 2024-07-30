import unittest

from split_booty import split_booty


class TestSplitBooty(unittest.TestCase):

    def test_even_distribution(self):
        purses = ({"gold_ingots": 6}, {"gold_ingots": 3}, {"gold_ingots": 9})
        result = split_booty(*purses)
        expected = ({"gold_ingots": 6}, {"gold_ingots": 6}, {"gold_ingots": 6})
        self.assertEqual(result, expected)

    def test_balanced_distribution(self):
        purses = ({"gold_ingots": 5}, {"gold_ingots": 7}, {"gold_ingots": 8})
        result = split_booty(*purses)
        expected = ({"gold_ingots": 7}, {"gold_ingots": 7}, {"gold_ingots": 6})
        self.assertEqual(result, expected)

    def test_all_zero_ingots(self):
        purses = ({}, {}, {})
        result = split_booty(*purses)
        expected = ({}, {}, {})
        self.assertEqual(result, expected)

    def test_some_zero_ingots(self):
        purses = ({"gold_ingots": 0}, {"gold_ingots": 3}, {"gold_ingots": 6})
        result = split_booty(*purses)
        expected = ({"gold_ingots": 3}, {"gold_ingots": 3}, {"gold_ingots": 3})
        self.assertEqual(result, expected)

    def test_empty_purses(self):
        purses = ()
        result = split_booty(*purses)
        expected = ({}, {}, {})
        self.assertEqual(result, expected)

    def test_non_integer_value(self):
        with self.assertRaises(ValueError):
            split_booty({"gold_ingots": "five"}, {
                        "gold_ingots": 3}, {"gold_ingots": 2})

    def test_negative_value(self):
        with self.assertRaises(ValueError):
            split_booty({"gold_ingots": -1},
                        {"gold_ingots": 3}, {"gold_ingots": 2})

    def test_no_gold_ingots(self):
        purses = ({"stones": 5}, {"apples": 3}, {"wood": 2})
        result = split_booty(*purses)
        expected = ({}, {}, {})
        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()
