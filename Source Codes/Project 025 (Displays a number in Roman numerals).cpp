// Asks for a number from 1 to 4999 and displays it in Roman numerals

#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    int storeNumber = 0;

    int thousands = 0;
    int hundreds = 0;
    int tens = 0;
    int units = 0;

    cout << ":: ROMAN NUMERALS CONVERTER ::" << endl;
    cout << "This small piece of software will convert decimal to Roman numerals for you." << endl << endl;

    while (true)
    {

    cout << "Please enter a number between 1 and 4999 (type 0 to exit): ";
    cin >> number;
    storeNumber = number;

    if (number == 0)
    { 
        break;
    }

    // thousands
    if (number >= 1000)
    {
        thousands = number / 1000;
        number = number - (thousands * 1000);
    }

    // hundreds
    if (number >= 100)
    {
        hundreds = number / 100;
        number = number - (hundreds * 100);
    }

    // tens
    if (number >= 10)
    {
        tens = number / 10;
        number = number - (tens * 10);
    }

    // units
    if (number > 0)
    {
        units = number;
        number = number - units;
    }

    cout << "In Roman Numerals, the number " << storeNumber << " is ";

    // thousands
    for (int i = thousands; i > 0; --i)
    {
        cout << "M";
    }

    // hundreds
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
            // DO NOTHING
        }
    }
    
    // tens
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
            // DO NOTHING
        }
    }
    
    // units
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
            // DO NOTHING
        }
    }

    cout << endl << endl;

    }

system("pause");

return 0;
}