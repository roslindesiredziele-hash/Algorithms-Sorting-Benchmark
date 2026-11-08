import pandas as pd
import matplotlib.pyplot as plt

# Load CSV
df = pd.read_csv("data/data.csv")

# Rename columns if Excel inserted spaces
df.columns = [c.strip() for c in df.columns]

# --------------------------
# Graph 1: All Algorithms
# --------------------------

plt.figure(figsize=(12, 6))

plt.plot(df["Input size"], df["BubbleSort Time"], label="Bubble Sort")
plt.plot(df["Input size"], df["InsertionSort Time"], label="Insertion Sort")
plt.plot(df["Input size"], df["MergeSort Time"], label="Merge Sort")
plt.plot(df["Input size"], df["QuickSort Time"], label="Quick Sort")
plt.plot(df["Input size"], df["HeapSort Time"], label="Heap Sort")
plt.plot(df["Input size"], df["ShellSort Time"], label="Shell Sort")

plt.title("Sorting Algorithms Performance Comparison")
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ms)")
plt.yscale("log")
plt.legend()
plt.grid(True)

plt.savefig("graphs/graph_all_algorithms.png", dpi=300)
plt.close()

# --------------------------
# Graph 2: Fast Algorithms
# --------------------------

plt.figure(figsize=(12, 6))

plt.plot(df["Input size"], df["MergeSort Time"], label="Merge Sort")
plt.plot(df["Input size"], df["QuickSort Time"], label="Quick Sort")
plt.plot(df["Input size"], df["HeapSort Time"], label="Heap Sort")
plt.plot(df["Input size"], df["ShellSort Time"], label="Shell Sort")

plt.title("O(n log n) Algorithms Comparison")
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ms)")
plt.yscale("log")
plt.legend()
plt.grid(True)

plt.savefig("graphs/graph_fast_algorithms.png", dpi=300)
plt.close()

# --------------------------
# Graph 3: Quadratic Algorithms
# --------------------------

plt.figure(figsize=(12, 6))

plt.plot(df["Input size"], df["BubbleSort Time"], label="Bubble Sort")
plt.plot(df["Input size"], df["InsertionSort Time"], label="Insertion Sort")

plt.title("Quadratic Sorting Algorithms Comparison")
plt.xlabel("Input Size (n)")
plt.ylabel("Execution Time (ms)")
plt.legend()
plt.grid(True)

plt.savefig("graphs/graph_quadratic_algorithms.png", dpi=300)
plt.close()

print("Graphs generated successfully.")