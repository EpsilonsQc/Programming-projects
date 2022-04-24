// Calculate the diameter, circumference and surface of a circle from the radius (user input)

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double radius = 0;
    double diameter = 0;
    double circumference = 0;
    double surface = 0;
    double Pi = 3.14159;

    cout << ":: RADIUS OF A CIRCLE ::" << endl << endl;

    cout << "Please enter the radius (r) of a circle : ";
    cin >> radius;
    cout << endl;

    diameter = radius * 2;
    circumference = Pi * diameter;
    surface = Pi * pow(radius, 2);

    cout << "Diameter:      " << fixed << setprecision(4) << diameter << endl;
    cout << "Circumference: " << fixed << setprecision(4) << circumference << endl;
    cout << "Surface:       " << fixed << setprecision(4) << surface << endl << endl;

    system("pause");

    return 0;
}