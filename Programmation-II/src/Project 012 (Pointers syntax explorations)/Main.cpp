// Pointers syntax explorations 
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>

using namespace std;

int main()
{
    int* zPtr; // zPtr will reference built-in array z 
    int number;
    int z[5]{ 1, 2, 3, 4, 5 };

    zPtr = z; // initialize zPtr with array z

    // debug line
    cout << "The (original) address of zPtr is: " << zPtr << endl;

    ++zPtr;

    // debug line
    cout << "The (+1) address of zPtr is:       " << zPtr << endl << endl;

    // use pointer to get first value of a built-in array 
    number = *zPtr;

    // debug line
    cout << "The value of *zPtr is:   " << number << endl;
    --zPtr; // remove increment from line 19

    // assign built-in array index/subscript 2 (the value 3) to number 
    number = zPtr[2];

    // debug line
    cout << "The value of zPtr[2] is: " << number << endl << endl;

    // debug line
    cout << "Enter for loop statement" << endl;

    // display entire built-in array z
    for (size_t i{ 0 }; i < 5; ++i)
    {
        cout << "Array element at index [" << i << "]: ";
        cout << zPtr[i] << endl;
    }

    // debug line
    cout << "Exit for loop statement" << endl << endl;

    ++z[0];
    cout << "The address of z is:    " << z << endl;

    ++zPtr;
    cout << "The address of zPtr is: " << zPtr << endl;

    cout << endl;

    system("pause");

    return 0;
}
