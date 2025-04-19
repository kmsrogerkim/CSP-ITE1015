#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
    while (1){
        char inpt;
        cout << "shape?" << endl;
        cin >> inpt;
        if (inpt == 'C')
        {
            int x, y, r;
            cin >> x >> y >> r;

            Circle circle;
            circle.setInfo(x,y,r);

            double area, perimeter;
            area = circle.getArea();
            perimeter = circle.getPerimeter();

            cout << "area:" << area << ",perimeter:" <<perimeter << endl;
        }
        else if (inpt == 'R')
        {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            Rectangle rectangle;
            rectangle.setInfo(x1, y1, x2, y2);

            double area, perimeter;
            area = rectangle.getArea();
            perimeter = rectangle.getPerimeter();

            cout << "area:" << area << ",perimeter:" <<perimeter << endl;
        }
        else return 0;
    }
    return 0;
}
