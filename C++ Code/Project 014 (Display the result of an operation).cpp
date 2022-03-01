// Asks the user to enter an operation (+, -, *, /) as well as 2 numbers and displays the result.

#include <iostream>

using namespace std;

int main()
{
    char operation = '0';
    double result = 0;
    double digit_1 = 0;
    double digit_2 = 0;


    cout << ":: CALCULATOR ::" << endl;

    cout << "Please enter the sign of operation (+, -, *, /) you want to compute: ";
    cin >> operation;

    cout << "Please enter a number: ";
    cin >> digit_1;

    cout << "Please enter a number: ";
    cin >> digit_2;

    cout << endl << ":: HERE ARE YOUR RESULTS ::" << endl;

    if (operation == '+')
    {
        result = digit_1 + digit_2;
        cout << digit_1 << " plus " << digit_2 << " equal " << result << endl;
    }

    else if (operation == '-')
    {
        result = digit_1 - digit_2;
        cout << digit_1 << " minus " << digit_2 << " equal " << result << endl;
    }

    else if (operation == '*')
    {
        result = digit_1 * digit_2;
        cout << digit_1 << " times " << digit_2 << " equal " << result << endl;
    }

    else if (operation == '/')
    {
        result = digit_1 / digit_2;
        cout << digit_1 << " divided by " << digit_2 << " equal " << result << endl;
    }

    system("pause");

    return 0;
}
