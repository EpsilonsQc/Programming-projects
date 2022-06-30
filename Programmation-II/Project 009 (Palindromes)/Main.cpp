// Palindromes - A palindrome is a string that’s spelled the same way forward and backward. 
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string);

bool isTrue = false;

int main()
{
    cout << "===================" << endl;
    cout << ".:: PALINDROMES ::." << endl;
    cout << "===================" << endl << endl;

    cout << "A palindrome is a string that is spelled the same way forward and backward." << endl << endl;

    // Declaring string
    string myString;

    while (true)
    {
        cout << "Please enter some text: ";
        // Taking string input using getline()
        getline(cin, myString);
        cout << endl;

        cout << "Is this string a palindrome?" << endl;
        isTrue = isPalindrome(myString);

        if (isTrue == true)
        {
            cout << "Yes, " << "the string {" << myString << "} is a palindrome." << endl << endl;
        }
        else if (isTrue == false)
        {
            cout << "No, " << "the string {" << myString << "} is NOT a palindrome." << endl << endl;
        }
    }
}

// Check whether or not the string is a palindrome
bool isPalindrome(string myStringParam)
{
    // Store a copy of myStringParam
    string myStringCopy = myStringParam;

    // Reverse the string storedString
    reverse(myStringCopy.begin(), myStringCopy.end());

    // If myStringParam is equal to storedString
    if (myStringParam == myStringCopy) 
    {
        return true;
    }
    else 
    {
        return false;
    }
}