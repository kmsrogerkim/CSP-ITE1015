#ifndef __SHAPES_H__
#define __SHAPES_H__

using namespace std;

class Shape 
{
    protected:
        double width, height;
    public:
        Shape(double pwidth, double pheight):width(pwidth), height(pheight){};
        virtual ~Shape(){};
        virtual double getArea() = 0;
};

class Rectangle : public Shape
{
    public:
        Rectangle(double pwidth, double pheight):Shape(pwidth, pheight){};
        ~Rectangle()override{};
        double getArea()
        {
            return width*height;
        };
};

class Triangle: public Shape 
{
    public:
        Triangle(double pwidth, double pheight):Shape(pwidth, pheight){};
        ~Triangle()override{};
        double getArea(){return (width*height)/2;};
};


#endif