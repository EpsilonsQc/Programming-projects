// Print a string backward
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <string>

using namespace std;

void displayIntro();
void stringReverse(string, size_t);

int main()
{
    displayIntro();

    // Declaring string
    string myString;

	// Infinite loop
    while (true)
    {
        cout << "Please enter some text: ";
        // Taking string input using getline()
        getline(cin, myString);
        cout << endl;

        // Displaying initial string
        cout << "The initial string is:  " << myString << endl;

        // Displaying reversed string
        cout << "The reversed string is: ";
        stringReverse(myString, 0);
        cout << endl << endl;
    }
}

// Reverse a string
void stringReverse(string myStringParam, size_t subscript)
{
    if (subscript < myStringParam.size())
    {
        stringReverse(myStringParam, subscript + 1);
        cout << myStringParam[subscript];
    }
}

void displayIntro()
{
    cout << "===============================" << endl;
    cout << ".:: PRINT A STRING BACKWARD ::." << endl;
    cout << "===============================" << endl << endl;
}