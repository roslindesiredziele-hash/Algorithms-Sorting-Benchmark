#include "Vec.h"
#include "sorts.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ofstream outfile("./data/data.csv");

     if (!outfile)
        {
            std::cerr << "Unable to open data.csv\n";
            return 1;
        }
        
    outfile
    << "InputSize,"
    << "BubbleSort,"
    << "InsertionSort,"
    << "MergeSort,"
    << "QuickSort,"
    << "HeapSort,"
    << "ShellSort"
    << endl;

    srand(time(NULL));

    LARGE_INTEGER t, t1, f;
    QueryPerformanceFrequency(&f);

    const int runs = 10;

    Vec sizes(1);
    sizes.push(5);
    sizes.push(10);
    sizes.push(20);
    sizes.push(30);
    sizes.push(40);
    sizes.push(50);
    sizes.push(100);
    sizes.push(200);
    sizes.push(300);
    sizes.push(400);
    sizes.push(500);
    sizes.push(1000);
    sizes.push(1200);
    sizes.push(1400);
    sizes.push(1600);
    sizes.push(1800);
    sizes.push(2000);

    cout << sizes << endl;

    cout << "Input-sizes\tBubble\t\tInsertion\tMerge\t\tQuick\t\tHeap\t\tShell\t\tIsSorted" << endl;

    cout << fixed << setprecision(3);

    for (int factor : sizes)
    {
        Vec V(1);

        for (int i = 0; i < factor; i++)
        {
            V.push(rand());
        }

        double bubbleTotal = 0;
        double insertionTotal = 0;
        double mergeTotal = 0;
        double quickTotal = 0;
        double heapTotal = 0;
        double shellTotal = 0;

        bool bubbleOK = true;
        bool insertionOK = true;
        bool mergeOK = true;
        bool quickOK = true;
        bool heapOK = true;
        bool shellOK = true;

        for (int run = 0; run < runs; run++)
    {
        Vec orMerge(V), orBub(V), orInsert(V), orQuick(V), orHeap(V), orShell(V);

        QueryPerformanceCounter(&t);
        BubbleSort(orBub);
        QueryPerformanceCounter(&t1);
        bubbleTotal += (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
        bubbleOK &= isSorted(orBub);

        QueryPerformanceCounter(&t);
        InsertionSort(orInsert);
        QueryPerformanceCounter(&t1);
        insertionTotal += (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
        insertionOK &= isSorted(orInsert);

        QueryPerformanceCounter(&t);
        MergeSort(orMerge, 0, orMerge.size() - 1);
        QueryPerformanceCounter(&t1);
        mergeTotal += (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
        mergeOK &= isSorted(orMerge);

        QueryPerformanceCounter(&t);
        QuickSort(orQuick, 0, orQuick.size() - 1);
        QueryPerformanceCounter(&t1);
        quickTotal += (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
         quickOK &= isSorted(orQuick);

        QueryPerformanceCounter(&t);
        HeapSort(orHeap);
        QueryPerformanceCounter(&t1);
        heapTotal += (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
        heapOK &= isSorted(orHeap);

        QueryPerformanceCounter(&t);
        ShellSort(orShell);
        QueryPerformanceCounter(&t1);
        shellTotal += (t1.QuadPart - t.QuadPart) * 1000.0 / f.QuadPart;
         shellOK &= isSorted(orShell);

    }
    
    double Bubtime = bubbleTotal / runs;
        double Insertime = insertionTotal / runs;
        double Mergetime = mergeTotal / runs;
        double Quicktime = quickTotal / runs;
        double Heaptime = heapTotal / runs;
        double Shelltime = shellTotal / runs;

        outfile << factor << "," << Bubtime << "," << Insertime << "," << Mergetime << "," << Quicktime << "," << Heaptime << "," << Shelltime << endl;

        

        cout << factor << "\t\t"
             << Bubtime << "\t\t"
             << Insertime << "\t\t"
             << Mergetime << "\t\t"
             << Quicktime << "\t\t"
             << Heaptime << "\t\t"
             << Shelltime << "\t\t"
            << bubbleOK << " "
            << insertionOK << " "
            << mergeOK << " "
            << quickOK << " "
            << heapOK << " "
            << shellOK << endl;
    }

    outfile.close();

    return 0;
}