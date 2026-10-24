#include <iostream>
#include "Vec.h"
#include "sorts.h"

using namespace std;

int main()
{
    Vec v(1);

v.push(5);
v.push(3);
v.push(8);
v.push(1);

cout <<"Before: "<< v << endl;

BubbleSort(v);

cout <<"After:  "<< v << endl;

return 0;
}