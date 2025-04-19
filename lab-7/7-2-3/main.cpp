#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
    A* arr[3];
    int a;
    double b;
    string c;
    cin >> a >> b >> c;

    arr[0] = new A(a);
    arr[1] = new B(b);
    arr[2] = new C(c);

    for (int i=0; i<3; i++)
    {
        arr[i]->print();
    }
    for (int i=0; i<3; i++)
    {
        delete arr[i];
    }
    return 0;
}
