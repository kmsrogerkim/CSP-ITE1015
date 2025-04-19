#include <iostream>
#include "zebra.h"
using namespace std;

int main()
{
    Zebra** zebra_arr = new Zebra* [10];
    int num_zebras = 0;

    while (num_zebras < 10)
    {
        string name;
        cin >> name;
        if (name == "0")
        {
            for (int i=0; i<num_zebras; i++)
            {
                zebra_arr[i]->printZebra();
            }
            return 0;
        };

        int age, numstripes;
        cin >> age >> numstripes;

        Zebra* new_zebra = new Zebra(name, age, numstripes);
        zebra_arr[num_zebras] = new_zebra;
        num_zebras += 1;
    }

    for (int i=0; i<10; i++)
    {
        zebra_arr[i]->printZebra();
    }
    return 0;
}
