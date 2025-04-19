#ifndef __SHAPES_H__
#define __SHAPES_H__

#include <string>
#include <cmath>
using namespace std;

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
        void Resize(const size_t row,const size_t col);
        bool DrawPixel(const int x, const int y, const char brush)
        {
            // have to modify to check if in range
            if (x >= row && col >= col) return false;
            canvas[x][y] = brush;
            return true;
        };
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
        Shape(const size_t top_left_row, const size_t top_left_col, const char brush)
        {
            this->top_left_row = top_left_row;
            this->top_left_col = top_left_col;
            this->brush = brush;
        }
        // double GetArea() 
        // {
        //     return x * top_left_col;
        // };
        // int GetPerimeter() 
        // {
        //     return ((2 * x) + (2 * top_left_col));
        // };
        virtual void Draw(Canvas *canvas) const = 0;
        virtual void printInfo() const = 0;
    protected:
        size_t top_left_row, top_left_col;
        char brush;
};

class Rectangle: public Shape
{
    private:
        size_t width, height;
    public:
        Rectangle(const size_t top_left_row, const size_t top_left_col, const size_t width, const size_t height, const char brush):Shape(top_left_row, top_left_col, brush)
        {
            this->top_left_row = top_left_row;
            this->top_left_col = top_left_col;
            this->width = width;
            this->height = height;
            this->brush = brush;
        };
        // double GetArea();   
        // int GetPerimeter();
        void Draw(Canvas* canvas) const override
        {
            for (int i = top_left_row; (i < height+top_left_row); i++){
                for (int j = top_left_col; j < (width+top_left_col); j++)
                {
                    if (!canvas->DrawPixel(i, j, this->brush)) break;
                }
            }
        };
        void printInfo() const override
        {
            cout << "rect" << " " << this->top_left_col << " " << this->top_left_row << " " << width << " " << height << " " << brush;
        };
};

class UpTriangle: public Shape
{
    private:
        size_t vertex_row, vertex_col, height;
    public:
        UpTriangle(const size_t vertex_row, const size_t vertex_col, const size_t height, const char brush):Shape(vertex_row,vertex_col,brush)
        {
            this->vertex_row = vertex_row;
            this->vertex_col = vertex_col;
            this->height = height;
            this->brush = brush;
        };
        // double GetArea();   
        // int GetPerimeter();
        void Draw(Canvas* canvas) const override
        {
            size_t col = vertex_col;
            size_t row = vertex_row;
            size_t j_max = 1; 
            for (int i=0; i<height; i++)
            {
                row = vertex_row + i;
                col = vertex_col - i;
                for(int j=0; j<j_max; j++)
                {
                    if(!canvas->DrawPixel(row, (col+j), brush))
                    {
                        break;
                    }
                } 
                j_max += 2;
            }
        };
        void printInfo() const override
        {
            cout << "tri_up" << " " << this->top_left_col << " " << this->top_left_row << " " << height << " " << brush;
        };
};

class DownTriangle: public Shape
{
    private:
        size_t vertex_row, vertex_col, height;
    public:
        DownTriangle(const size_t vertex_row, const size_t vertex_col, const size_t height, const char brush):Shape(vertex_row,vertex_col,brush)
        {
            this->vertex_row = vertex_row;
            this->vertex_col = vertex_col;
            this->height = height;
            this->brush = brush;
        };
        void Draw(Canvas* canvas) const override
        {
            size_t col = vertex_col;
            size_t row = vertex_row;
            size_t j_max = 1; 
            for (int i=0; i<height; i++)
            {
                row = vertex_row - i;
                col = vertex_col - i;
                for(int j=0; j<j_max; j++)
                {
                    if(!canvas->DrawPixel(row, (col+j), brush))
                    {
                        break;
                    }
                } 
                j_max += 2;
            }
        };
        void printInfo() const override
        {
            cout << "tri_down" << " " << this->top_left_col << " " << this->top_left_row << " " << height << " " << brush;
        };
};

class Diamond: public Shape
{
    private:
        size_t vertex_row, vertex_col , center_to_vertex, height;
    public:
        Diamond(const size_t vertex_row, const size_t vertex_col, const size_t center_to_vertex, const char brush):Shape(vertex_row,vertex_col,brush)
        {
            this->vertex_row = vertex_row;
            this->vertex_col = vertex_col; 
            this-> center_to_vertex =  center_to_vertex;
            this->height = (center_to_vertex / 2) + 1;
            this->brush = brush;
        };
        void Draw(Canvas* canvas) const override
        {
            size_t col = vertex_col;
            size_t row = vertex_row;
            size_t j_max = 1; 
            for (int i=0; i<height; i++)
            {
                row = vertex_row + i;
                col = vertex_col - i;
                for(int j=0; j<j_max; j++)
                {
                    if(!canvas->DrawPixel(row, (col+j), brush))
                    {
                        break;
                    }
                } 
                j_max += 2;
            }

            size_t new_vertex_row = vertex_row + (height*2) - 2;
            row = new_vertex_row;
            col = vertex_col;
            j_max = 1; 
            for (int i=0; i<height; i++)
            {
                row = new_vertex_row - i;
                col = vertex_col - i;
                for(int j=0; j<j_max; j++)
                {
                    if(!canvas->DrawPixel(row, (col+j), brush))
                    {
                        break;
                    }
                } 
                j_max += 2;
            }
        };
        void printInfo() const override
        {
            cout << "diamond" << " " << this->top_left_col <<" " << this->top_left_row <<" " << center_to_vertex <<" " << brush;
        };
};

#endif