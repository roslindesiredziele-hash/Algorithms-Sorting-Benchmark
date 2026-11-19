cmake_minimum_required(VERSION 3.10)

project(AlgorithmsSortingBenchmark)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    benchmark
    src/main.cpp
    src/Vec.cpp
    src/sorts.cpp
)

enable_testing()

add_executable(
    AlgorithmsSortingBenchmark_TDD
    src/Vec.cpp
    src/sorts.cpp
    tests/AlgorithmsSortingBenchmark_TDD.cpp
)

target_include_directories(
    AlgorithmsSortingBenchmark_TDD
    PRIVATE
        src
        external
)

add_test(
    NAME AlgorithmsSortingBenchmarkTests
    COMMAND AlgorithmsSortingBenchmark_TDD
)