// Bank account balance and name
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include "Account.h"

using namespace std;

void displayIntro();
int endOfProgram();

int main()
{
	displayIntro();
	
	Account account1{ "Jane Green", 50 };
	Account account2{ "John Blue", 7 };

	// display initial balance of each object
	cout << "account1: " << account1.getName() << " balance is $" << account1.getBalance();
	cout << endl << "account2: " << account2.getName() << " balance is $" << account2.getBalance();

	// deposit an amount to account1
	cout << endl << endl << "Enter deposit amount for account1: "; // prompt
	int depositAmount;
	cin >> depositAmount; // obtain user input
	cout << "adding " << depositAmount << " to account1 balance";
	account1.deposit(depositAmount); // add to account1 balance

	// display balance
	cout << endl << endl << "account1: " << account1.getName() << " balance is $" << account1.getBalance();
	cout << endl << "account2: " << account2.getName() << " balance is $" << account2.getBalance();

	// deposit an amount to account2
	cout << endl << endl << "Enter deposit amount for account2: "; // prompt
	cin >> depositAmount; // obtain user input
	cout << "adding " << depositAmount << " to account2 balance";
	account2.deposit(depositAmount); // add to account2 balance

	// display balance
	cout << endl << endl << "account1: " << account1.getName() << " balance is $" << account1.getBalance();
	cout << endl << "account2: " << account2.getName() << " balance is $" << account2.getBalance();

	// withdraw an amount from account1
	cout << endl << endl << "Enter withdraw amount for account1: "; // prompt
	int withdrawAmount;
	cin >> withdrawAmount; // obtain user input
	account1.withdraw(withdrawAmount); // withdraw from account1 balance

	// display balance
	cout << endl << endl << "account1: " << account1.getName() << " balance is $" << account1.getBalance();
	cout << endl << "account2: " << account2.getName() << " balance is $" << account2.getBalance() << endl;

	// withdraw an amount from account2
	cout << endl << endl << "Enter withdraw amount for account2: "; // prompt
	cin >> withdrawAmount; // obtain user input
	account2.withdraw(withdrawAmount); // withdraw from account2 balance

	// display balance
	cout << endl << endl << "account1: " << account1.getName() << " balance is $" << account1.getBalance();
	cout << endl << "account2: " << account2.getName() << " balance is $" << account2.getBalance() << endl;

	endOfProgram();
}

void displayIntro()
{
	cout << "=====================================" << endl;
	cout << ".:: BANK ACCOUNT BALANCE AND NAME ::." << endl;
	cout << "=====================================" << endl << endl;
}

int endOfProgram()
{
	cout << endl;
	cout << "====================" << endl;
	cout << ":: END OF PROGRAM ::" << endl;
	cout << "====================" << endl << endl;

	system("pause");

	return 0;
}