#include <iostream>

using namespace std;

int main()
{
    int UserInput = 0;
    int digit_1 = 0;
    int digit_2 = 0;
    int digit_3 = 0;
    int digit_4 = 0;
    int digit_5 = 0;

    cout << ":: DIGITS OF AN INTEGER ::" << endl << endl;

    cout << "Please enter a five-digit number: ";
    cin >> UserInput;

    digit_1 = (UserInput / 10000) % 10;
    digit_2 = (UserInput / 1000) % 10;
    digit_3 = (UserInput / 100) % 10;
    digit_4 = (UserInput / 10) % 10;
    digit_5 = (UserInput / 1) % 10;

    cout << "Here's the digit of your five-digit number : " << digit_1 << "   " << digit_2 << "   " << digit_3 << "   " << digit_4 << "   " << digit_5 << endl << endl;

    system("pause");

    return 0;
}
