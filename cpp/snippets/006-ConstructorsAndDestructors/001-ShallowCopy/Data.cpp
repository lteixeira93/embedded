#include "Data.hpp"

Data::Data(const Data &source)
{
    this->id = source.id;
    this->random_data = source.random_data;
}

Data::Data(std::string id, int random_data)
:  id { id }, random_data { random_data }
{
    cout << "Object initialized with " << this->id << " and " << this->random_data << endl;
}   

Data::~Data()
{
    cout << "Object destroyed" << endl;
}