// Print the integers from 1 to 20 using a while loop and the unsigned int counter variable x 
// Print only 5 integers per line. 

#include <iostream>

using namespace std;

int main()
{
    unsigned int x = 1;

    while (x <= 20) 
    {
        if (x % 5 == 0) 
        {
            cout << x << endl;
            ++x;
        }
        else 
        {
            cout << x << '\t';
            ++x;
        }
    }

    system("pause");

    return 0;
}