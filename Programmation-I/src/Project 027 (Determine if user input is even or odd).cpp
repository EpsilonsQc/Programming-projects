// Asks the user to enter a number and displays whether the number is even or odd.

#include <iostream>

using namespace std;

bool isEven(int userInput);

int main()
{
    int userInput = 0;

    cout << ":: DETERMINE IF USER INPUT IS EVEN OR ODD ::" << endl << endl;

    for (int i = 1; i > 0; ++i)
    {
        cout << "Please enter an integer: ";
        cin >> userInput;

        if (isEven(userInput))
        {
            cout << "This integer is even." << endl << endl;
        }
        else
        {
            cout << "This integer is odd." << endl << endl;
        }
    }

    system("pause");

    return 0;
}

bool isEven(int userInput)
{
    return userInput % 2 == 0;
}