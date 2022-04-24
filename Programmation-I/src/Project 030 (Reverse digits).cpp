// Reverse your numbers

#include <iostream>

using namespace std;

void returnReversed();

int main()
{

    cout << ":: REVERSE YOUR NUMBERS ::" << endl << endl;

    returnReversed();
    
    system("pause");

    return 0;
}

void returnReversed()
{
    for (int i = 1; i > 0; ++i)
    {
        int number = 0;
        int remainder = 0;
        int reversedNumber = 0;

        cout << "Please enter a number: ";
        cin >> number;

            while (number != 0)
            {
                 remainder = number % 10; 
                 reversedNumber = reversedNumber * 10 + remainder;
                 number = number / 10;
            }

        cout << "Reversed number: " << reversedNumber << endl << endl;
    } 
}