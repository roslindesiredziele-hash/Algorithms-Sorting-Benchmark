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

    for (int i = 0; i < n - 1 ; i++)
    {
        for (int j = 0; j < n -i - 1; j++)
        {
            if (V[j] > V[j + 1])
                SwapInt(V[j], V[j + 1]);
        }
    }
}