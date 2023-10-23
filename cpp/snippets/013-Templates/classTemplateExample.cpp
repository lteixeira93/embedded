#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Item
{
private:
    std::string name;
    T value;
public:
    Item(std::string name , T value) 
    : name{name}, value {value}
    {}

    std::string get_name() const {return name;}
    T get_value() const {return value;}
};

template <typename T1, typename T2>
struct My_pair
{
    T1 first;
    T2 second;
};


int main(void)
{
    Item<int> i1 {"Larry", 1};
    std::cout << i1.get_name() << " " << i1.get_value() << std::endl;
    Item<double> i2 {"House", 1.1};
    std::cout << i2.get_name() << " " << i2.get_value() << std::endl;

    My_pair<std::string, int> p1 {"Frank", 100};
    std::cout << p1.first << " " << p1.second << std::endl;


    return 0;
}
