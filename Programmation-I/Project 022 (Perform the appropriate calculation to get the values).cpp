// Perform the appropriate calculation to get the values

#include <iostream>

using namespace std;

int main()
{

    for (unsigned int y = 1; y != 10; ++y)
    {
        cout << (static_cast<double> (y) / 10) << endl;
    }

    cout << endl;

    system("pause");

    return 0;
}