#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
    A* arr[3];
    arr[0] = new A();
    arr[1] = new B();
    arr[2] = new C();

    for (int i=0; i<3; i++)
    {
        arr[i]->test();
        delete arr[i];
    }
    return 0;
}
