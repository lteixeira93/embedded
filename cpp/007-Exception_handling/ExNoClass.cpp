#include <iostream>
#include <string>

int calculate_km_per_hour(int km, int hour)
{
    int km_per_hour {};

    if (hour == 0)
    {
        throw 0;
    }
    if (hour < 0 || km < 0)
    {
        throw std::string{"Negative values are not allowed"} ;
    }
    
    km_per_hour = km / hour;
    return km_per_hour;    
}

int main(void)
{
    int km {10}, hour {2};

    try
    {
        std::cout << calculate_km_per_hour(km, hour) << std::endl;
    }
    catch(int &e)
    {
        std::cerr << "Cannot divide by zero" << '\n';
    }
    catch(std::string &e)
    {
        std::cerr << e << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown exception" << '\n';
    }
    

    return 0;
}
