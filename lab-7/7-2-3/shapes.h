#ifndef __SHAPES_H__
#define __SHAPES_H__

using namespace std;

class A 
{
    private:
        int* memberA;
    public:
        A(int num)
        {
            memberA = new int;
            *memberA = num;
            cout << "new memberA" << endl;
        };
        virtual ~A()
        {
            delete memberA;
            cout << "delete memberA" << endl;
        };

        virtual void print()
        {
            cout << "*memberA " << *memberA << endl;
        };
};

class B : public A 
{
    private:
        double* memberB;
    public:
        B(double num) : A(1)
        {
            memberB = new double;
            *memberB = num;
            cout << "new memberB" << endl;
        };
        virtual ~B()
        {
            delete memberB;
            cout << "delete memberB" << endl;
        };
        virtual void print()
        {
            A::print();
            cout << "*memberB " << *memberB << endl;
        };
};


class C: public B 
{
    private:
        string* memberC;
    public:
        C(string num) : B(1.1)
        {
            memberC = new string;
            *memberC = num;
            cout << "new memberC" << endl;
        };
        virtual ~C()
        {
            delete memberC;
            cout << "delete memberC" << endl;
        };
        virtual void print()
        {
            B::print();
            cout << "*memberC " << *memberC << endl;
        };
};


#endif