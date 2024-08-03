import unittest

from energy import fix_wiring


class TestFixWiring(unittest.TestCase):

    def test_basic_case(self):
        plugs = ["plug1", "plug2", "plug3"]
        sockets = ["socket1", "socket2", "socket3", "socket4"]
        cables = ["cable1", "cable2", "cable3", "cable4"]
        expected = [
            "plug cable1 into socket1 using plug1",
            "plug cable2 into socket2 using plug2",
            "plug cable3 into socket3 using plug3",
            "weld cable4 to socket4 without plug",
        ]
        result = list(fix_wiring(cables, sockets, plugs))
        self.assertEqual(result, expected)

    def test_filter_non_strings(self):
        plugs = ["plug1", None, "plug2"]
        sockets = [1, "socket1", "socket2"]
        cables = ["cable1", False]
        expected = ["plug cable1 into socket1 using plug1"]
        result = list(fix_wiring(cables, sockets, plugs))
        self.assertEqual(result, expected)

    def test_more_sockets_than_cables(self):
        plugs = ["plug1", "plug2"]
        sockets = ["socket1", "socket2", "socket3"]
        cables = ["cable1", "cable2"]
        expected = [
            "plug cable1 into socket1 using plug1",
            "plug cable2 into socket2 using plug2",
        ]
        result = list(fix_wiring(cables, sockets, plugs))
        self.assertEqual(result, expected)

    def test_sockets_cables_without_plugs(self):
        plugs = ["plug1", "plug2"]
        sockets = ["socket1", "socket2", "socket3"]
        cables = ["cable1", "cable2", "cable3"]
        expected = [
            "plug cable1 into socket1 using plug1",
            "plug cable2 into socket2 using plug2",
            "weld cable3 to socket3 without plug",
        ]
        result = list(fix_wiring(cables, sockets, plugs))
        self.assertEqual(result, expected)

    def test_more_cables_than_sockets(self):
        plugs = ["plug1", "plug2"]
        sockets = ["socket1"]
        cables = ["cable1", "cable2", "cable3"]
        expected = ["plug cable1 into socket1 using plug1"]
        result = list(fix_wiring(cables, sockets, plugs))
        self.assertEqual(result, expected)

    def test_all_empty(self):
        plugs = []
        sockets = []
        cables = []
        expected = []
        result = list(fix_wiring(cables, sockets, plugs))
        self.assertEqual(result, expected)

    def test_empty_plugs(self):
        plugs = []
        sockets = ["socket1", "socket2"]
        cables = ["cable1", "cable2"]
        expected = [
            "weld cable1 to socket1 without plug",
            "weld cable2 to socket2 without plug",
        ]
        result = list(fix_wiring(cables, sockets, plugs))
        self.assertEqual(result, expected)


if __name__ == "__main__":
    unittest.main()
