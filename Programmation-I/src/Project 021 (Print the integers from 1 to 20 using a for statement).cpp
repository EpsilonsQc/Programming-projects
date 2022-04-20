// Print the integers from 1 to 20 using a for statement and the unsigned int counter variable x 
// Print only 5 integers per line. 

#include <iostream>

using namespace std;

int main()
{

    for (unsigned int x = 1; x <= 20; ++x)
    {
        if (x % 5 == 0)
        {
            cout << x << endl;
        }
        else
        {
            cout << x << '\t';
        }
    }

    cout << endl;

    system("pause");

    return 0;
}