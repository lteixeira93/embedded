#include <ostream>
#include <cstring>
#include "MyString.hpp"

/* Constructors and destructors */
MyString::MyString()
: str {nullptr}
{
    str = new char[1];
    *str = '\0';
}

MyString::MyString(const char *s)
: str {nullptr}
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}

MyString::MyString(const MyString &source)
: str {nullptr}
{
    // Deep copy required (Raw pointer as member class)
    str = new char(strlen(source.str) + 1);
    strcpy(str, source.str);
}

MyString::MyString(MyString &&source)
: str {nullptr}
{
    // Steal data required
    this->str = source.str;
    source.str = nullptr;
}

MyString::~MyString()
{
    delete [] str;
}

/* Oveloaded operators */
MyString &MyString::operator=(const MyString &rhs)
{
    delete [] str;
    this->str = nullptr;
    this->str = new char[strlen(rhs.str) + 1];
    strcpy(this->str, rhs.str);

    return *this;
}

MyString &MyString::operator=(MyString &&rhs)
{
    delete [] this->str;
    this->str = nullptr;
    this->str = rhs.str;

    rhs.str = nullptr;

    return *this;
}

/* Oveloaded insertion operators */
std::ostream &operator<<(std::ostream &os, const MyString &rhs)
{
    os << rhs.str;
    return os;
}

std::istream &operator>>(std::istream &is, MyString &rhs)
{
    char *buff = new char[1000];
    is >> buff;
    rhs = MyString{buff};
    delete buff;

    return is;
}

void MyString::display() const
{
    std::cout << str << ": " << get_length() << std::endl; 
}

int MyString::get_length() const
{
    return strlen(str);
}

const char *MyString::get_str() const
{
    return this->str;
}

