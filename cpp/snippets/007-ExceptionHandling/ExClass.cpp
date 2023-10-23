#include <iostream>
#include <string>

/* User defined Exception Classes */
class DivideByZeroExcept
{};

class NegativeValueExcept
{}; 

int calculate_km_per_hour(int km, int hour)
{
    int km_per_hour {};

    if (hour == 0)
    {
        throw DivideByZeroExcept();
    }
    if (hour < 0 || km < 0)
    {
        throw NegativeValueExcept();
    }
    
    km_per_hour = km / hour;
    return km_per_hour;    
}

int main(void)
{
    int km {10}, hour {0};

    try
    {
        std::cout << calculate_km_per_hour(km, hour) << std::endl;
    }
    catch(const DivideByZeroExcept &ex)
    {
        std::cerr << "Cannot divide by zero" << '\n';
    }
    catch(const NegativeValueExcept &ex)
    {
        std::cerr << "Negative values are not allowed" << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown exception" << '\n';
    }
    

    return 0;
}
