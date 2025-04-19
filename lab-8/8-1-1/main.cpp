#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
    IntegerSet int_set;
    while (1)
    {
        string inpt;
        cin >> inpt;
        if (inpt == "add")
        {
            int num;
            cin >> num;
            int_set.AddNumber(num);
        }
        if (inpt == "del")
        {
            int num;
            cin >> num;
            int_set.DeleteNumber(num);
        }
        if (inpt == "get")
        {
            int num;
            cin >> num;
            num = int_set.GetItem(num);
            cout << num << endl;
            continue;
        }
        if (inpt == "quit")
        {
            return 0;
        }
        
        vector<int> vec = int_set.GetAll();
        for (int i=0; i<vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}