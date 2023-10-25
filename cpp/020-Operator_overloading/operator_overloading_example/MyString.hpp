#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#include <iostream>
#include <cstring>

class MyString
{
private:
    static int num_objects;
public:
    char *myStr;

    static int get_num_objects();

    /* Operator overloading */
    // Move
    MyString &operator=(MyString &&rhs);
    // Copy
    MyString &operator=(const MyString &rhs);

    /* Constructors and destructors */
    MyString();
    MyString(const char *str);
    ~MyString();
};



#endif // MYSTRING_HPP