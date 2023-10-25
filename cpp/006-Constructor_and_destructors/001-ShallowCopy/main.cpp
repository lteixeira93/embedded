#include <iostream>
#include "Data.hpp"

using std::cout;
using std::endl;

int main(void)
{
    Data *d0 = new Data();
    Data d1 ("#1#");
    Data d2 ("#2#", 2);
    Data d_ref {d2};

    delete d0;
    return 0;
}
