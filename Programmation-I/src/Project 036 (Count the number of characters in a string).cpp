// Count the number of characters in a string

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << ":: COUNT THE NUMBER OF CHARACTERS IN A STRING ::" << endl << endl;

	for (int i = 1; i > 0; ++i)
	{
		string userInput;

		cout << "Please enter a phrase : ";
		getline(cin, userInput);
 
		cout << userInput.length() << " characters (with spaces)." << endl << endl;
	}

	system("pause");

	return 0;
}