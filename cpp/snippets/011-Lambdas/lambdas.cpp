// [] () -> return_type (Hide if void) specifiers {};
#include <iostream>

int main(void)
{
    const int n {3};
    int nums[n] {10,20,30};

    // Creating an object of STATELESS lambda
    auto sum = [] (auto nums [], auto n)
    {
        auto sum {0};
        for (size_t i = 0; i < n; i++) sum += nums[i];
        return sum;        
    };

    // Now sum is an object
    std::cout << sum(nums, 3) << std::endl;

    return 0;
}
