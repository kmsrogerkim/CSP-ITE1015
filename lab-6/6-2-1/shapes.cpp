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
void Canvas::Print() const {
    cout << " ";

    for (int i= 0; i< this->col; ++i) cout<< (i% 10);
    cout<< endl;

    for (int i= 0; i< this->row; ++i) 
    {
        cout<< (i% 10);
        for (int j = 0; j < this->col; ++j) cout<< this->canvas[i][j];
        cout<< endl;
    }
}

void Canvas::Clear() {
    this->canvas = init(this->canvas, this->row, this->col); 
}

void Canvas::Resize(const size_t row,const size_t col)
{
    this->row = row;
    this->col = col;
    this->canvas = init(this->canvas, row, col); 
};


// Rectangle----------------------------------------------------------------------
// double Rectangle::GetArea()
// {
//     return Shape::GetArea();
// }

// int Rectangle::GetPerimeter()
// {
//     return Shape::GetPerimeter();
// }

// void Rectangle::Draw(Canvas* canvas, int x, int y)
// {
//     canvas->DrawPixel(x, y, this->brush);
// }
