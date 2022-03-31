#include <iostream>

using namespace std;

int main()
{
    unsigned int sum = 0;

    for (unsigned int count = 1; count <= 99; count += 2) {
        sum += count;
        cout << count << endl;
    }
    
    cout << endl;
    cout << "The sum of the odd integers between 1 and 99 is : " << sum << endl;

    return 0;
}