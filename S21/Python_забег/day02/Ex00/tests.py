import unittest

from key import Key


class TestKeyFunctions(unittest.TestCase):

    def test_key(self):
        key = Key()

        self.assertEqual(
            len(key),
            1337,
            f"Expected length 1337, but got {len(key)}")

        self.assertEqual(
            key[404],
            3,
            f"Expected key[404] to be 3, but got {key[404]}")

        self.assertTrue(key > 9000, f"Expected key to be greater than 9000")

        self.assertEqual(
            key.passphrase,
            "zax2rulez",
            f"Expected passphrase to be 'zax2rulez', but got {key.passphrase}",
        )

        self.assertEqual(
            str(key),
            "GeneralTsoKeycard",
            f"Expected str(key) to be 'GeneralTsoKeycard', but got {str(key)}",
        )


if __name__ == "__main__":
    unittest.main()
