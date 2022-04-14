// Convert angles to radians

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double angle = 0;
    double radians = 0;
    double Pi = 3.14159;

    cout << ":: CONVERT ANGLES TO RADIANS ::" << endl << endl;

    for (int i = 1; i > 0; ++i)
    {
        cout << "Please enter an angle (in degree) : ";
        cin >> angle;

        radians = angle * Pi / 180;

        cout << "Radians: " << fixed << setprecision(12) << radians << endl << endl;
    }

    system("pause");

    return 0;
}