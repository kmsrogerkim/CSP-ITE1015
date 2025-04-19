#include <iostream>
#include <set>

#include "shapes.h"

using namespace std;

int main()
{
    string inpt;
    string opt;
    set<int> setA;
    set<int> setB;

    int count = 0;
    set<int>* temp_set = &setA;
    while(1)
    {
        cin >> inpt;
        if (inpt == "0") return 0;
        if (inpt == "}") count++;
        if (count == 2)
        {
            set<int> full_set;
            if (opt == "+")
            {
                full_set = getUnion(setA, setB);
                printSet(full_set);
            }
            if (opt == "*")
            {
                full_set = getIntersection(setA, setB);
                printSet(full_set);
            }
            if (opt == "-")
            {
                full_set = getDifference(setA, setB);
                printSet(full_set);
            }
            count = 0;
            temp_set = &setA;
            setA.clear();
            setB.clear();
            continue;
        }

        if (inpt == "+" || inpt == "*" || inpt == "-")
        {
            temp_set = &setB;
            opt = inpt;
            continue;
        }

        if (inpt == "{" || inpt == "}") continue;

        int digit = stoi(inpt); 
        temp_set->insert(digit);
    }
}
