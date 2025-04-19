#include <iostream>
#include <set>
#include <algorithm>
#include "shapes.h"

using namespace std;

void printSet(const set<int>& my_set)
{
    cout << "{ ";
    for (auto it: my_set)
    {
        cout << it << " ";
    }
    cout << "}" << endl;
}

set<int> getIntersection(const set<int>& set0, const set<int>& set1)
{
    set<int> full_set;
    set_intersection(set0.begin(), set0.end(), 
                    set1.begin(), set1.end(), 
                    inserter(full_set, full_set.begin()));
    return full_set;
}

set<int> getUnion(const set<int>& set0, const set<int>& set1)
{
    set<int> full_set;
    set_union(set0.begin(), set0.end(), 
                    set1.begin(), set1.end(), 
                    inserter(full_set, full_set.begin()));
    return full_set;
}

set<int> getDifference(const set<int>& set0, const set<int>& set1)
{
    set<int> full_set;
    for (auto num: set0)
    {
        if (set1.find(num) == set1.end())
        {
            full_set.insert(num);
        }
    }
    return full_set;
}