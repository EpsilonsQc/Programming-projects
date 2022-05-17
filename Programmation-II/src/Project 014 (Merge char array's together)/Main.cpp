// Merge array's of char together 
// Main.cpp (Main function | Program execution begins and ends there)

#include <iostream>

using namespace std;

void mergeTogether(char*, const char*); // prototype

int main()
{
    char string1[80];
    char string2[80];

    cout << "Enter two strings: ";
    cin >> string1 >> string2;

    mergeTogether(string1, string2);

    cout << string1 << endl;

    cout << endl;

    system("pause");

    return 0;
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
