#include <iostream>
#include "Vec.h"

using namespace std;

int main()
{
    Vec v(1);

    v.push(10);
    v.push(20);
    v.push(30);

    cout<< v.get(0) << " "
    << v.get(1) << " "
    << v.get(2) << endl;

    return 0;
}