#include <iostream>

using namespace std;

static int* largest_ptr(int *ptr_x, int* ptr_y);

int main (void) 
{
	int *ptr_ret {nullptr};	
	int x {300}, y {200};

	ptr_ret = largest_ptr(&x, &y);

	cout << "Largest pointer is: " << *ptr_ret << endl;

	return 0;
}

static int* largest_ptr(int *ptr_x, int* ptr_y) 
{
	if(*ptr_x > *ptr_y) return ptr_x;
	else return ptr_y;
}