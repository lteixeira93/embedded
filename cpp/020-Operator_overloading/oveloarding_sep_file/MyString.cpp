#include "MyString.h"

int MyString::num_objects{0};

int MyString::get_num_objects() {
    return num_objects;
}

// Move op
MyString &MyString::operator=(MyString &&rhs) {
    if(this == &rhs) return *this;

    delete [] this->my_str;

    /* Point to rhs.my_str address in memory */
    this->my_str = rhs.my_str;

    rhs.my_str = nullptr;

    return *this;
}

// Copy op
MyString &MyString::operator=(MyString &rhs) {
    delete [] this->my_str;
    this->my_str = new char(strlen(rhs.my_str) + 1);
    strcpy(this->my_str, rhs.my_str);

    return *this;
}

/* Constructors and destructors */
MyString::MyString()
        : my_str{nullptr} {
    ++num_objects;

    this->my_str = new char;
    *this->my_str = '\0';
}

MyString::MyString(const char *str)
        : my_str{nullptr} {
    ++num_objects;

    if(str == nullptr) {
        this->my_str = new char;
        *this->my_str = '\0';
    }

    this->my_str = new char(strlen(str) + 1);
    strcpy(this->my_str, str);
}

MyString::~MyString() {
    num_objects--;
}
