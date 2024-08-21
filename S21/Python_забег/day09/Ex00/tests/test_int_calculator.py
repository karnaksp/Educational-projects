import unittest
import calculator


class TestIntCalculator(unittest.TestCase):

    def test_add(self):
        self.assertEqual(calculator.add(10, 5), 15)
        self.assertEqual(calculator.add(-10, 5), -5)
        self.assertEqual(calculator.add(0, 0), 0)

    def test_sub(self):
        self.assertEqual(calculator.sub(10, 5), 5)
        self.assertEqual(calculator.sub(5, 10), -5)
        self.assertEqual(calculator.sub(0, 0), 0)

    def test_mul(self):
        self.assertEqual(calculator.mul(10, 5), 50)
        self.assertEqual(calculator.mul(-10, 5), -50)
        self.assertEqual(calculator.mul(0, 5), 0)

    def test_div(self):
        self.assertEqual(calculator.div(10, 5), 2)
        self.assertEqual(calculator.div(5, 1), 5)
        with self.assertRaises(ZeroDivisionError):
            calculator.div(10, 0)

    def test_invalid_inputs(self):
        with self.assertRaises(TypeError):
            calculator.add(10.5, 5)
        with self.assertRaises(TypeError):
            calculator.sub(10, "5")
        with self.assertRaises(TypeError):
            calculator.mul(10, None)
        with self.assertRaises(TypeError):
            calculator.div(10, [5])


if __name__ == "__main__":
    unittest.main()
