#include "shapes.h"
#include <cmath>

void Circle::setInfo(int x, int y, int r)
{
    xpos = x;
    ypos = y;
    radius = r;
}

double Circle::getArea()
{
    return (3.14*radius*radius);
}

double Circle::getPerimeter()
{
    return (2*3.14*radius);
}

void Rectangle::setInfo(int x1, int y1, int x2, int y2)
{
    xpos1 = x1;
    xpos2 = x2;
    ypos1 = y1;
    ypos2 = y2;
}
double Rectangle::getArea()
{
    return (std::abs(xpos2-xpos1) * std::abs(ypos2-ypos1));
}
double Rectangle::getPerimeter()
{
    return (std::abs(xpos2-xpos1)*2 + std::abs(ypos2-ypos1)*2);
}