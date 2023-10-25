#include <iostream>
#include <vector>
#include "CopyMoveClass.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
#if defined SHALLOW || defined DEEP
	std::cout << "Number of objects: " << CopyMoveClass::get_num_obj() << std::endl;
	CopyMoveClass obj1 {100};
	obj1.display(obj1);
	std::cout << "Number of objects: " << CopyMoveClass::get_num_obj() << std::endl;
	CopyMoveClass obj2 {obj1};
	std::cout << "Number of objects: " << CopyMoveClass::get_num_obj() << std::endl;

#else
	vector <CopyMoveClass> v;
	v.push_back(CopyMoveClass{100});
#endif
	
	std::cout << "Number of objects: " << CopyMoveClass::get_num_obj() << std::endl;

	return 0;
}
