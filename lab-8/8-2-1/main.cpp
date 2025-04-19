#include <iostream>
#include "shapes.h"
#include <vector>
using namespace std;

int main()
{
    vector<Shape*> shapes;

    double w1, h1, w2, h2;
    cin >> w2 >> h2;
    cin >> w1 >> h1;

    Triangle* triangle = new Triangle(w2,h2);
    Rectangle* rectangle = new Rectangle(w1, h1);
    shapes.push_back(triangle);
    shapes.push_back(rectangle);
    for (vector<Shape*>::iterator itr = shapes.begin(); itr!=shapes.end(); itr++)
    {
        cout << (*itr)->getArea() << endl;
        delete (*itr);
    }
}
