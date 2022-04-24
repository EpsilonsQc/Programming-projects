// Using "De Morgan’s laws" to write equivalent expressions
// Show that both the original expression and the new expression in each case produce the same value

#include <iostream>

using namespace std;

int main()
{

    int x = 0;
    int y = 0;
    int a = 0;
    int b = 0;
    int g = 0;
    int i = 0;
    int j = 0;

    cout << "If both results for a given exercise (a, b, c or d) is true, it" << endl;
    cout << "means both expression of a given exercise produce the same value." << endl << endl;

    cout << "Exercise a)" << endl << endl;

        cout << "Result : " << (!(x < 5) && !(y >= 7)) << endl;
        cout << "Result : " << (!((x < 5) || (y >= 7))) << endl << endl;

    cout << "Exercise b)" << endl << endl;

         cout << "Result : " << (! ( a == b ) || !( g != 5 )) << endl;
         cout << "Result : " << (! (( a == b ) && ( g != 5 ))) << endl << endl;
 
    cout << "Exercise c)" << endl << endl;

         cout << "Result : " << (! (( x <= 8 ) && ( y > 4 ))) << endl;
         cout << "Result : " << (! ( x <= 8 ) || !( y > 4 )) << endl << endl;

    cout << "Exercise d)" << endl << endl;

         cout << "Result : " << (! (( i > 4 ) || ( j <= 6 ))) << endl;
         cout << "Result : " << (! ( i > 4 ) && !( j <= 6 )) << endl << endl;

    system("pause");

    return 0;
}