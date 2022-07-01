// Random-access files statements
// Person.h (Class definition | Function prototypes and data members)

#pragma once

#include <iomanip>

using namespace std;

class Person
{
public:
	// CTOR
	Person() {};
	Person(string lastName, string firstName, int age) {};

	// accessor functions for id 
	void setId(int) {};
	int getId() const {};

	// accessor functions for lastName 
	void setLastName(const string&) {};
	string getLastName() const {};

	// accessor functions for firstName 
	void setFirstName(const string&) {};
	string getFirstName() const {};

	// accessor functions for age 
	void setAge(int) {};
	int getAge() const {};

	void displayIntro()
	{
		cout << "======================================" << endl;
		cout << ".:: RANDOM-ACCESS FILES STATEMENTS ::." << endl;
		cout << "======================================" << endl << endl;
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

public:
	char lastName[15] = {"unassigned"};
	char firstName[10] = {""};
	int age = 0;
	int id = 0;
};