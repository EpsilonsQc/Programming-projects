// Determine if a number is a "perfect number"
// An integer is said to be a perfect number if the sum of its divisors, including 1 (but not the number itself), is equal to the number. 

#include <iostream>

using namespace std;

void isPerfect();

int main()
{
    cout << ":: ALL THE PERFECT NUMBERS BETWEEN 1 AND 10000 ::" << endl;

    isPerfect();

    cout << endl << endl;

    system("pause");

    return 0;
}

void isPerfect()
{
    for (int numberInput = 1; numberInput <= 10000; ++numberInput)
    {
        int number = 1;
        int sum = 0;

        while (number < numberInput) 
        {
            if (numberInput % number == 0)
            {
                sum = sum + number;
            }

            ++number;
        }

        if (sum == numberInput)
        {
            cout << endl << number << " is a perfect number with factors of 1";

            for (int divisors = 2; divisors <= number / 2; ++divisors)
            {
                if ((number % divisors) == 0)
                {
                    cout << " + " << divisors;
                }
            }
        }
        else
        {
            // Number is not a perfect number
        }
    }
}