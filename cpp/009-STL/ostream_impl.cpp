#include <iostream>

class MyDataClass
{
    friend std::ostream &operator<<(std::ostream &os, const MyDataClass &rhs)
    {
        os << rhs.name << std::endl;
        os << rhs.age << std::endl;

        return os;
    }

    friend std::istream &operator>>(std::istream &is, MyDataClass &rhs)
    {
        is >> rhs.name;
        std::cout << "Name added" << std::endl;
        return is;
    }

public:
    std::string name;
    int age;

    MyDataClass();
    MyDataClass(std::string name, int age);
};

MyDataClass::MyDataClass()
: name {""}, age {0}
{}

MyDataClass::MyDataClass(std::string name, int age)
: name {name}, age {age}
{
    std::cout << "Args constructor called" << std::endl;
}

int main(void)
{
    MyDataClass obj0 {};
    MyDataClass obj1 {"Luiz", 29};

    std::cout << obj1 << std::endl;

    std::cin >> obj0;

    std::cout << obj0 << std::endl;

    return 0;
}
