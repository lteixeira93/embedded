#include "Data.hpp"

int Data::display_data() const
{
    return *this->random_data;
}

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