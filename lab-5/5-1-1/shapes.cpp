#include <iostream>
#include "shapes.h"

using namespace std;

static char** init(char** matrix, const size_t row, const size_t col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            matrix[i][j] = '.';
        }
    }
    return matrix;
}

static char** auto_alloc(const size_t row, const size_t col) {
    char** matrix = new char*[row]; 
    for (int i = 0; i < row; ++i) {
        matrix[i] = new char[col];  
    }
    matrix = init(matrix, row, col); 
    return matrix;
}

static void auto_delete(char** matrix, const size_t row, const size_t col) {
    for (int i = 0; i < row; ++i) {
        delete[] matrix[i];  
    }
    delete[] matrix;     
}

// Canvas----------------------------------------------------------------------
bool Canvas::DrawPixel(const int x, const int y, const char brush)
{
    canvas[x][y] = brush;
    return true;
}

void Canvas::Print() const {
    cout << " ";

    for (int i = 0; i < this->col; ++i) {
        cout << i;
    }
    cout << endl;

    for (int i = 0; i < this->row; ++i) {
        cout << i; 

        for (int j = 0; j < this->col; ++j) {
            cout << this->canvas[i][j]; 
        }
        cout << endl;
    }
}

void Canvas::Clear() {
    this->canvas = init(this->canvas, this->row, this->col); 
}

// Square----------------------------------------------------------------------
Square::Square(const size_t x, const char brush) : Shape(x,x,brush)
{}

double Square::GetArea()
{
    return Shape::GetArea();
}

int Square::GetPerimeter()
{
    return Shape::GetPerimeter();
}

void Square::Draw(Canvas* canvas, int x, int y)
{
    canvas->DrawPixel(x, y, this->brush);
}

// Rectangle----------------------------------------------------------------------
Rectangle::Rectangle(const size_t x, const size_t y, const char brush) : Shape(x,y,brush)
{
    this->x = x;
    this->y = y;
    this->brush = brush;
}

double Rectangle::GetArea()
{
    return Shape::GetArea();
}

int Rectangle::GetPerimeter()
{
    return Shape::GetPerimeter();
}

void Rectangle::Draw(Canvas* canvas, int x, int y)
{
    canvas->DrawPixel(x, y, this->brush);
}
