#ifndef __SHAPES_H__
#define __SHAPES_H__
#include <iostream>
using namespace std;

template <class T>
class MyContainer
{
    public:
        MyContainer(int size) 
        {
            n_elements = size;
            obj_arr = new T[n_elements];
        }; 
        ~MyContainer() 
        {
            delete[] obj_arr;
        };
        void clear() {};
        int size() {return this->n_elements;}

        template <class U>
        friend std::istream& operator>> (std::istream& in, MyContainer<U>& b);
        template <class U>
        friend std::ostream& operator<< (std::ostream& out, MyContainer<U>& b);
    protected:
        T* obj_arr= nullptr;
        int n_elements;
};

template <class T>
istream& operator>> (std::istream& in, MyContainer<T>& b)
{
    for (int i=0; i<b.size(); i++)
    {
        in >> b.obj_arr[i];
    }
    return in;
};
template <class T>
ostream& operator<< (std::ostream& out, MyContainer<T>& b)
{
    for (int i = 0; i < b.size(); i++) {
        out << b.obj_arr[i] << " "; 
    }
    return out;
};

#endif