// Displays the integer equivalent of characters

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char A = 'A';
    char Z = 'Z';
    char b = 'b';
    char f = 'f';
    char zero = '0';
    char one = '1';
    char nine = '9';
    char mul = '*';
    char div = '/';

    cout << ":: INTEGER EQUIVALENT OF CHARACTERS ::" << endl << endl;

    cout << "Integer equivalent of 'A' -> " << static_cast<int>(A) << endl;
    cout << "Integer equivalent of 'Z' -> " << static_cast<int>(Z) << endl;
    cout << "Integer equivalent of 'b' -> " << static_cast<int>(b) << endl;
    cout << "Integer equivalent of 'f' -> " << static_cast<int>(f) << endl;
    cout << "Integer equivalent of '0' -> " << static_cast<int>(zero) << endl;
    cout << "Integer equivalent of '1' -> " << static_cast<int>(one) << endl;
    cout << "Integer equivalent of '9' -> " << static_cast<int>(nine) << endl;
    cout << "Integer equivalent of '*' -> " << static_cast<int>(mul) << endl;
    cout << "Integer equivalent of '/' -> " << static_cast<int>(div) << endl << endl;

    system("pause");

    return 0;
}