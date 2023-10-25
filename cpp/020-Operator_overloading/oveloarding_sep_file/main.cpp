#include <iostream>
#include "MyString.h"

using namespace std;

int main() {
    cout << MyString::get_num_objects() << endl;
    MyString s0 {};
    cout << MyString::get_num_objects() << endl;
    MyString s1 {"Data"};
    cout << MyString::get_num_objects() << endl;

    // Move
    s0 = "Data";
    s1 = MyString{"NewData"};

    // Copy
    s0 = s1;

    return 0;
}