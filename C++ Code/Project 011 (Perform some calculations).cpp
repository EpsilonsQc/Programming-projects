// Asks the user to enter 2 numbers and displays the largest, the smallest, the product, the sum, the difference and the ratio.

#include <iostream>

using namespace std;

int main()
{
    double digit_1 = 0;
    double digit_2 = 0;
    double biggerThan = 0;
    double smallerThan = 0;
    double productOf = 0;
    double sumOf = 0;
    double diffOf = 0;
    double ratioOf = 0;

    cout << ":: CALCULATOR ::" << endl;
    cout << "This small piece of software will perform some useful calculations for you." << endl << endl;

    cout << "Please enter a number: ";
    cin >> digit_1;

    cout << "Please enter a number: ";
    cin >> digit_2;

    cout << endl << ":: HERE ARE YOUR RESULTS ::" << endl;

    if (digit_1 > digit_2)
    {
        cout << "BiggerThan: " << digit_1 << " is bigger than " << digit_2 << endl;
    }
    else
    {
        cout << "BiggerThan: " << digit_2 << " is bigger than " << digit_1 << endl;
    }

    if (digit_1 < digit_2)
    {
        cout << "SmallerThan: " << digit_1 << " is smaller than " << digit_2 << endl;
    }
    else
    {
        cout << "SmallerThan: " << digit_2 << " is smaller than " << digit_1 << endl;
    }

    productOf = digit_1 * digit_2;
    cout << "Multiplication: " << digit_1 << " times " << digit_2 << " equal " << productOf << endl;

    sumOf = digit_1 + digit_2;
    cout << "Addition: " << digit_1 << " plus " << digit_2 << " equal " << sumOf << endl;

    diffOf = digit_1 - digit_2;
    cout << "Substraction: " << digit_1 << " minus " << digit_2 << " equal " << diffOf << endl;

    ratioOf = (digit_1 + digit_2) / 2;
    cout << "Ratio: " << "(" << digit_1 << " plus " << digit_2 << ")" << " divided by 2 equal " << ratioOf << endl;

    system("pause");

    return 0;
}
