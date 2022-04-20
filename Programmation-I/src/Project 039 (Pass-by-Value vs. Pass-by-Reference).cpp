// Pass-by-Value vs. Pass-by-Reference

#include <iostream>

using namespace std;

int tripleByValue(int number);
int tripleByReference(int& number);

int main()
{
	int count = 2;

	cout << ":: PASS-BY-VALUE vs. PASS-BY-REFERENCE ::" << endl << endl;

	cout << "Triple by value result is: " << tripleByValue(count) << " and count: " << count << endl;
	cout << "Triple by reference result is: " << tripleByReference(count) << " and count: " << count << endl;

	system("pause");

	return 0;
}

int tripleByValue(int number)
{
	return number *= 3;
}

int tripleByReference(int& number)
{
	return number *= 3;
}