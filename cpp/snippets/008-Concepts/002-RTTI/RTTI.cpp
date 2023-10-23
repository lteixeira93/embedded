#include <iostream>
#include <typeinfo>

using namespace std;

class Base { virtual void dummy(){} };
class Derived : public Base {};

int main(int argc, char const *argv[])
{
    /* code */
    Base* base_ptr = new Derived();

    cout << typeid(*base_ptr).name() << endl;

    delete base_ptr;

    return 0;
}
