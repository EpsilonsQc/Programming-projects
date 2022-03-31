// Asks the user to enter a number and displays whether the number is even or odd.

#include <iostream>

using namespace std;

int main()
{
    int wholeNumber;

    cout << "Please enter a whole number: ";
    cin >> wholeNumber;

    if (wholeNumber % 2 == 0)
    {
        cout << endl << wholeNumber << " is an even number." << endl;
    }

    else
    {
        cout << endl << wholeNumber << " is an odd number." << endl;
    }

    system("pause");

    return 0;
}