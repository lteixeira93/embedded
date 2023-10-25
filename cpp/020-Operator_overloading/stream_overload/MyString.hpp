#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>

class MyString
{
    friend std::ostream &operator<<(std::ostream &os, const MyString &rhs);
    friend std::istream &operator>>(std::istream &is, MyString &rhs);
private:
    char *str;
public:
    /* Constructors and destructors */
    MyString();
    MyString(const char *s);
    MyString(const MyString &source);
    MyString(MyString &&source);
    ~MyString();

    /* Oveloaded operators */
    MyString &operator=(const MyString &rhs);
    MyString &operator=(MyString &&rhs);

    /* Helper methods */
    void display() const;
    int get_length() const;
    const char *get_str() const;
};

#endif // MYSTRING_HPP