#include <iostream>
#include "Vec.h"
#include "sorts.h"

using namespace std;

int main()
{
    Vec V(1);

V.push(5);
V.push(3);
V.push(8);
V.push(1);

Vec D = V;  //Vec D(V);
D.push(9);
D.push(7);

cout <<"Before: "<< V << endl;

BubbleSort(V);

cout <<"After BubbleSort:  "<< V << endl;

cout <<"Before: "<< D << endl;

InsertionSort(D);

cout <<"After InsertionSort: "<< D << endl;

return 0;
}