// Print the value 333.546372 in a 15-character field with precisions of 1 , 2 and 3.
// Print each number on the same line, left-justify each number in its field.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    for (int PrecisionLevel = 1; PrecisionLevel <= 3; PrecisionLevel++)
    {
        cout << fixed << left << setprecision(PrecisionLevel) << setw(15) << 333.546372;
    }

    cout << endl;

    system("pause");

    return 0;
}