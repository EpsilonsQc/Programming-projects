// Move all zeroes to end of array
// MoveZerosToEnd.h (Class definition | Function prototypes and data members)

#pragma once

#include "Defines.h"

class MoveZeros
{
public:

	MoveZeros();

	void displayHeaders();
	void displayMsg();
	void moveZerosToEnd();
	void printArray();
	int endProgram();

private:

	bool isZerosMoved;
	int myArray[arraySize];
};