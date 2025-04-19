#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "shapes.h"
using namespace std;

int main()
{
    string input;
    SortedArray instance;
    while (1)
    {
        getline(cin, input);
        if (input == "add")
        {
            string nums;
            getline(cin, nums);
            istringstream iss(nums);
            
            int number;
            while (iss >> number)
            {
                instance.AddNumber(number);
            }
        }
        if (input == "ascend")
        {
            vector<int> temp = instance.GetSortedAscending();
            for (int num: temp)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        if (input == "descend")
        {
            vector<int> temp = instance.GetSortedDescending();
            for (int num: temp)
            {
                cout << num << " ";
            }
            cout << endl;
        }
        if (input == "min")
        {
            cout << instance.GetMin()<< endl;
        }
        if (input == "max")
        {
            cout << instance.GetMax() << endl;
        }
        if (input == "quit") return 0;
    }
}
