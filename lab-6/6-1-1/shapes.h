#ifndef __SHAPES_H__
#define __SHAPES_H__
class Shape
{
    public:
        Shape(double width, double height) : width(width), height(height){};
        virtual double getArea() = 0;
         // must modify this into a pure virtual function
        protected:
            double width, height;
};

class Triangle : public Shape
{
    public:
        // Triangle(){};
        Triangle(double _width, double _height) : Shape(_width, _height) {};
        virtual double getArea()
        {
            return (width*height)/2;
        };
};

class Rectangle : public Shape
{
    public:
        // Rectangel(){};
        Rectangle(double _width, double _height) : Shape(_width, _height) {};
        virtual double getArea()
        {
            return width*height;
        };
};

# endif