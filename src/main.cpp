#include <iostream>
#include "Vec.h"
#include "sorts.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main()
{
    srand(time(NULL));

    for (int factor = 100; factor < 5000; factor += 100)
    {
        Vec V(1);

        int n = 10;

        for (int i = 0; i < n; i++)
        {
            int num = rand();
            V.push(num);
        }

        Vec orMerge(V), orBub(V), orInsert(V);

        LARGE_INTEGER t, t1, f;

        QueryPerformanceFrequency(&f);
        QueryPerformanceCounter(&t);
        BubbleSort(orBub);
        cout << "Original BubVector: " << orBub << "\t\tSorted: " << orBub << "\n"
             << endl;
        QueryPerformanceCounter(&t1);
        double Bubtime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        QueryPerformanceCounter(&t);
        InsertionSort(orInsert);
        cout << "Original BInsertVector: " << orInsert << "\t\tSorted: " << orInsert << "\n"
             << endl;
        QueryPerformanceCounter(&t1);
        double Insertime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        QueryPerformanceCounter(&t);
        MergeSort(V, 0, orMerge.size() - 1);
        cout << "Original mergeVector: " << orMerge << "\t\tSorted: " << orMerge << "\n"
             << endl;
        QueryPerformanceCounter(&t1);
        double Mergetime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        cout << Bubtime << "\t\t" << Insertime << "\t\t" << Mergetime << endl;
        cout << endl;
    }

    return 0;
}