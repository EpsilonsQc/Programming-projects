// Calculates the hypotenuse of a right triangle

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double sideA = 0;
    double sideB = 0;
    double hypotenuse = 0;

    cout << ":: CALCULATES THE HYPOTENUSE OF A RIGHT TRIANGLE ::" << endl << endl;

    for (int i = 1; i > 0; ++i)
    {
        cout << "Enter the value of side A: ";
        cin >> sideA;

        cout << "Enter the value of side B: ";
        cin >> sideB;

        hypotenuse = hypot(sideA, sideB);

        cout << endl << "The value of the hypotenuse (side C) is: " << hypotenuse << endl << endl;
    }

    system("pause");

    return 0;
}