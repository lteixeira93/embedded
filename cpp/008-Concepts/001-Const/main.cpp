#include <iostream>
#include "Data.hpp"

using std::cout;
using std::endl;

int main(void)
{
    const Data d0 {"#0#", 10};
    cout << d0.display_data() << endl;

    return 0;
}
