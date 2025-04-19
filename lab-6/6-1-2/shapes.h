#ifndef __ANIMAL_H__
#define __ ANIMAL _H__

#include <string>
using namespace std;

class Animal
{
    public:
        Animal(string _name, int _age):name(_name), age(_age) {};
        virtual void printInfo()=0;
         // must modify this into a pure virtual function
    protected:
        string name;
        int age;
};
class Zebra : public Animal
{
    private:
        int stripes;
    public:
        Zebra(string name, int age, int stripes) : Animal(name, age)
        {
            this->stripes = stripes; 
        };
        void printInfo()
        {
            cout << "Zebra, Name:" << name << ", Age: " << age << ", Number of stripes: " << stripes << endl;
        }
};
class Cat : public Animal
{
    private:
        string favoriteToy;
    public:
        Cat(string name, int age, string favoriteToy) : Animal(name, age)
        {
            this->favoriteToy = favoriteToy; 
        };
        void printInfo()
        {
            cout << "Cat, Name:" << name << ", Age: " << age << ", Favorite toy: " << favoriteToy << endl;
        }
};
#endif