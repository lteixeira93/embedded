#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#define CPY_ASSIGN

class MyString
{
private:
    char *str;
public:

    MyString();
    MyString(const char *s);
    
    MyString(const MyString &source);
    MyString &operator=(const MyString &rhs);
    
    ~MyString();
};

#endif // MYSTRING_HPP
