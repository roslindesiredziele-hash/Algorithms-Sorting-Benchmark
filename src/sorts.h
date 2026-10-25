#ifndef SORTS_H
#define SORTS_H

#include "Vec.h"

void BubbleSort(Vec& V);
void InsertionSort(Vec& V);
void Merge(Vec& V, int left, int mid, int right);
void MergeSort(Vec& V, int left, int right);

#endif

