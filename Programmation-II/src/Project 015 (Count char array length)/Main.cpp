// Count array of char length
// Main.cpp (Main function | Program execution begins and ends there)

#include <iostream>

using namespace std;

int countLength(const char*); // prototype

int main()
{
	char string1[80];

	cout << "Enter a string: ";
	cin >> string1;

	cout << "Number of char: " << countLength(string1) << endl;
}

// Count array of char length
int countLength(const char* s)
{
	unsigned int x;

	for (x = 0; *s != '\0'; ++s)
	{
		++x;
	}

	return x;
}
