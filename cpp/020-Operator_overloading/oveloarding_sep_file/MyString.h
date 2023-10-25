#ifndef MY_STRING_H
#define MY_STRING_H
#include <iostream>
#include <cstring>

class MyString {
private:
    static int num_objects;

public:
    char *my_str;

    static int get_num_objects();

    /* Operator overloading */
    // Move op
    MyString &operator=(MyString &&rhs);

    // Copy op
    MyString &operator=(MyString &rhs);

    /* Constructors and destructors */
    MyString();
    MyString(const char *str);
    ~MyString();
};

#endif //MY_STRING_H
