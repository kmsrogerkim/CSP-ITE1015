#ifndef __ZEBRA_H__
#define __ZEBRA_H__

#include <string>

class Zebra
{
    public:
        Zebra(std::string _name, int _age, int _numStripes);
        void printZebra();

    private:
        std::string name;
        int age;
        int numStripes;
};

#endif