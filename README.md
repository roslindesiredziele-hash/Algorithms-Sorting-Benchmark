# Algorithms Sorting Benchmark

A C++ project for benchmarking and comparing classical sorting algorithms using a custom dynamic array implementation (`Vec`).

The project was developed as part of an Algorithms course and focuses on practical performance analysis, complexity comparison, and experimental evaluation of sorting techniques.

---

## Features

### Sorting Algorithms

- Bubble Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Shell Sort

### Custom Data Structure

- `Vec` dynamic array implementation
- Dynamic resizing
- Deep copy semantics
- Bounds-checked element access
- Copy assignment operator
- Stream output operator

### Benchmarking

- Random input generation
- High-resolution timing using `QueryPerformanceCounter`
- Sorting correctness verification
- CSV export
- Automated graph generation

---

## Complexity Summary

| Algorithm | Best | Average | Worst |
|------------|------------|------------|------------|
| Bubble Sort | O(n) | O(n²) | O(n²) |
| Insertion Sort | O(n) | O(n²) | O(n²) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) |
| Shell Sort | Depends on gap sequence | Typically better than O(n²) | Depends on gap sequence |

---

## Benchmark Methodology

For each input size:

1. Generate a random input array.
2. Create identical copies of the input.
3. Run each sorting algorithm on the same data.
4. Measure execution time independently.
5. Verify correctness using `isSorted(...)`.
6. Export measurements to CSV.

Results are stored in:

```text
data/data.csv
```

---

## Example Results

```text
N       Bubble   Insertion   Merge   Quick   Heap   Shell

100     0.196    0.078       0.096   0.034   0.050  0.037
1000    17.149   6.811       1.098   0.404   0.806  0.668
2000    59.985   19.199      1.437   0.729   1.240  1.122
```

---

## Graph Generation

Benchmark results can be visualized with:

- Pandas
- Matplotlib

Generate graphs using:

```bash
python data/plot_results.py
```

Generated figures:

```text
graph_all_algorithms.png
graph_fast_algorithms.png
graph_quadratic_algorithms.png
```

---

## Observations

Experimental results are consistent with theoretical complexity analysis.

- Bubble Sort is the slowest algorithm for larger inputs.
- Insertion Sort performs better than Bubble Sort but remains quadratic.
- Merge Sort demonstrates stable O(n log n) growth.
- Quick Sort is typically the fastest on random input data.
- Heap Sort guarantees O(n log n) performance while sorting in-place.
- Shell Sort significantly outperforms quadratic algorithms and remains competitive with Heap Sort.

---

## Project Structure

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

---

## Build

Compile using GCC:

```bash
g++ src/main.cpp src/sorts.cpp src/Vec.cpp -o benchmark
```

Run:

```bash
./benchmark
```

Windows:

```cmd
benchmark.exe
```

---

## Technologies

- C++17
- GCC / MinGW
- Git
- Python
- Pandas
- Matplotlib

---

## Future Improvements

- Multiple benchmark repetitions and averaging
- Additional input distributions
  - Sorted arrays
  - Reverse-sorted arrays
  - Nearly sorted arrays
  - Duplicate-heavy arrays
- Comparison against `std::sort`
- Cross-platform timing using `std::chrono`
- Automated testing

---

## Author

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź