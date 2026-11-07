#include "sorts.h"

bool isSorted(const Vec &V)
{
    for (int i = 1; i < V.size(); i++)
    {
        if (V[i - 1] > V[i])
        {
            return false;
        }
    }

    return true;
}

void SwapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(Vec &V)
{
    int n = V.size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (V[j] > V[j + 1])
                SwapInt(V[j], V[j + 1]);
        }
    }
}

void InsertionSort(Vec &V)
{
    int n = V.size();
    for (int i = 1; i < n; i++)
    {
        int temp = V[i];
        int track = i - 1;

        while (track >= 0 && V[track] > temp)
        {
            V[track + 1] = V[track];
            track--;
        }

        V[track + 1] = temp;
    }
}

void Merge(Vec &V, int left, int mid, int right)
{
    int n = right - left + 1;
    Vec temp(n);

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (V[i] <= V[j])
        {
            temp.push(V[i]);
            i++;
        }
        else
        {
            temp.push(V[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        temp.push(V[i]);
        i++;
    }

    while (j <= right)
    {
        temp.push(V[j]);
        j++;
    }

    for (int step = 0; step < temp.size(); step++)
    {
        V[left + step] = temp[step];
    }
}

void MergeSort(Vec &V, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int mid = left + (right - left) / 2;

    MergeSort(V, left, mid);
    MergeSort(V, mid + 1, right);

    Merge(V, left, mid, right);
}

void QuickSort(Vec &V, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    int pivotIndex = left + rand() % (right - left + 1);

    SwapInt(V[pivotIndex], V[right]);

    int pivot = V[right];

    int i = left;

    for (int j = left; j <= right; j++)
    {
        if (V[j] <= pivot)
        {
            SwapInt(V[i], V[j]);
            i++;
        }
    }

    int pivotpos = i - 1;

    QuickSort(V, left, pivotpos - 1);
    QuickSort(V, pivotpos + 1, right);
}

void Heapify(Vec& V, int heapSize, int node)
{
    int largest = node;

    int left = 2 * node + 1;
    int right = 2 * node + 2;

    if (left < heapSize && V[left] > V[largest])
    {
        largest = left;
    }

    if (right < heapSize && V[right] > V[largest])
    {
        largest = right;
    }

    if (largest != node)
    {
        SwapInt(V[node], V[largest]);

        Heapify(V, heapSize, largest);
    }
}

void HeapSort(Vec &V)
{

}