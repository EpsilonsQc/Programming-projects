// Calculate the value of 2.5 raised to the power 3 using function pow. 
// Print the result with a precision of 2 in a field width of 10 positions.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << fixed << setprecision(2) << setw(10) << pow(2.5, 3) << endl << endl;

    system("pause");

    return 0;
}