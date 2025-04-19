#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <map>
#include <cstring>
using namespace std;

// Vector
// int main()
// {
//     vector<int> my_vec = {1,2};
//     my_vec.resize(5);

//     for (auto i = my_vec.begin(); i != my_vec.end(); i++)
//     {
//         cout << *i << " ";
//     }
//     cout << endl;
//     return 0;
// }

// list
// int main()
// {
//     list<int> lst = {1,2,3,4,5};
//     auto itr = lst.begin();
//     itr++;
//     itr = lst.insert(itr, 100);
//     cout << *itr << endl; // 100
//     for (auto i = lst.begin(); i != lst.end(); i++)
//     {
//         cout << *i << " ";
//     }
//     cout << endl;
//     return 0;
// }

// stack
// int main()
// {
//     stack<int> st;
//     st.push(10);
//     st.push(20);
//     st.top() -= 5;
//     cout << st.top() << endl;
//     return 0;
// }

// map
// int main()
// {
//     map<string, int> m;
//     m.insert(make_pair("a", 1));
//     for (auto i = m.begin(); i != m.end(); i++)
//     {
//         cout << i-> first << " " << i->second << endl;
//     }
//     m.insert(make_pair("a", 2));
//     for (auto i = m.begin(); i != m.end(); i++)
//     {
//         cout << i-> first << " " << i->second << endl;
//     }
//     return 0;
// }

// ----- copy constructor -----
// class A
// {
//     private:
//         int x;
//         // friend class B;
//         // friend void do_sth(const A& obj);
// };

// class B : public A
// {
//     private:
//         int x, y;
//         friend class A; // this wouldn't do anything now since A is parent
//     public:
//         B(){};
//         B(const B& obj)
//         {
//             x = obj.x;
//             y = obj.y;
//         };
//         B(const A& obj)
//         {
//             x = obj.x; // this would cause error without the friend in the class A
//         };
//         void do_sth(const A& obj) { cout << obj.x << endl; }; // cause error too without friend
// }


// ----- operator overloading -----
// class Point
// {
//     private:
//         int x, y, z;
//     public:
//         Point(int a, int b, int c): x(a), y(b), z(c) {};
//         Point operator=(const Point& pt)
//         {
//             x = pt.x; y = pt.y; z = pt.z;
//             return *this;
//         }
//         void print()
//         {
//             cout << x << " " << y << " " << z << endl;
//         }
// };

// int main()
// {
//     Point p1(1,1,1);
//     Point p2(2,2,2);
//     Point p3(3,3,3);
//     (p1 = p2) = p3;
//     p1.print();
//     p2.print();
//     p3.print();
// }

// ------ Template ------
// class Point
// {
//     public:
//         Point(){cout << "Point created" << endl;}
// };
// class Shape
// {
//     public:
//         void display() {cout << "show" << endl;}
// };
// template<class T, class U>
// class Rectangle: public T
// {
//     public:
//         vector<U> vec;
//         void display() { T::display();}
// };

// int main()
// {
//     // testing exit and abort
//     // std::abort();
//     // std::exit(2);
//     return 1;
//     Rectangle<Shape, int> rt2;
//     rt2.display();
//     rt2.vec.push_back(1);
//     for (auto i = rt2.vec.begin(); i!=rt2.vec.end(); i++)
//     {
//         cout << *i << endl;
//     }
//     return 0;
// }

// ------ Exception Handling -----
// class ExceptionA {};
// class ExceptionB: public ExceptionA {};
// int main()
// {
//     try
//     {
//         throw ExceptionA();
//     }
//     catch(const ExceptionB& e)
//     {
//         cout << "whatever" << endl;
//     }
//     catch(const std::exception& e)
//     {
//         cout << "std::exception" << endl;
//     }
//     return 0; 
// }

// ----- new -----
// int main()
// {
//     int* arr = new int[10];
//     for (int i=0; i<10; i++)
//     {
//         arr[i] = i;
//     }
//     for (int i=0; i<10; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;

//     cout << *arr << endl;
//     delete[] arr;
//     cout << *arr << endl;
//     cout << " start " << endl;
//     for (int i=0; i<10; i++)
//     {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// More copy constructors
class MyString
{
    private:
        int len;
        char* str;
    public:
        MyString(const char *s = "")
        {
            len = strlen(s);
            str = new char[len+1];
            strcpy(str, s);            
        }
        void Print() { cout << str << endl; }
};
MyString get_instance()
{
    MyString str("HY");
    return str;
}
int main()
{
    MyString s1 = get_instance();
    s1.Print();
    return 0;
}