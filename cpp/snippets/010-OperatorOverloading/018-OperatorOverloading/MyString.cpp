#include <cstring>
#include <iostream>
#include "MyString.hpp"

MyString::MyString() 
: str {nullptr}
{
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *s) 
: str {nullptr}
{
    if(s == nullptr) 
    {
        str = new char[1];
        *str = '\0';
    }
    else {
        str = new char[strlen(s)+1];
        strcpy(str,s);
    }
}

MyString::MyString(const MyString &source)
: str {nullptr}
{
    str = new char[strlen(source.str)+1];
    strcpy(str, source.str);
}

MyString &MyString::operator=(const MyString &rhs)
{
    delete [] this->str;

    this->str = new char[strlen(rhs.str)+1];
    strcpy(this->str, rhs.str);

    return *this;
}

MyString::~MyString()
{
    delete [] str;
}