// Asks for a number from 1 to 4999 and displays it in Roman numerals

#include <iostream>

using namespace std;

int main()
{
    cout << ":: ROMAN NUMERALS CONVERTER ::" << endl;
    cout << "This small piece of software will convert decimal to Roman numerals for you." << endl << endl;

    while (true)
    {

     unsigned int userInput = 0;
     unsigned int preserveInput = 0;
     unsigned int thousands = 0;
     unsigned int hundreds = 0;
     unsigned int tens = 0;
     unsigned int units = 0;

    cout << "Please enter a number between 1 and 4999 (type 0 to exit): ";
    cin >> userInput;
    preserveInput = userInput;

    if (userInput == 0)
    { 
        break;
    }

    if (userInput >= 1000)
    {
        thousands = userInput / 1000;
        userInput = userInput - (thousands * 1000);
    }

    if (userInput >= 100)
    {
        hundreds = userInput / 100;
        userInput = userInput - (hundreds * 100);
    }

    if (userInput >= 10)
    {
        tens = userInput / 10;
        userInput = userInput - (tens * 10);
    }

    if (userInput > 0)
    {
        units = userInput;
        userInput = userInput - units;
    }

    cout << "In Roman Numerals, the number " << preserveInput << " is ";

    for (int i = thousands; i > 0; --i)
    {
        cout << "M";
    }

    for (int i = hundreds; i > 0; --i)
    {
        if (i == 9)
        {
            cout << "CM";
            break;
        }
        else if (i == 8)
        {
            cout << "DCCC";
            break;
            
        }
        else if (i == 7)
        {
            cout << "DCC";
            break;

        }
        else if (i == 6)
        {
            cout << "DC";
            break;

        }
        else if (i == 5)
        {
            cout << "D";
            break;

        }
        else if (i == 4)
        {
            cout << "CD";
            break;
        }
        else if (i == 1 || i == 2 || i == 3)
        {
            cout << "C";
        }
        else if (i == 0)
        {
        }
    }
    
    for (int i = tens; i > 0; --i)
    {
        if (i == 9)
        {
            cout << "XC";
            break;
        }
        else if (i == 8)
        {
            cout << "LXXX";
            break;

        }
        else if (i == 7)
        {
            cout << "LXX";
            break;

        }
        else if (i == 6)
        {
            cout << "LX";
            break;

        }
        else if (i == 5)
        {
            cout << "L";
            break;

        }
        else if (i == 4)
        {
            cout << "XL";
            break;
        }
        else if (i == 1 || i == 2 || i == 3)
        {
            cout << "X";
        }
        else if (i == 0)
        {
        }
    }
    
    for (int i = units; i > 0; --i)
    {
        if (i == 9)
        {
            cout << "IX";
            break;
        }
        else if (i == 8)
        {
            cout << "VIII";
            break;

        }
        else if (i == 7)
        {
            cout << "VII";
            break;

        }
        else if (i == 6)
        {
            cout << "VI";
            break;

        }
        else if (i == 5)
        {
            cout << "V";
            break;

        }
        else if (i == 4)
        {
            cout << "IV";
            break;
        }
        else if (i == 1 || i == 2 || i == 3)
        {
            cout << "I";
        }
        else if (i == 0)
        {
        }
    }

    cout << endl << endl;

    }

system("pause");

return 0;
}