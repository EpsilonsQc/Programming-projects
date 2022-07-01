// Move all zeroes to end of array
// Main.cpp (Main function | Program execution begins and ends there) 

#include "MoveZeros.h"
#include <iostream>

using namespace std;

int main()
{
	// Instanciate an object of my class MoveZeros
	MoveZeros MoveZerosObj;

	// Display headers
	MoveZerosObj.displayIntro();

	// Display original array
	MoveZerosObj.displayMsg();
	MoveZerosObj.printArray();
	
	// Display modified array (zeros moved to end of array)
	MoveZerosObj.moveZerosToEnd();
	MoveZerosObj.displayMsg();
	MoveZerosObj.printArray();

	// End of program
	MoveZerosObj.endProgram();
}