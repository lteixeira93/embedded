#include "Data.hpp"

Data::Data(const Data &source)
: Data { source.id , *source.random_data }
{}

Data::Data(std::string id, int random_data)
{
    this->random_data = new int;
    *this->random_data = random_data;
    this->id = id;

    cout << "Object initialized with " << this->id << " and " << *this->random_data << endl;
}   

Data::~Data()
{
    cout << "Object destroyed" << endl;
}