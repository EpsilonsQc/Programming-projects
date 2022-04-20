// Give the quotient and remainder of a user inputs then separate the digits of another user input.

#include <iostream>

using namespace std;

void separatingDigits();

int main()
{
    unsigned int a = 0;
    unsigned int b = 0;
    unsigned int quotient = 0;
    unsigned int remainder = 0;

    cout << ":: GIVE THE QUOTIENT AND REMAINDER OF YOUR NUMBERS ::" << endl << endl;

    cout << "Please enter a number (a): ";
    cin >> a;

    cout << "Please enter a number (b): ";
    cin >> b;
    cout << endl;

    quotient = floor(a / b);
    cout << "Quotient of number (a) and (b) is: " << quotient << endl;

    remainder = a % b;
    cout << "Remainder of the quotient from (a) and (b) is: " << remainder << endl << endl;

    cout << ":: SEPARATE THE DIGITS OF YOUR NUMBER ::" << endl << endl;

    separatingDigits();

    cout << endl << endl;

    system("pause");

    return 0;
}

void separatingDigits()
{
    int userInput = 0;

    cout << "Please enter a number between 1 and 32767: ";
    cin >> userInput;

    while (userInput > 32767)
    {
        cout << "The number you entered is too big." << endl << endl << "Please enter a number between 1 and 32767: ";
        cin >> userInput;
    }

    unsigned int digit = 0;
    unsigned int divider = 10000;

    while (divider > 0)
    {
        digit = userInput / divider;
        userInput -= digit * divider;
        divider /= 10;

        if (digit != 0)
        {
            cout << digit << "  ";
        }
    }
}