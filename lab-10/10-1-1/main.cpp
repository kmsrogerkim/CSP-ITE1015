#include <iostream>
#include <sstream>
#include <string>
#include "shapes.h"
using namespace std;

int main()
{
    MyString a, b;
    string command;
    while (1)
    {
        cin >> command;
        if (command == "new")
        {
            cout << "enter a" << endl;
            cin >> a;
            cout << "enter b" << endl;
            cin >> b;
            continue;
        }
        else if (command == "quit") return 0;
        else
        {
            string first_inpt = command;
            string opt;

            string line_inpt;
            getline(cin, line_inpt);
            istringstream iss(line_inpt);

            MyString* first_instance;

            iss >> opt;

            if (first_inpt == "a") first_instance = &a;
            else if (first_inpt == "b") first_instance = &b;
            MyString cpy_first_instance = *first_instance;

            if (opt == "+")
            {
                MyString* second_instance;

                string second_inpt;
                iss >> second_inpt;

                if (second_inpt == "a") second_instance = &a;
                else if (second_inpt == "b") second_instance = &b;
                MyString cpy_second_instance= *second_instance;

                MyString res_string;
                res_string = (*first_instance) + (*second_instance);
                cout << res_string << endl;

                // taking stuff back
                *second_instance = cpy_second_instance;
            }
            else if (opt == "*")
            {
                int second_inpt;
                iss >> second_inpt;

                MyString res_string;
                res_string = (*first_instance) * second_inpt;
                cout << res_string << endl;
            }
            *first_instance = cpy_first_instance;
        }
        continue;
    }
    return 0;
}