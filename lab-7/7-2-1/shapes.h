#ifndef __SHAPES_H__
#define __SHAPES_H__

using namespace std;

class A 
{
    public:
        virtual void test(){
            cout << "A::test()" << endl;
        };
};

class B : public A 
{
    public:
        virtual void test(){
            cout << "B::test()" << endl;
        };
};

class C: public B 
{
    public:
        virtual void test(){
            cout << "C::test()" << endl;
        };
};


#endif