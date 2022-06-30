// Random-access files statements
// Person.h (Class definition | Function prototypes and data members)

#pragma once

class Person
{
public:
	// CTOR
	Person();
	Person(string lastName, string firstName, int age);
	
	// accessor functions for id 
	void setId(int);
	int getId() const;

	// accessor functions for lastName 
	void setLastName(const string&);
	string getLastName() const;

	// accessor functions for firstName 
	void setFirstName(const string&);
	string getFirstName() const;

	// accessor functions for age 
	void setAge(int);
	int getAge() const;

public:
	char lastName[15];
	char firstName[10];
	int age;
	int id;
};

