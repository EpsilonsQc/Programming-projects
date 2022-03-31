// Sum the odd integers between 1 and 99 using a for statement using the unsigned int variables sum and count.

#include <iostream>

using namespace std;

int main()
{
    unsigned int sum = 0;

    for (unsigned int count = 1; count <= 99; count++) {

        if (count % 2 != 0)
        {
            sum += count;
        }
    }

    cout << "The sum of the odd integers between 1 and 99 is : " << sum << endl << endl;

    system("pause");

    return 0;
}
