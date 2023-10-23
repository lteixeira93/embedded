#include "MyString.hpp"

int MyString::num_objects {0};

int MyString::get_num_objects()
{
    return num_objects;
}

// Move
MyString &MyString::operator=(MyString &&rhs)
{
    if(this == &rhs) return *this;

    delete [] this->myStr;

    this->myStr = rhs.myStr;

    rhs.myStr = nullptr;

    return *this;
}

// Copy
MyString &MyString::operator=(const MyString &rhs)
{
    delete [] this->myStr;
    this->myStr = new char[strlen(rhs.myStr)+1];
    strcpy(this->myStr, rhs.myStr);

    return *this;
}

MyString::MyString()
: myStr {nullptr}
{
    ++num_objects;

    this->myStr = new char;
    *this->myStr = '\0';
}

MyString::MyString(const char *str)
: myStr {nullptr}
{
    ++num_objects;

    if(str == nullptr)
    {
        this->myStr = new char;
        *this->myStr = '\0';
    }
    
    this->myStr = new char[strlen(str)+1];
    strcpy(myStr, str);
}

MyString::~MyString()
{
    num_objects--;
}
