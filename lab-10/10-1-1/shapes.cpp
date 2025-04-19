#include <iostream>
#include "shapes.h"

using namespace std;

MyString MyString::operator+(const MyString& b) 
{
    string res_str = this->str + b.str;
    this->str = res_str;
    return (*this);
}
MyString MyString::operator*(const int b) 
{
    string res;
    for (int i = 0; i < b; ++i) {
        res += str; 
    }
    this->str = res;
    return (*this);
}
