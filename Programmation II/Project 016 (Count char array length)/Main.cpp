// Count char array length
// Main.cpp (Main function | Program execution begins and ends there)

#include <iostream>

using namespace std;

void displayIntro();
int countLength(const char*);

int main()
{
	displayIntro();
		
	char string1[80];

	// Infinite loop
	while (true)
	{
		cout << "Enter a string: ";
		cin >> string1;

		cout << "Number of char: " << countLength(string1) << endl << endl;
	}
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

void displayIntro()
{
	cout << "===============================" << endl;
	cout << ".:: COUNT CHAR ARRAY LENGTH ::." << endl;
	cout << "===============================" << endl << endl;
}