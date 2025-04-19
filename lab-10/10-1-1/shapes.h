#ifndef __SHAPES_H__
#define __SHAPES_H__

class MyString{
    public:
        MyString operator+(const MyString& b);
        MyString operator*(const int b);

        friend std::ostream& operator<<(std::ostream& out, MyString& my_string)
        {
            out << my_string.str;
            return out;
        };
        friend std::istream& operator>>(std::istream& in, MyString& my_string)
        {
            in >> my_string.str;
            return in;
        };
    private:
        std::string str;
};

#endif