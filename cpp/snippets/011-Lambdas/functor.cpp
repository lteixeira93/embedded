#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

struct Square_f
{
    void operator() (int x)
    {
        std::cout << x*x << std::endl;
    }
};

template <typename T>
struct Displayer
{
    void operator() (const T data)
    {
        std::cout << data << std::endl;
    } 
};

int main(void)
{
    // Using functors
    std::vector<int> v {1, 2, 3, 4};
    Square_f sqrf;
    Displayer<int> dsp;

    for_each(v.begin(), v.end(), sqrf); // sqrf.operator()(v.at(i))
    std::cout << std::endl;
    for_each(v.begin(), v.end(), dsp);
    std::cout << std::endl;
    // OR
    for_each(v.begin(), v.end(), Displayer<int>());
    std::cout << std::endl;

    // Using lambdas // [] () -> return_type (Hide if void) specifiers {};
    for_each(v.begin(), v.end(), [] (int x) {std::cout << x*x << std::endl;});


    return 0;
}
