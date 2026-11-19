#define CATCH_CONFIG_MAIN
#include "../external/catch.hpp"

#include "../src/Vec.h"
#include "../src/sorts.h"

TEST_CASE("Empty vector is sorted")
{
    Vec v(1);

    REQUIRE(isSorted(v));
}

TEST_CASE("Single element vector is sorted")
{
    Vec v(1);
    v.push(42);

    REQUIRE(isSorted(v));
}

TEST_CASE("Bubble Sort sorts correctly")
{
    Vec v(5);

    v.push(5);
    v.push(2);
    v.push(9);
    v.push(1);
    v.push(3);

    BubbleSort(v);

    REQUIRE(isSorted(v));
}

TEST_CASE("Insertion Sort sorts correctly")
{
    Vec v(5);

    v.push(5);
    v.push(2);
    v.push(9);
    v.push(1);
    v.push(3);

    InsertionSort(v);

    REQUIRE(isSorted(v));
}

TEST_CASE("Merge Sort sorts correctly")
{
    Vec v(5);

    v.push(5);
    v.push(2);
    v.push(9);
    v.push(1);
    v.push(3);

    MergeSort(v, 0, v.size() - 1);

    REQUIRE(isSorted(v));
}

TEST_CASE("Quick Sort sorts correctly")
{
    Vec v(5);

    v.push(5);
    v.push(2);
    v.push(9);
    v.push(1);
    v.push(3);

    QuickSort(v, 0, v.size() - 1);

    REQUIRE(isSorted(v));
}

TEST_CASE("Heap Sort sorts correctly")
{
    Vec v(5);

    v.push(5);
    v.push(2);
    v.push(9);
    v.push(1);
    v.push(3);

    HeapSort(v);

    REQUIRE(isSorted(v));
}

TEST_CASE("Shell Sort sorts correctly")
{
    Vec v(5);

    v.push(5);
    v.push(2);
    v.push(9);
    v.push(1);
    v.push(3);

    ShellSort(v);

    REQUIRE(isSorted(v));
}

TEST_CASE("Already sorted vector remains sorted")
{
    Vec v(5);

    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);
    v.push(5);

    QuickSort(v, 0, v.size() - 1);

    REQUIRE(isSorted(v));
}

TEST_CASE("Reverse ordered vector sorts correctly")
{
    Vec v(5);

    v.push(5);
    v.push(4);
    v.push(3);
    v.push(2);
    v.push(1);

    MergeSort(v, 0, v.size() - 1);

    REQUIRE(isSorted(v));
}

TEST_CASE("Sorting preserves vector size")
{
    Vec v(5);

    v.push(5);
    v.push(2);
    v.push(9);
    v.push(1);
    v.push(3);

    int originalSize = v.size();

    HeapSort(v);

    REQUIRE(v.size() == originalSize);
}

TEST_CASE("Vec push increases size")
{
    Vec v(1);

    REQUIRE(v.size() == 0);

    v.push(10);
    v.push(20);

    REQUIRE(v.size() == 2);
}

TEST_CASE("Vec contains finds elements")
{
    Vec v(1);

    v.push(10);
    v.push(20);
    v.push(30);

    REQUIRE(v.contains(20));
    REQUIRE_FALSE(v.contains(99));
}

TEST_CASE("Vec sum computes correctly")
{
    Vec v(1);

    v.push(1);
    v.push(2);
    v.push(3);
    v.push(4);

    REQUIRE(v.sum() == 10);
}

TEST_CASE("Vec average computes correctly")
{
    Vec v(1);

    v.push(2);
    v.push(4);
    v.push(6);
    v.push(8);

    REQUIRE(v.avg() == Approx(5.0));
}