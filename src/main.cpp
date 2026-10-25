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

cout <<"Before: "<< V << endl;

BubbleSort(V);

cout <<"After:  "<< V << endl;

return 0;
}