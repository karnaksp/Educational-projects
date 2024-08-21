import time
import random
from itertools import tee
import matplotlib.pyplot as plt
from multiply import mul


def pure_python_mul(a, b):
    b_iter = tee(zip(*b), len(a))
    return [
        [
            sum(ele_a * ele_b for ele_a, ele_b in zip(row_a, col_b))
            for col_b in b_iter[i]
        ]
        for i, row_a in enumerate(a)
    ]


def generate_random_matrix(rows, cols):
    return [[random.randint(0, 10) for _ in range(cols)] for _ in range(rows)]


def time_pure_python_mul(a, b):
    start = time.time()
    pure_python_mul(a, b)
    return time.time() - start


def time_cython_mul(a, b):
    start = time.time()
    mul(a, b)
    return time.time() - start


def test_performance(sizes):
    python_times = []
    cython_times = []

    for size in sizes:
        rows_a = cols_a = size
        cols_b = size

        a = generate_random_matrix(rows_a, cols_a)
        b = generate_random_matrix(cols_a, cols_b)

        python_time = time_pure_python_mul(a, b)
        cython_time = time_cython_mul(a, b)

        python_times.append(python_time)
        cython_times.append(cython_time)

        print(
            f"Size {size}x{size}: Python: {python_time:.4f} seconds, Cython: {cython_time:.4f} seconds"
        )

    return sizes, python_times, cython_times


def plot_performance(sizes, python_times, cython_times):
    plt.figure(figsize=(10, 6))
    plt.plot(sizes, python_times, label="Pure Python", marker="o")
    plt.plot(sizes, cython_times, label="Cython", marker="o")
    plt.xlabel("Matrix Size (n x n)")
    plt.ylabel("Time (seconds)")
    plt.title("Performance Comparison: Pure Python vs. Cython Matrix Multiplication")
    plt.legend()
    plt.grid(True)
    plt.savefig("performance_comparison.png")


if __name__ == "__main__":
    sizes = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
    sizes, python_times, cython_times = test_performance(sizes)
    plot_performance(sizes, python_times, cython_times)
