// Calculating the Value of π from the infinite series
//
// π = 4 - 4/3 + 4/5 - 4/7 + 4/9 - 4/11 + …
//
// Print a table that shows the value of π approximated by computing the first 200,000 terms of this series
// Show how many terms are used before getting a value that begins with 3.14159

#include <iostream>
#include <iomanip>

using namespace std;

int calculatePi();

int main()
{
    int howMany = calculatePi();

    cout << endl << "The value " << "'3.14159'" << " was achieved after a total of " << howMany << " operations." << endl << endl;

    system("pause");

    return 0;
}

int calculatePi()
{   
    int maxOpCount = 200000;
    int lineNumber = 1;
    int divValue = 3;
    bool flag = false;
    double pi = 4.0;

    for (int i = 1; i <= maxOpCount; ++i)
    {
        if (i % 2 == 0)
        {
            pi += 4.0 / divValue;
            divValue += 2;
        }
        else
        {
            pi -= 4.0 / divValue;
            divValue += 2;
        }

        cout << "Line # " << i << " -> " << setprecision(10) << pi << endl;

        if ((static_cast<int>(pi * 100000) == 314159) && !flag)
        {
            lineNumber = i;
            flag = true;
        }
    }

    return lineNumber;
}