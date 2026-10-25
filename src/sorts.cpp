#include "sorts.h"

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



void MergeSort(Vec& V, int left, int right)
{
    if(left >= right)
    {
        return;
    }

    int mid  = (left + right)/2;

    MergeSort(V, left, mid);
    MergeSort(V, mid + 1, right);

    Merge(V, left, mid, right);
}