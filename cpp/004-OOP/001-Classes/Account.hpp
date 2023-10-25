#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account
{
private:
	double balance;
public:
	int a;
	int b;

	double get_balance();
	void set_balance (double balance);

	Account(); // Best practice: Define your own user constructor
	Account(double balance_val);

	~Account();
};

#endif // _ACCOUNT_H_
