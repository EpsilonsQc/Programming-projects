// Merge char array's together
// Main.cpp (Main function | Program execution begins and ends there)

#include <iostream>

using namespace std;

void displayIntro();
void mergeTogether(char*, const char*);

int main()
{
    displayIntro();
	
    char string1[80];
    char string2[80];

	// Infinite loop
    while (true)
    {
        cout << "Please enter two strings." << endl;

        cout << "String 1: ";
        cin >> string1;
        cout << "String 2: ";
        cin >> string2;

        cout << endl;

        mergeTogether(string1, string2);

        cout << string1 << endl << endl;
    }
}

// Merge array's of char together
void mergeTogether(char* s1, const char* s2)
{
    while (*s1 != '\0')
    {
        ++s1;
    }

    for (; (*s1 = *s2); ++s1, ++s2)
    {
        // empty statement
    }
}

void displayIntro()
{
    cout << "===================================" << endl;
    cout << ".:: MERGE CHAR ARRAY'S TOGETHER ::." << endl;
    cout << "===================================" << endl << endl;
}