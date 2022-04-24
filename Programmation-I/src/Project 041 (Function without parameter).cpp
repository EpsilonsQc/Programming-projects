// Function without parameter which lets you know how many times it has been called

#include <iostream>

using namespace std;

int noParameter();

int counts = 0;

int main()
{
    int functionCount = 0;

    for (int i = 1; i <= 10; ++i)
    {
        functionCount = noParameter();
        cout << "The function has been called " << functionCount << " time(s)." << endl;
    }

    system("pause");

    return 0;
}

int noParameter()
{
    return ++counts;
}