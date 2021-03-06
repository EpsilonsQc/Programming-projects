// Bank account balance and name
// Account.h (Class definition | Function prototypes and data members)

#pragma once

#include <string>

class Account
{
public:

	//Account constructor with two parameters
	Account(std::string accountName, int initialBalance)
		: name{ accountName } // assign accountName to data member name
	{
		// validate that the initialBalance is greater than 0; if not, data member balance keeps it's default initial value of 0
		if (initialBalance > 0) // if the initialBalance is valid
		{
			balance = initialBalance; // assign it to data member balance
		}
	}

	// function that deposits (adds) only a valid amount to the balance
	void deposit(int depositAmount)
	{
		if (depositAmount > 0) // if the depositAmount is valid
		{
			balance = balance + depositAmount; // add it to the balance
		}
	}

	// function that withdraw (substract) only a valid amount to the balance
	void withdraw(int withdrawAmount)
	{
		if (balance - withdrawAmount >= 0)
		{
			balance = balance - withdrawAmount;
			std::cout << "withdrawing " << withdrawAmount << " from account1 balance";
		}
		else
		{
			std::cout << "Withdrawal amount exceeded account balance.";
		}
	}

	// function returns the account balance
	int getBalance() const
	{
		return balance;
	}

	// function that sets the name
	void setName(std::string accountName)
	{
		name = accountName;
	}

	// function that returns the name
	std::string getName() const
	{
		return name;
	}

private:

	std::string name; // account name data member
	int balance{ 0 }; // account balance data member with default initial value

}; // end class Account