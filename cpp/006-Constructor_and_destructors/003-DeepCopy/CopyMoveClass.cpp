#include <iostream>
#include "CopyMoveClass.hpp"

int CopyMoveClass::num_obj {0};

int CopyMoveClass::get_data() 
{
    return *this->data;
}

int CopyMoveClass::get_num_obj() 
{
    return num_obj;
}

void CopyMoveClass::set_data(int data) 
{
    *this->data = data;
}

void CopyMoveClass::display(CopyMoveClass s) 
{
    std::cout << s.get_data() << std::endl;
}

#ifdef DEEP
CopyMoveClass::CopyMoveClass(const CopyMoveClass &source) 
: CopyMoveClass {*source.data}
{}

CopyMoveClass::CopyMoveClass(int data)
{
    this->data = new int; // Allocating int on Heap
    *this->data = data;
    ++num_obj;
}
#endif // DEEP

#ifdef SHALLOW
CopyMoveClass::CopyMoveClass(const CopyMoveClass &source) 
: data {source.data} // In the shallow we don't delegate and allocate again
{}

CopyMoveClass::CopyMoveClass(int data)
{
    this->data = new int; // Allocating int on Heap
    *this->data = data;
    ++num_obj;
}
#endif // SHALLOW

#ifdef MOVE
CopyMoveClass::CopyMoveClass(CopyMoveClass &&source) noexcept
: data {source.data} // Moving data and nullout source pointer
{
    std::cout << "Moving data" << std::endl;
    source.data = nullptr;
}

CopyMoveClass::CopyMoveClass(int data)
{
    this->data = new int; // Allocating int on Heap
    *this->data = data;
    ++num_obj;
}
#endif // MOVE

CopyMoveClass::~CopyMoveClass()
{
    num_obj--;
    if (data != nullptr)
    {
        std::cout << "Destructor freeing data for: " << *data << std::endl;
    } else {
        std::cout << "Destructor freeing data for: nullptr" << std::endl;
    }    

    delete data;
}