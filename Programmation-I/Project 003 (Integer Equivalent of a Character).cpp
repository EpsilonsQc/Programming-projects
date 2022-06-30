// Displays the numbers 1 through 4 on the same line, separated by spaces.Use a single output statementand a single insertion operator.

#include <iostream>

using namespace std;

int main()
{
    char UserInput = 0;

    cout << ":: CONVERT USER INPUT TO ASCII CHARACTER SET ::" << endl << endl;

    cout << "Please enter a character (letter, number or special characters): ";
    cin >> UserInput;
    cout << "User input conversion to ASCII equal : " << static_cast<int>(UserInput) << endl << endl;

    system("pause");

    return 0;
}