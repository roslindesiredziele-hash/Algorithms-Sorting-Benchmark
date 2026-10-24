#include "sorts.h"

void SwapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(Vec &v)
{
    int n = v.size();

    for (int i = 0; i < n - 1 ; i++)
    {
        for (int j = 0; j < n -i - 1; j++)
        {
            if (v[j] > v[j + 1])
                SwapInt(v[j], v[j + 1]);
        }
    }
}