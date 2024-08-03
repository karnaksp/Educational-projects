import unittest
from unittest.mock import patch

from personality import create_turret_class, random_by_total, turrets_generator


class TestRandomByTotal(unittest.TestCase):
    def test_random_by_total_total(self):
        result = random_by_total(total=100)
        self.assertEqual(sum(result), 100)

    def test_random_by_total_count(self):
        result = random_by_total(count=3)
        self.assertEqual(len(result), 3)

    def test_random_by_total_invalid_count(self):
        with self.assertRaises(ValueError):
            random_by_total(count=0)

    def test_random_by_total_total_zero(self):
        with self.assertRaises(ValueError):
            random_by_total(total=0)

    def test_random_by_total_total_negative(self):
        with self.assertRaises(ValueError):
            random_by_total(total=-100)

    def test_random_by_total_count_one(self):
        result = random_by_total(count=1)
        self.assertEqual(result, (100,))

    @patch("random.randint")  # подменяет реальный random на заданные числа
    def test_random_by_total_invalid_input(self, mock_randint):
        mock_randint.side_effect = [1, 2, 3]
        with self.assertRaises(ValueError):
            random_by_total(total=0, count=3)

    @patch("random.randint")
    def test_random_by_total_enough_total(self, mock_randint):
        mock_randint.side_effect = [1, 2, 3]
        result = random_by_total(total=6, count=3)
        self.assertEqual(result, (1, 2, 3))

    @patch("random.randint")
    def test_random_by_total_not_enough_total(self, mock_randint):
        mock_randint.side_effect = [1, 2]
        with self.assertRaises(ValueError):
            random_by_total(total=3, count=3)


class TestCreateTurretClass(unittest.TestCase):
    def test_turret_class_creation(self):
        turret_class = create_turret_class(5, 3, 2, 1, 4)
        self.assertEqual(turret_class.name, "Turret")
        self.assertEqual(turret_class.neuroticism, 5)
        self.assertEqual(turret_class.openness, 3)
        self.assertEqual(turret_class.conscientiousness, 2)
        self.assertEqual(turret_class.extraversion, 1)
        self.assertEqual(turret_class.agreeableness, 4)


class TestTurretsGenerator(unittest.TestCase):

    @patch("personality.random_by_total")
    def test_turrets_generator_calls_random_by_total(
            self, mock_random_by_total):
        mock_random_by_total.return_value = (1, 2, 3, 4, 90)
        next(turrets_generator())
        mock_random_by_total.assert_called_once_with(count=5)

    @patch("personality.create_turret_class")
    @patch("personality.random_by_total")
    def test_turrets_generator_calls_create_turret_class(
        self, mock_random_by_total, mock_create_turret_class
    ):
        mock_random_by_total.return_value = (1, 2, 3, 4, 90)
        next(turrets_generator())
        mock_create_turret_class.assert_called_once_with(1, 2, 3, 4, 90)

    @patch("personality.create_turret_class")
    def test_turrets_generator_returns_turret_class(
            self, mock_create_turret_class):
        mock_create_turret_class.return_value = "Turret"
        turret = next(turrets_generator())
        self.assertEqual(turret, "Turret")

    @patch("personality.create_turret_class")
    @patch("personality.random_by_total")
    def test_turrets_generator_yields_infinite_sequence(
        self, mock_random_by_total, mock_create_turret_class
    ):
        mock_random_by_total.return_value = (1, 2, 3, 4, 90)
        mock_create_turret_class.return_value = "Turret"
        turrets = set(next(turrets_generator()) for _ in range(10))
        self.assertEqual(len(turrets), 1)

    @patch("personality.create_turret_class")
    @patch("personality.random_by_total")
    def test_turrets_generator_yields_different_turrets(
        self, mock_random_by_total, mock_create_turret_class
    ):
        mock_random_by_total.side_effect = [
            (1, 2, 3, 4, 90),
            (5, 6, 7, 8, 74),
        ]
        mock_create_turret_class.side_effect = ["Turret1", "Turret2"]
        turrets = [next(turrets_generator()) for _ in range(2)]
        self.assertNotEqual(turrets[0], turrets[1])


if __name__ == "__main__":
    unittest.main()
