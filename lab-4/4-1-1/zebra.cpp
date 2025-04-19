#include <iostream>
#include "zebra.h"

Zebra::Zebra(std::string _name, int _age, int _numStripes)
{
    name = _name;
    age = _age;
    numStripes = _numStripes;
}

void Zebra::printZebra()
{
    std::cout << "Name: " << name << ", Age: " << age << ", Number of stripes: " << numStripes << std::endl;
}