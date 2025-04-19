#ifndef __SHAPES_H__
#define __SHAPES_H__

using namespace std;

class A 
{
    public:
        virtual string getTypeInfo(){
            string ans = "This is an instance of class A";
            return ans;
        };
};

class B : public A 
{
    public:
        virtual string getTypeInfo(){
            string ans = "This is an instance of class B";
            return ans;
        };
};

class C: public B 
{
    public:
        virtual string getTypeInfo(){
            string ans = "This is an instance of class C";
            return ans;
        };
};


#endif