#include <iostream>
#include <string>

template <typename T>
T sum_input(T a, T b)
{
    return a + b;
}

int main(void)
{
    // std::cout << sum_input<int>(1, 2) << std::endl;

    std::string s0 = "L", s1 = "Z";
    std::cout << sum_input<std::string>(s0, s1) << std::endl;

    return 0;
}
