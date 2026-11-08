#include <iostream>
#include "Vec.h"
#include "sorts.h"
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>

using namespace std;

int main()
{
    std::ofstream outfile("./data/data.csv");
    outfile << "Input size" << "," << "BubbleSort Time" << "," << "InsertionSort Time " << "," << "MergeSort Time" << "," << "QuickSort Time" << "," << "HeapSort Time" << "," << "ShellSort Time" << std::endl;

    srand(time(NULL));
    LARGE_INTEGER t, t1, f;
    QueryPerformanceFrequency(&f);

    cout << "OK\tN\tBubble\tInsertion\t\tMerge\t\tQuick\t\tHeap\t\tShell" << endl;

    for (int factor = 5; factor <= 50; factor += 5)
    {
        Vec V(1);

        for (int i = 0; i < factor; i++)
        {
            int num = rand();
            V.push(num);
        }

        Vec orMerge(V), orBub(V), orInsert(V), orQuick(V), orHeap(V), orShell(V);

        QueryPerformanceCounter(&t);
        BubbleSort(orBub);
        QueryPerformanceCounter(&t1);
        double Bubtime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        QueryPerformanceCounter(&t);
        InsertionSort(orInsert);
        QueryPerformanceCounter(&t1);
        double Insertime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        QueryPerformanceCounter(&t);
        MergeSort(orMerge, 0, orMerge.size() - 1);
        QueryPerformanceCounter(&t1);
        double Mergetime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        QueryPerformanceCounter(&t);
        QuickSort(orQuick, 0, orQuick.size() - 1);
        QueryPerformanceCounter(&t1);
        double Quicktime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        QueryPerformanceCounter(&t);
        HeapSort(orHeap);
        QueryPerformanceCounter(&t1);
        double Heaptime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        QueryPerformanceCounter(&t);
        ShellSort(orShell);
        QueryPerformanceCounter(&t1);
        double Shelltime = (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;

        if (outfile.is_open())
        {
            outfile << factor << "," << Bubtime << "," << Insertime << "," << Mergetime << "," << Quicktime << "," << Heaptime << "," << Shelltime << std::endl;
        }
        else
        {
            std::cerr << "Unable to open file";
        }

        cout << isSorted(orBub) << " "
             << isSorted(orInsert) << " "
             << isSorted(orMerge) << " "
             << isSorted(orQuick) << " "
             << isSorted(orHeap) << " "
             << isSorted(orShell) << " "
             << endl;

        cout << factor << "\t\t"
             << Bubtime << "\t\t"
             << Insertime << "\t\t"
             << Mergetime << "\t\t"
             << Quicktime << "\t\t"
             << Heaptime << "\t\t"
             << Shelltime << endl;
    }
    outfile.close();

    return 0;
}