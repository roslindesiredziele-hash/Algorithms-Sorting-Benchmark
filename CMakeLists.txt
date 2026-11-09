cmake_minimum_required(VERSION 3.10)

project(AlgorithmsSortingBenchmark)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

add_executable(
    AlgorithmsSortingBenchmark_TDD
    src/sorts.cpp
    tests/AlgorithmsSortingBenchmark_TDD.cpp
)

target_include_directories(AlgorithmsSortingBenchmark_TDD PRIVATE
    src
    external
)

add_test(
    NAME AlgorithmsSortingBenchmarkTests
    COMMAND AlgorithmsSortingBenchmark_TDD
)