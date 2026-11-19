import pandas as pd
import matplotlib.pyplot as plt
from pathlib import Path

# ----------------------------
# Load data
# ----------------------------

df = pd.read_csv("data/data.csv")
df.columns = [c.strip() for c in df.columns]

Path("report").mkdir(exist_ok=True)

# ----------------------------
# Helper Function
# ----------------------------

def plot_algorithms(data, algorithms, title, filename, log_scale=False):
    plt.figure(figsize=(12, 6))

    for algo in algorithms:
        plt.plot(
            data["InputSize"],
            data[algo],
            marker="o",
            linewidth=2,
            label=algo.replace("Sort", " Sort")
        )

    plt.title(title)
    plt.xlabel("Input Size (n)")
    plt.ylabel("Execution Time (ms)")

    if log_scale:
        plt.yscale("log")

    plt.grid(True, linestyle="--", alpha=0.7)
    plt.legend()
    plt.tight_layout()

    plt.savefig(f"report/{filename}", dpi=300)
    plt.close()


# =====================================================
# Figure 1: Very Small Inputs (5–25)
# =====================================================

small_25 = df[df["InputSize"] <= 25]

plot_algorithms(
    small_25,
    [
        "BubbleSort",
        "InsertionSort",
        "MergeSort",
        "QuickSort",
        "HeapSort",
        "ShellSort"
    ],
    "Very Small Inputs (5-25)",
    "figure1_very_small_inputs.png"
)

# =====================================================
# Figure 2: Small Inputs (25–50)
# =====================================================

range_25_50 = df[(df["InputSize"] >= 25) &
                 (df["InputSize"] <= 50)]

plot_algorithms(
    range_25_50,
    [
        "BubbleSort",
        "InsertionSort",
        "MergeSort",
        "QuickSort",
        "HeapSort",
        "ShellSort"
    ],
    "Small Inputs (25-50)",
    "figure2_small_inputs.png"
)

# =====================================================
# Figure 3: Transition Region (50–100)
# =====================================================

range_50_100 = df[(df["InputSize"] >= 50) &
                  (df["InputSize"] <= 100)]

plot_algorithms(
    range_50_100,
    [
        "BubbleSort",
        "InsertionSort",
        "MergeSort",
        "QuickSort",
        "HeapSort",
        "ShellSort"
    ],
    "Transition Region (50-100)",
    "figure3_transition_region.png"
)

# =====================================================
# Figure 4: Medium-to-Large Inputs (100–2000)
# =====================================================

large_inputs = df[df["InputSize"] >= 100]

plot_algorithms(
    large_inputs,
    [
        "BubbleSort",
        "InsertionSort",
        "MergeSort",
        "QuickSort",
        "HeapSort",
        "ShellSort"
    ],
    "Medium-to-Large Inputs (100-2000)",
    "figure4_medium_large_inputs.png"
)

# =====================================================
# Figure 5: Quadratic Algorithms Only
# =====================================================

plot_algorithms(
    df,
    [
        "BubbleSort",
        "InsertionSort"
    ],
    "Quadratic Algorithms Comparison",
    "figure5_quadratic_algorithms.png"
)

# =====================================================
# Figure 6: O(n log n) Algorithms Only
# =====================================================

plot_algorithms(
    df,
    [
        "MergeSort",
        "QuickSort",
        "HeapSort",
        "ShellSort"
    ],
    "O(n log n) Algorithms Comparison",
    "figure6_nlogn_algorithms.png"
)

# =====================================================
# Figure 7: Full Comparison (Log Scale)
# =====================================================

plot_algorithms(
    df,
    [
        "BubbleSort",
        "InsertionSort",
        "MergeSort",
        "QuickSort",
        "HeapSort",
        "ShellSort"
    ],
    "All Algorithms Comparison (Log Scale)",
    "figure7_full_comparison_log.png",
    log_scale=True
)

print("Generated:")
print(" - figure1_very_small_inputs.png")
print(" - figure2_small_inputs.png")
print(" - figure3_transition_region.png")
print(" - figure4_medium_large_inputs.png")
print(" - figure5_quadratic_algorithms.png")
print(" - figure6_nlogn_algorithms.png")
print(" - figure7_full_comparison_log.png")