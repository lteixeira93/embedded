#ifndef _DATA_HPP_
#define _DATA_HPP_
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Data
{
private:
    std::string id;
    int *random_data;
public:
    Data(const Data &source);
    Data(std::string id, int random_data);
    ~Data();
};


#endif // _DATA_HPP_