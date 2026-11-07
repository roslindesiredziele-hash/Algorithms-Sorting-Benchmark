# Algorithms Sorting Benchmark

A C++ project comparing the performance of classical sorting algorithms using a custom dynamic array implementation (`Vec`) and an experimental benchmarking framework.

Implemented:

- Bubble Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Shell Sort

Custom data structure:

- Vec

Benchmark:

- Random input generation
- High-resolution timing (`QueryPerformanceCounter`)
- Sorting correctness verification
- CSV export
- Performance graph generation

Graph generation:

- Pandas
- Matplotlib

Generated data:

- `data/data.csv`

Generated graphs:

- `graph_all_algorithms.png`
- `graph_fast_algorithms.png`
- `graph_quadratic_algorithms.png`

Algorithm complexity:

| Algorithm | Best Case | Average Case | Worst Case |
|------------|------------|------------|------------|
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) |
| Shell Sort | Depends on gap sequence | Typically better than O(n²) | Depends on gap sequence |

Benchmark methodology:

1. Generate a random input array.
2. Create identical copies of the input.
3. Run each sorting algorithm on the same data.
4. Verify correctness using `isSorted(...)`.
5. Measure execution time.
6. Export results to CSV.
7. Generate performance graphs.

Typical output:

```text
N       Bubble   Insertion   Merge   Quick   Heap   Shell

100     0.196    0.078       0.096   0.034   0.050  0.037
1000    17.149   6.811       1.098   0.404   0.806  0.668
2000    59.985   19.199      1.437   0.729   1.240  1.122
```

Build:

```bash
g++ src/main.cpp src/sorts.cpp src/Vec.cpp -o benchmark
```

Run:

```bash
./benchmark
```

or on Windows:

```cmd
benchmark.exe
```

Generate graphs:

```bash
python data/plot_results.py
```

Project structure:

```text
Algorithms-Sorting-Benchmark
│
├── data/
│   ├── data.csv
│   └── plot_results.py
│
├── report/
│
├── src/
│   ├── main.cpp
│   ├── Vec.cpp
│   ├── Vec.h
│   ├── sorts.cpp
│   └── sorts.h
│
└── README.md
```

Technologies:

- C++17
- GCC / MinGW
- Git
- Python
- Pandas
- Matplotlib

Future improvements:

- Average multiple benchmark runs
- Additional input distributions:
  - Sorted arrays
  - Reverse-sorted arrays
  - Nearly sorted arrays
  - Duplicate-heavy arrays
- Comparison with `std::sort`
- Cross-platform timing using `std::chrono`
- Unit testing

Author:

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź