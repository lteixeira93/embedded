#include "iostream"
#include "Account.hpp"

double Account::get_balance()
{
 	return balance;
}

void Account::set_balance (double balance) 
{
	this->balance = balance;
}

Account::Account () 
{
	std::cout << "Object created" << std::endl;
    balance = 5;
}

Account::Account (double balance_val) 
{
	std::cout << "Object args created" << std::endl;
    balance = balance_val;
}


Account::~Account() 
{
	std::cout << "Object destroyed" << std::endl;
}