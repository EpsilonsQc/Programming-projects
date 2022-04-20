// Convert temperatures (from C to F and from F to C)

#include <iostream>

using namespace std;

int main()
{
    char unitMeasure;
    int temperature = 0;

    cout << ":: CONVERT TEMPERATURES ::" << endl << endl;

    for (int i = 1; i > 0; ++i)
    {
        cout << "Please enter a unit of measure ('C' for Celcius or 'F' for Fahrenheit): ";
        cin >> unitMeasure;

        cout << "Please enter a temperature: ";
        cin >> temperature;

        cout << endl;

        if (unitMeasure == 'C')
        {
            cout << temperature << "C (Celcius) is equivalent to ";
            temperature = (temperature * 9 / 5) + 32;
            cout << temperature << " Fahrenheit" << endl << endl;
        }
        else if (unitMeasure == 'F')
        {
            cout << temperature << "F (Fahrenheit) is equivalent to ";
            temperature = (temperature - 32) * 5 / 9;
            cout << temperature << " Celcius" << endl << endl;
        }
    }

    system("pause");

    return 0;
}