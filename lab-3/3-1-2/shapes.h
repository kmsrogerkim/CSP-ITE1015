#ifndef __SHAPES_H__
#define __SHAPES_H__
class Circle
{
    private:
        int xpos, ypos;
        int radius;
    public:
        void setInfo(int x, int y, int r);
        double getArea();
        double getPerimeter();
};

class Rectangle
{
    private:
        int xpos1, ypos1;
        int xpos2, ypos2;
    public:
        void setInfo(int x1, int y1, int x2, int y2);
        double getArea();
        double getPerimeter();
};
#endif