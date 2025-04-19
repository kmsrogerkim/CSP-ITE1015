#include <iostream>
#include "shapes.h"
using namespace std;

int main()
{
    Animal* animals[10];
    int i = 0;
    while (i<12)
    {
        char rect_or_square;
        cin >> rect_or_square;

        string name;
        int age;

        if (rect_or_square == 'z' && i<10)
        {
            int stripes;
            cin >> name >> age >> stripes;
            Zebra* rectangle = new Zebra(name, age, stripes);
            animals[i] = rectangle; 
        }
        else if (rect_or_square == 'c' && i<10)
        {
            string fav_toy;
            cin >> name >> age >> fav_toy;
            Cat* rectangle = new Cat(name, age, fav_toy);
            animals[i] = rectangle; 
        }
        else
        {
            for (int j=0; j<i; j++)
            {
                animals[j]->printInfo();
                delete animals[j];
            }
            return 0;
        };
        i++;
    }
    return 0;
}
