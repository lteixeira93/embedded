#include <iostream>
#include "MyString.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    MyString a {"Hello"};
    MyString b {};

    b = a;

    return 0;
}
