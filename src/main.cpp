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
    LARGE_INTEGER t, t1, f;
    QueryPerformanceFrequency(&f);

    for (int factor = 100; factor < 5000; factor += 100)
    {
        Vec V(1);

        for (int i = 0; i < factor; i++)
        {
            int num = rand();
            V.push(num);
        }

        Vec orMerge(V), orBub(V), orInsert(V);

        //  cout << "\nOriginal BubVector: " << orBub << "\t\t";
        QueryPerformanceCounter(&t);
        BubbleSort(orBub);
        QueryPerformanceCounter(&t1);
        double Bubtime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
        /*cout << "Sorted: " << orBub << "\n"
             << endl; */

        //  cout << "\nOriginal BInsertVector: " << orInsert << "\t\t";
        QueryPerformanceCounter(&t);
        InsertionSort(orInsert);
        QueryPerformanceCounter(&t1);
        double Insertime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
        /*  cout << "Sorted: " << orInsert << "\n"
                << endl; */

        // cout << "\nOriginal mergeVector: " << orMerge << "\t\t";
        QueryPerformanceCounter(&t);
        MergeSort(orMerge, 0, orMerge.size() - 1);
        QueryPerformanceCounter(&t1);
        double Mergetime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
        /* cout << "Sorted: " << orMerge << "\n"
              << endl; */

        cout << isSorted(orBub) << " "
             << isSorted(orInsert) << " "
             << isSorted(orMerge) << endl;

        cout << factor << "\t\t"
             << Bubtime << "\t\t"
             << Insertime << "\t\t"
             << Mergetime << endl;
        cout << endl;
    }

    return 0;
}