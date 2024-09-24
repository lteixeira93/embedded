#include <iostream>

using namespace std;

class Person
{
public:
    int age;
    void yearPasses();
    void amIOld();

    Person();
    Person(int initialAge);

    ~Person();
};

Person::Person()
{
    cout << "No args constructor called" << endl;
}

Person::Person(int initialAge)
{
    if (initialAge < 0)
    {
        cout << "Age is not valid, setting age to 0." << endl;
        this->age = 0;
    }
    else {
        this->age = initialAge;
    }    
}

Person::~Person()
{
}

void Person::yearPasses()
{
    ++this->age;
}

void Person::amIOld()
{
    if (this->age < 13)
    {
        cout << "You are young." << endl;
    }
    else if ((this->age >= 13) && (this->age < 18))
    {
        cout << "You are a teenager." << endl;
    }
    else
    {
        cout << "You are old." << endl;
    }
    
}

int main(void)
{
    Person *p  = new Person(4);
    Person *p1 = new Person(-1);
    Person *p2 = new Person(10);
    Person *p3 = new Person(16);
    Person *p4 = new Person(18);

    p->yearPasses();
    p1->yearPasses();
    p2->yearPasses();
    p3->yearPasses();
    p4->yearPasses();

    p->amIOld();
    p1->amIOld();
    p2->amIOld();
    p3->amIOld();
    p4->amIOld();

    delete p, p1, p2, p3, p4;

    return 0;
}
