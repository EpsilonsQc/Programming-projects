// Asks the user to enter 3 numbers and displays them from smallest to largest, separated by commas.

#include <iostream>

using namespace std;

int main()
{
    int digit_1 = 0;
    int digit_2 = 0;
    int digit_3 = 0;

    cout << ":: SMALLER TO BIGGER ::" << endl;

    cout << endl << "Please enter a number: ";
    cin >> digit_1;

    cout << endl << "Please enter a number: ";
    cin >> digit_2;

    cout << endl << "Please enter a number: ";
    cin >> digit_3;

    cout << endl << endl << ":: HERE ARE YOUR NUMBERS FROM SMALLER TO BIGGER ::" << endl;

    if (digit_1 < digit_2 && digit_2 < digit_3)
    {
        cout << digit_1 << ", " << digit_2 << ", " << digit_3 << endl;
    }

    else if (digit_1 < digit_3 && digit_3 < digit_2)
    {
        cout << digit_1 << ", " << digit_3 << ", " << digit_2 << endl;
    }

    else if (digit_2 < digit_1 && digit_1 < digit_3)
    {
        cout << digit_2 << ", " << digit_1 << ", " << digit_3 << endl;
    }

    else if (digit_2 < digit_3 && digit_3 < digit_1)
    {
        cout << digit_2 << ", " << digit_3 << ", " << digit_1 << endl;
    }

    else if (digit_3 < digit_1 && digit_1 < digit_2)
    {
        cout << digit_3 << ", " << digit_1 << ", " << digit_2 << endl;
    }

    else if (digit_3 < digit_2 && digit_2 < digit_1)
    {
        cout << digit_3 << ", " << digit_2 << ", " << digit_1 << endl;
    }

    system("pause");

    return 0;
}