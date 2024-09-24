#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person
{
public:
    string name;
    int age;

    bool operator<(const Person &rhs) const 
    {
        return (this->age < rhs.age) ? true : false;
    }
};

template <typename T>
T min(T a, T b)
{
    return (a < b) ? a : b;
}

int main(void)
{
    Person p1 = {"Luiz", 28};
    Person p2 = {"Taynara", 25};
    Person p3 = min<Person>(p1, p2);

    cout << min<int>(2, 3) << endl;
    cout << p3.name << endl;

    return 0;
}
