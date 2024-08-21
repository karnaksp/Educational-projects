import unittest
import time
from monotonic import monotonic
import matplotlib.pyplot as plt


class TestMonotonicComparison(unittest.TestCase):

    def test_monotonic_time_comparison_plot(self):
        """Generate a plot to visually compare the monotonic time from two sources."""
        num_samples = 50
        custom_times = []
        standard_times = []
        sleep_intervals = 0.05

        for _ in range(num_samples):
            custom_times.append(monotonic())
            standard_times.append(time.monotonic())
            time.sleep(sleep_intervals)

        plt.figure(figsize=(12, 6))
        plt.subplot(2, 1, 1)
        plt.plot(
            custom_times, marker="o", linestyle="-", color="b", label="Custom monotonic"
        )
        plt.title("Custom Monotonic Time Progression")
        plt.xlabel("Sample Number")
        plt.ylabel("Time (seconds)")
        plt.grid(True)
        plt.legend()
        plt.subplot(2, 1, 2)
        plt.plot(
            standard_times,
            marker="o",
            linestyle="-",
            color="r",
            label="Standard monotonic",
        )
        plt.title("Standard Monotonic Time Progression")
        plt.xlabel("Sample Number")
        plt.ylabel("Time (seconds)")
        plt.grid(True)
        plt.legend()

        plt.tight_layout()
        plt.savefig("plot.png")

    def test_monotonic_time_comparison_print(self):
        """Print example times from both sources for manual comparison."""
        print("Monotonic Time Comparison Example:")
        for _ in range(5):
            print(f"Custom monotonic: {monotonic()}")
            print(f"Standard monotonic: {time.monotonic()}")
            time.sleep(0.5)


class TestMonotonic(unittest.TestCase):

    def test_monotonic_time_in_seconds(self):
        """Ensure that the monotonic time is a non-negative number."""
        current_time = monotonic()
        self.assertIsInstance(current_time, float)
        self.assertGreaterEqual(current_time, 0)

    def test_monotonic_time_order(self):
        """Ensure that consecutive calls return increasing time values."""
        time1 = monotonic()
        time.sleep(0.1)
        time2 = monotonic()
        self.assertGreater(time2, time1)

    def test_monotonic_time_sanity(self):
        """Check if the time difference is reasonable (within a certain range)."""
        time1 = monotonic()
        time.sleep(1)
        time2 = monotonic()
        self.assertAlmostEqual(time2 - time1, 1, delta=0.1)


if __name__ == "__main__":
    unittest.main()
