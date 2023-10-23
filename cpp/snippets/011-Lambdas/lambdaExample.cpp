// Here is a basic syntax of a lambda (Inline anonymous functions) function in C++:

// [capture-list](parameters) -> return_type {
    // function body
// };
// [](){} - Lambda pattern
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct {
    // overload function call ()
    void operator()(int x)
    {
        std::cout << x << std::endl;
    }
}something;


int main(int argc, char const *argv[])
{
    /* Lambda function with parameters. */
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << add(1,2) << std::endl;

    /* Lambda function with capture-by-value. */
    int multiplier = 3;
    auto multi = [multiplier](int a) {
        return multiplier * a;
    };
    std::cout << multi(5) << std::endl;

    /* Lambda function with capture-by-reference. */
    int expiresInDays = 5;
    auto updateDays = [&expiresInDays](int newDays) {
        expiresInDays = newDays;
    };
    std::cout << multi(30) << std::endl;

    std::vector <int> v {2, 3, 4, 5, 6};

    // Without lambda
    // std::for_each(v.begin(), v.end(), something); 

    // With lambda
    std::for_each(v.begin(), v.end(), [](int x){ std::cout << x << std::endl; }); 

    // Or
    int d {10}, e {11};
    std::for_each(v.begin(), v.end(), [&](int x) -> void { 
        (x % 2 == 0) ? 
        std::cout << x << " Is Even" << std::endl : std::cout << x << " Is Odd" << std::endl;

        std::cout << "D = " << d-- << " E = " << e-- << std::endl;
    }
    ); 

    std::cout << "Final D = " << d << " Final E = " << e << std::endl;
    return 0;
}
