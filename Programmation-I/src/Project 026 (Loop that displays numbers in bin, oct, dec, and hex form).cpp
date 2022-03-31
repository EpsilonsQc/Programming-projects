// A loop that displays the numbers from 1 to 256 in decimal, octal, hexadecimal and binary form.

#include <iostream>

using namespace std;

int main()
{

    unsigned int maxNumbers = 256;

    for (unsigned int outputValue = 1; outputValue <= maxNumbers; outputValue++)
    {
        cout << "hexadecimal : " << hex << outputValue << endl;
        cout << "octal       : " << oct << outputValue << endl;
        cout << "decimal     : " << dec << outputValue << endl;

        // START OF THE DECIMAL TO BINARY OPERATIONS
        cout << endl << "DEBUG  : maxNumbers print  : " << maxNumbers << endl; // DEBUG LINE
        cout << "DEBUG  : outputValue print : " << outputValue << endl; // DEBUG LINE

        unsigned int number = 0;
        unsigned int binary = 0;

        number = outputValue; // ASSIGN outputValue [1 to 256] value to number
        cout << "DEBUG  : number (outputValue assigned) : " << number << endl; // DEBUG LINE

        while (number != 0)
        { 
            binary = number % 2; // MODULO 2 [NOT WORKING FOR UNKNOWN REASON]
            cout << "DEBUG  : binary = number % 2 (modulo 2) : " << number << endl; // DEBUG LINE

            number /= 2; // DIV BY 2
            cout << "DEBUG  : number divided by 2 : " << number << endl; // DEBUG LINE

            cout << endl << "Binary : " << binary << endl; // SUPPOSED TO OUTPUT BINARY NUMBER
        }
        // END OF THE DECIMAL TO BINARY OPERATIONS

        cout << endl << endl;

    }

    system("pause");

    return 0;
}