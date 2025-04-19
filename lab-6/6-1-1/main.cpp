#include <iostream>
#include <vector>
#include <sstream>
#include "shapes.h"
using namespace std;

int main()
{
    Shape* shapes[10];
    int i = 0;
    while (i<12)
    {
        char rect_or_square;
        cin >> rect_or_square;

        double width, height;

        if (rect_or_square == 'r' && i<10)
        {
            cin >> width >> height;
            Rectangle* rectangle = new Rectangle(width, height);
            // Rectangle rectangle = Rectangle(width, height);
            shapes[i] = rectangle; 
        }
        else if (rect_or_square == 't' && i<10)
        {
            cin >> width >> height;
            Triangle* rectangle = new Triangle(width, height);
            shapes[i] = rectangle; 
        }
        else
        {
            if (i==0) return 0;
            for (int j=0; j<i; j++)
            {
                cout << shapes[j]->getArea() << endl;
                delete shapes[j];
            }
            return 0;
        };
        i++;
    }
    return 0;
}
