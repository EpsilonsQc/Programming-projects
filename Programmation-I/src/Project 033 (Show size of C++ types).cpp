// Show size of C++ types

#include <iostream>

using namespace std;

int main()
{
    cout << ":: SHOW SIZE OF C++ TYPES ::" << endl << endl;
    
    cout << "Size of BOOL:         " << sizeof(bool) << " bytes" << endl;
    cout << "Size of CHAR:         " << sizeof(char) << " bytes" << endl;
    cout << "Size of SHORT:        " << sizeof(short) << " bytes" << endl;
    cout << "Size of INTEGER:      " << sizeof(int) << " bytes" << endl;
    cout << "Size of LONG LONG:    " << sizeof(long long) << " bytes" << endl;
    cout << "Size of FLOAT:        " << sizeof(float) << " bytes" << endl;
    cout << "Size of DOUBLE:       " << sizeof(double) << " bytes" << endl;
    cout << "Size of STRING:      " << sizeof(string) << " bytes" << endl << endl;

    system("pause");

    return 0;
}