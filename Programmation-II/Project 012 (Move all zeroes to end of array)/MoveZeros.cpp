// Move all zeroes to end of array
// MoveZerosToEnd.cpp (Implementation file | Constructor and member functions definitions)

#include "MoveZeros.h"
#include <iostream>

using namespace std;

// Default constructor (CTOR) with no parameter
MoveZeros::MoveZeros() :
	isZerosMoved(false),
	myArray{ -1, 3, 4, 0, 5, -2, 0, 6, 0 }
{
	// Empty CTOR body
}

void MoveZeros::displayIntro()
{
	cout << "=======================================" << endl;
	cout << ".:: MOVE ALL ZEROES TO END OF ARRAY ::." << endl;
	cout << "=======================================" << endl << endl;
}

void MoveZeros::displayMsg()
{
	if (isZerosMoved == false)
	{
		cout << "Original array: ";
	}
	else if (isZerosMoved == true)
	{
		cout << endl;
		cout << "Modified array: ";
	}
}

void MoveZeros::moveZerosToEnd()
{
	// Confirm that zero elements has been moved
	isZerosMoved = true;

	// Count of non-zero elements
	unsigned int count = 0;

	// If myArrayParam[i] is non-zero, then update the value of myArrayParam at index/subscript "count" to myArrayParam[i]
	for (int i = 0; i < arraySize; i++)
	{
		if (myArray[i] != 0)
		{
			myArray[count++] = myArray[i];
		}
	}

	// Update all elements at index/subscript > count (non-zero elements) with value 0
	for (int i = count; i < arraySize; i++)
	{
		myArray[i] = 0;
	}
}

// Print the array elements
void MoveZeros::printArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		cout << myArray[i] << " ";
	}
}

int MoveZeros::endProgram()
{
	cout << endl << endl;
	cout << "====================" << endl;
	cout << ":: END OF PROGRAM ::" << endl;
	cout << "====================" << endl << endl;

	system("pause");

	return 0;
}