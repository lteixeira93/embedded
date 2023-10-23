#include<iostream>

class Person 
{
public:
    std::string name;
    int age;

    bool operator<(const Person &rhs) const;
    Person();
    ~Person();
    Person(std::string age, int name);
};

Person::Person() 
{}
Person::~Person() 
{}

Person::Person(std::string name_val, int age_val) 
: name {name_val}, age {age_val}
{}

bool Person::operator<(const Person &rhs) const
{
    if (this->age < rhs.age)
    {
        return true;
    }
    return false;
}

template <typename T>
T min(T p0, T p1)
{
    return (p0 < p1) ? p0 : p1;
}

int main(void)
{
    Person p0 {"Luiz", 29};
    Person p1 {"Taynara", 25};
    Person p3 = min<Person>(p0, p1);

    return 0;
}
