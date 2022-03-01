// Asks for the user's first name and prints "Hello <first name>!"

#include <iostream>

using namespace std;

int main()
{
    string UserInput = "first_name";

    cout << "Please enter your first name: ";
    cin >> UserInput;
    cout << "Hello " << UserInput << "!";

    system("pause");

    return 0;
}
