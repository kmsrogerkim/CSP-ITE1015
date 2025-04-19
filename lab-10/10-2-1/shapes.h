#ifndef __SHAPES_H__
#define __SHAPES_H__

class MyVector{
    public:
        MyVector() : length(0), a(NULL) {}
        MyVector(int length) : length(length) {
            a = new int[length]();
        };
        ~MyVector() {
            delete[] a;
        };

        MyVector& operator=(const MyVector& b) {
            if (this == &b) return *this; 
            delete[] a; 

            length = b.length;
            a = new int[length];
            for (int i = 0; i < length; ++i) {
                a[i] = b.a[i];
            }
            return *this;
        };
        MyVector operator+(const MyVector& b) {
            MyVector result(length);
            for (int i = 0; i < length; ++i) {
                result.a[i] = a[i] + b.a[i];
            }
            return result;
        }
        MyVector operator-(const MyVector& b) {
            MyVector result(length);
            for (int i = 0; i < length; ++i) {
                result.a[i] = a[i] - b.a[i];
            }
            return result;
        };
        MyVector operator+(const int b) {
            MyVector result(length);
            for (int i = 0; i < length; ++i) {
                result.a[i] = a[i] + b;
            }
            return result;
        };
        MyVector operator-(const int b) {
            MyVector result(length);
            for (int i = 0; i < length; ++i) {
                result.a[i] = a[i] - b;
            }
            return result;
        };

        friend std::ostream& operator<<(std::ostream& out, const MyVector& b) {
            for (int i = 0; i < b.length; ++i) {
                out << b.a[i] << " ";
            }
            return out;
        };
        friend std::istream& operator>>(std::istream& in, MyVector& b) {
            for (int i = 0; i < b.length; ++i) {
                in >> b.a[i];
            }
            return in;
        };
    private:
        int length;
        int *a;
};

#endif