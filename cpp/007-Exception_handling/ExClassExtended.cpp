#include <iostream>
#include <string>

/* User defined Exception Classes inherits from std::exception */
class DivideByZeroExcept : public std::exception
{
public:
    DivideByZeroExcept() noexcept = default;
    ~DivideByZeroExcept() = default;

    virtual const char *what() const noexcept override
    {
        return "Cannot divide by zero";
    }
};

class NegativeValueExcept : public std::exception
{
public:    
    NegativeValueExcept() noexcept = default;
    ~NegativeValueExcept() = default;

    virtual const char *what() const noexcept override
    {
        return "Negative values are not allowed";
    }
}; 

class CalculateAvg : public DivideByZeroExcept, NegativeValueExcept
{
public:
    int km, hour;
    int calculate_km_per_hour(int km, int hour);
};

int CalculateAvg::calculate_km_per_hour(int km, int hour)
{
    this->km = km;
    this->hour = hour;
    int km_per_hour {};

    if (this->hour == 0)
    {
        throw DivideByZeroExcept();
    }
    if (this->hour < 0 || this->km < 0)
    {
        throw NegativeValueExcept();
    }
    
    km_per_hour = this->km / this->hour;
    return km_per_hour;    
}

int main(void)
{
    int km {10}, hour {5};
    CalculateAvg calc = CalculateAvg();

    try
    {
        std::cout << calc.calculate_km_per_hour(km, hour) << std::endl;
    }
    catch(const std::exception &ex)
    {
        std::cerr << ex.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown error" << std::endl;
    }

    return 0;
}
