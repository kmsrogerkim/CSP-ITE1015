#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
    int row, column;
    cin >> row >> column;
    Canvas* canvas = new Canvas(column, row);
    Shape* shapes[10];

    int num_shapes = 0;
    while (1)
    {
        string command;
        cin >> command;

        if (command == "add")
        {
            string rect_or_square;
            cin >> rect_or_square;

            if (rect_or_square == "rect")
            {
                size_t top_left_col, top_left_row, width, height;
                char brush;

                cin >> top_left_row >> top_left_col >> width >> height >> brush;

                Rectangle* rectangle = new Rectangle(top_left_row, top_left_col, width, height, brush);
                shapes[num_shapes] = rectangle;
                num_shapes++;    
            }
            else if (rect_or_square == "tri_up")
            {
                size_t top_left_col, top_left_row, height;
                char brush;

                cin >> top_left_row >> top_left_col >> height >> brush;

                UpTriangle* rectangle = new UpTriangle(top_left_row, top_left_col, height, brush);
                shapes[num_shapes] = rectangle;
                num_shapes++;    
            }
            else if (rect_or_square == "tri_down")
            {
                size_t top_left_col, top_left_row, height;
                char brush;

                cin >> top_left_row >> top_left_col >> height >> brush;

                DownTriangle* rectangle = new DownTriangle(top_left_row, top_left_col, height, brush);
                shapes[num_shapes] = rectangle;
                num_shapes++;    
            }
            else if (rect_or_square == "diamond")
            {
                size_t top_left_col, top_left_row, width;
                char brush;

                cin >> top_left_row >> top_left_col >> width >> brush;

                Diamond* rectangle = new Diamond(top_left_row, top_left_col, width, brush);
                shapes[num_shapes] = rectangle;
                num_shapes++;    
            }
        }
        else if (command=="draw")
        {
           for (int i=0; i<num_shapes; i++) 
           {
                shapes[i]->Draw(canvas);
           }
            canvas->Print();
            canvas->Clear();
        }
        else if (command=="resize")
        {
            size_t row, col;
            cin >> row >> col;
            delete canvas;
            canvas = new Canvas(col, row);
        }
        else if (command=="dump")
        {
            for (int i=0; i<num_shapes; i++)
            {
                cout << i << " ";
                shapes[i]->printInfo();
                cout << endl;
            }
        }
        else if (command=="delete")
        {
            int index;
            cin >> index;

            if (index >= num_shapes) continue;
           
            delete shapes[index];
            for (int i=index; i<num_shapes; i++)
            {
                if (i!=9)
                {
                    shapes[i] = shapes[i+1];
                }
            }
            // delete shapes[num_shapes-1];
            num_shapes -= 1;
            // for (int i=0; i<num_shapes; i++)
            // {
            //     shapes[i]->printInfo();
            //     cout << endl;
            // }
        }
        else if (command=="quit") return 0;

    }
    return 0;
}
