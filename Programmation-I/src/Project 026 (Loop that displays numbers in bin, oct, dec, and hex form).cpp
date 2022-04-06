// A loop that displays the numbers from 1 to 256 in hexadecimal, decimal, octal and binary form.

#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    string binaryChunk = "";

    for (unsigned int outputValue = 1; outputValue <= 256; ++outputValue)
    {
        cout << "Hexadecimal : " << hex << outputValue << endl;
        cout << "Decimal     : " << dec << outputValue << endl;
        cout << "Octal       : " << oct << outputValue << endl;

        binaryChunk = bitset<12>(outputValue).to_string(); // ASSIGN THE BINARY NUMBER TO A STRING
        binaryChunk.insert(4, 1, ' '); // ADD AN EMPTY SPACE ONE TIME AT POSITION 4 (CREATE CHUNK 1)
        binaryChunk.insert(9, 1, ' '); // ADD AN EMPTY SPACE ONE TIME AT POSITION 9 (CREATE CHUNK 2)

        cout << "Binary      : " << binaryChunk << endl << endl;
    }

    system("pause");

    return 0;
}