#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <string>
#include <cmath>

class Canvas
{
    public:
        Canvas(const size_t row, const size_t col)
        {
            this->row = row;
            this->col = col;

            canvas = new char*[row];
            for (size_t i = 0; i < row; ++i) {
                canvas[i] = new char[col];
            } 

            for (size_t i = 0; i < row; ++i) {
                for (size_t j = 0; j < col; ++j) {
                    canvas[i][j] = '.'; // Fill each element with '.'
                }
            }
        };
        ~Canvas()
        {
            for (size_t i = 0; i<row; i++)
            {
                delete[] canvas[i];
            }
            delete[] canvas;
        };
        bool DrawPixel(const int x, const int y, const char brush);
        void Print() const;
        void Clear();
    private:
        size_t row, col;
        char **canvas;
};

class Shape 
{
    public:
        Shape();
        Shape(const size_t x, const size_t y, const char brush)
        {
            this->x = x;
            this->y = y;
            this->brush = brush;
        }
        double GetArea() 
        {
            return x * y;
        };
        int GetPerimeter() 
        {
            return ((2 * x) + (2 * y));
        };
        void Draw(Canvas *canvas) const 
        {
            // canvas->DrawPixel()
        };
    protected:
        size_t x, y;
        char brush;
};

class Square : public Shape
{
    public:
        Square();
        Square(const size_t x, const char brush);
        double GetArea();
        int GetPerimeter();
        void Draw(Canvas* canvas, int x, int y);
};

class Rectangle : public Shape
{
    public:
        Rectangle();
        Rectangle(const size_t x, const size_t y, const char brush);
        double GetArea();   
        int GetPerimeter();
        void Draw(Canvas* canvas, int x, int y);
};

#endif