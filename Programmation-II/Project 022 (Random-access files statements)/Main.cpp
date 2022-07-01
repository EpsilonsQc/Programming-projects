// Random-access files statements
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <fstream>
#include "Person.h"

using namespace std;

int main()
{
	fstream fileObject ("nameage.dat", ios::out);
	
	Person personInfo = { "unassigned", "", 0 };
	
	personInfo.displayIntro();
	
	// Initialize nameage.dat with 100 records
	for (int r = 0; r < 100; ++r)
	{
		fileObject.write(reinterpret_cast<char*>(&personInfo), sizeof(personInfo));
	}

	fileObject.seekp(0); // Go to the beginning of the file
	
	// Input 10 names and age and write them to the file
	for (int x = 1; x <= 10; ++x) 
	{
		cout << "Enter last name, first name, and age: " << endl;
		cin >> personInfo.lastName >> personInfo.firstName >> personInfo.age;
		
		fileObject.write(reinterpret_cast<char*>(&personInfo), sizeof(personInfo));
		cout << endl;
	}

	personInfo.endOfProgram();
}