import unittest
import calculator


class TestFloatCalculator(unittest.TestCase):

    def test_add(self):
        self.assertAlmostEqual(calculator.add(10.5, 5.2), 15.7)
        self.assertAlmostEqual(calculator.add(-10.5, 5.3), -5.2)
        self.assertAlmostEqual(calculator.add(0.0, 0.0), 0.0)

    def test_sub(self):
        self.assertAlmostEqual(calculator.sub(10.5, 5.2), 5.3)
        self.assertAlmostEqual(calculator.sub(5.3, 10.5), -5.2)
        self.assertAlmostEqual(calculator.sub(0.0, 0.0), 0.0)

    def test_mul(self):
        self.assertAlmostEqual(calculator.mul(10.5, 5.2), 54.6)
        self.assertAlmostEqual(calculator.mul(-10.5, 5.0), -52.5)
        self.assertAlmostEqual(calculator.mul(0.0, 5.2), 0.0)

    def test_div(self):
        self.assertAlmostEqual(calculator.div(10.5, 5.2), 2.019230769230769)
        self.assertAlmostEqual(calculator.div(5.5, 1.1), 5.0)
        with self.assertRaises(ZeroDivisionError):
            calculator.div(10.5, 0.0)

    def test_invalid_inputs(self):
        with self.assertRaises(TypeError):
            calculator.add(10, "5.2")
        with self.assertRaises(TypeError):
            calculator.sub(10.5, [5.2])
        with self.assertRaises(TypeError):
            calculator.mul(10.5, None)
        with self.assertRaises(TypeError):
            calculator.div(10.5, {"a": 5.2})


if __name__ == "__main__":
    unittest.main()
