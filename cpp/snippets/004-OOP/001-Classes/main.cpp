#include <iostream>
#include "Account.hpp"

int main (void) {
	Account *ptr = new Account();

	ptr->a = 1;
	ptr->b = 2;

	delete ptr;

	Account my_account;

	my_account.set_balance(10.2);
	std::cout << my_account.get_balance() << std::endl;

	return 0;
}