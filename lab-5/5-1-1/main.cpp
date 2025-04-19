#include <iostream>
#include <vector>
#include <sstream>
#include "shapes.h"
using namespace std;

int main()
{
    int row, column;
    cin >> row >> column;
    Canvas* canvas = new Canvas(column, row);
    
    while (1)
    {
        string rect_or_square;
        cin >> rect_or_square;

        if (rect_or_square == "rect")
        {
            size_t top_left_x, top_left_y, width, height;
            char brush;

            cin >> top_left_x >> top_left_y >> width >> height >> brush;

            Rectangle* rectangle = new Rectangle(width, height, brush);
            
            cout << "Area:" << rectangle->GetArea() << endl;
            cout << "Perimeter:" << rectangle->GetPerimeter() << endl;

            for (int i = top_left_y; (i < height+top_left_y) && (i < row); i++){
                for (int j = top_left_x; j < (width+top_left_x) && (j < column); j++)
                {
                    rectangle->Draw(canvas, i, j);
                }
            }
            canvas->Print();
            canvas->Clear();

            delete rectangle;
        }
        else if (rect_or_square == "square")
        {
            size_t top_left_x, top_left_y, width;
            char brush;
            cin >> top_left_x >> top_left_y >> width >> brush;
            size_t height = width;

            Square* rectangle = new Square(width, brush);
            
            cout << "Area:" << rectangle->GetArea() << endl;
            cout << "Perimeter:" << rectangle->GetPerimeter() << endl;

            for (int i = top_left_y; (i < height+top_left_y) && (i < row); i++){
                for (int j = top_left_x; j < (width+top_left_x) && (j < column); j++)
                {
                    rectangle->Draw(canvas, i, j);
                }
            }
            canvas->Print();
            canvas->Clear();

            delete rectangle;
        }
        else if (rect_or_square == "quit") return 0;
        else cout << "Error!" << endl;
    }
    return 0;
}
