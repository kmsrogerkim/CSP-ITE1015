#include <iostream>
#include <sstream>
#include <string>
#include "shapes.h"

using namespace std;

void add_num(MyVector& first_instance, const int b)
{
    MyVector res = first_instance + b;
    cout << res << endl;
}
void add_instance(MyVector& first_instance, MyVector& second_instance)
{
    MyVector res = first_instance + second_instance;
    cout << res << endl;
}

void subtract_num(MyVector& first_instance, const int b)
{
    MyVector res = first_instance - b;
    cout << res << endl;
}
void subtract_instance(MyVector& first_instance, MyVector& b)
{
    MyVector res = first_instance - b;
    cout << res << endl;
}

int main()
{
    MyVector* a = nullptr;
    MyVector* b = nullptr;
    string command;
    while (1)
    {
        cin >> command;
        if (command == "new")
        {
            int len;
            cin >> len;

            if (a && b) 
            {
                delete a;
                delete b;
            }
            a = new MyVector(len);
            b = new MyVector(len);

            cout << "enter a" << endl;
            string line_inpt;
            cin.get();
            getline(cin, line_inpt);
            istringstream iss(line_inpt); 
            iss >> *a;

            cout << "enter b" << endl;
            getline(cin, line_inpt);
            iss.clear();
            iss.str(line_inpt); 
            iss >> *b;

            continue;
        }
        else if (command == "quit") return 0;
        else
        {
            if (!a && !b) continue;

            char first_inpt = command[0];
            char opt;
            string second_inpt;
            bool second_inpt_num = false;

            cin >> opt >> second_inpt;
            int num;
            int ascii_second_inpt = static_cast<int>(second_inpt[0]);

            if (ascii_second_inpt > 47 && ascii_second_inpt < 58)
            {
                // if integer is inputed after the operator
                num = stoi(second_inpt);
                second_inpt_num = true;  
            }

            if (opt == '+')
            {
                if (second_inpt_num)
                {
                    if (first_inpt == 'a') add_num(*a, num);
                    else add_num(*b, num);
                }
                else
                {
                    if (first_inpt == 'a' && second_inpt == "b") add_instance(*a, *b);
                    if (first_inpt == 'a' && second_inpt == "a") add_instance(*a, *a);
                    if (first_inpt == 'b' && second_inpt == "a") add_instance(*b, *a);
                    if (first_inpt == 'b' && second_inpt == "b") add_instance(*b, *b);
                }
            }
            else if (opt == '-')
            {
                if (second_inpt_num)
                {
                    if (first_inpt == 'a') subtract_num(*a, num);
                    else subtract_num(*b, num);
                }
                else
                {
                    if (first_inpt == 'a' && second_inpt == "b") subtract_instance(*a, *b);
                    if (first_inpt == 'a' && second_inpt == "a") subtract_instance(*a, *a);
                    if (first_inpt == 'b' && second_inpt == "a") subtract_instance(*b, *a);
                    if (first_inpt == 'b' && second_inpt == "b") subtract_instance(*b, *b);
                }
            }
        }
        continue;
    }
}
