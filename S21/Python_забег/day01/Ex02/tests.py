import unittest
from io import StringIO
from unittest.mock import patch

from decorator import *


class TestPurseFunctionsWithSqueak(unittest.TestCase):

    @patch("sys.stdout", new_callable=StringIO)
    def test_empty_with_squeak(self, mock_stdout):
        purse = {"gold_ingots": 3}
        self.assertEqual(empty(purse), {})
        self.assertIn("SQUEAK", mock_stdout.getvalue())

    @patch("sys.stdout", new_callable=StringIO)
    def test_add_ingot_with_squeak(self, mock_stdout):
        purse = {"gold_ingots": 1}
        new_purse = add_ingot(purse)
        self.assertEqual(new_purse, {"gold_ingots": 2})
        self.assertEqual(purse, {"gold_ingots": 1})
        self.assertIn("SQUEAK", mock_stdout.getvalue())

    @patch("sys.stdout", new_callable=StringIO)
    def test_get_ingot_with_squeak(self, mock_stdout):
        purse = {"gold_ingots": 3}
        new_purse = get_ingot(purse)
        self.assertEqual(new_purse, {"gold_ingots": 2})
        self.assertEqual(purse, {"gold_ingots": 3})
        self.assertIn("SQUEAK", mock_stdout.getvalue())

    @patch("sys.stdout", new_callable=StringIO)
    def test_compile_with_squeak(self, mock_stdout):
        purse = {"gold_ingots": 3}
        new_purse = add_ingot(get_ingot(add_ingot(empty(purse))))
        self.assertEqual(new_purse, {"gold_ingots": 1})
        output = mock_stdout.getvalue()
        self.assertEqual(output.count("SQUEAK"), 4)  # Four operations

    @patch("sys.stdout", new_callable=StringIO)
    def test_other_purse_with_squeak(self, mock_stdout):
        purse = {"stones_ingots": 3}
        new_purse = add_ingot(purse)
        self.assertEqual(new_purse, {"stones_ingots": 3, "gold_ingots": 1})
        self.assertIn("SQUEAK", mock_stdout.getvalue())


if __name__ == "__main__":
    unittest.main()
