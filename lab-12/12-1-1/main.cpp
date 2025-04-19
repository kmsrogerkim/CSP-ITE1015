#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "shapes.h"
using namespace std;

int main()
{
    for (int i=0; i<3; i++)
    {
        int size;
        cin >> size;
        cin.ignore();

        string input;
        getline(cin, input);
        istringstream iss(input);
        
        if (i==0) 
        {
            MyContainer<int> my_container(size);
            iss >> my_container; 
            cout << my_container << endl;
        }
        if (i==1) 
        {
            MyContainer<double> my_container(size);
            iss >> my_container; 
            cout << my_container << endl;
        }
        else 
        {
            MyContainer<string> my_container(size);
            iss >> my_container; 
            cout << my_container << endl;
        }
    }
    return 0;
}