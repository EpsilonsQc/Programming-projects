#include <iostream>

using namespace std;

int main()
{
	int age = 0;
	int year = 0;
	bool EnterTheMatrix = false;
	bool Neo = false;
	bool ChoosenOne = false;

	cout << ":: THE MATRIX - Resurrections ::" << endl;
	cout << "You might have been choosen, Neo!" << endl << endl;

	cout << "Please enter the current year: ";
	cin >> year;
	cout << endl;

	cout << "Please enter your current age: ";
	cin >> age;
	cout << endl;

	int birthyear = year - age;

	cout << "Neo, it seems like the year is " << year << ". You are " << age << " years old and your birthyear is either " << birthyear - 1 << " or " << birthyear << "." << endl << endl;

	if (birthyear >= 2000)
	{
		EnterTheMatrix = false;
		cout << "Damn millenial!!!" << endl;
	}
	else
	{
		EnterTheMatrix = true;
		cout << "Well well well..." << endl;
	}

	if (EnterTheMatrix == true)
	{
		Neo = true;
		cout << "Welcome to the Matrix, Neo! ";
	}
	else

	{
		Neo = false;
		cout << "Get out of here, your way too young, Neo! ";
	}

	if (Neo == true)
	{
		ChoosenOne = true;
		cout << "You are the choosen one!" << endl << endl;
		cout << "You'll get used to it, I don't even see the code. All I see is a blond, brunette, redhead." << endl;
		cout << "Choices, while an illusion, is still the only way out of or into the Matrix" << endl << endl;
	}

	else
	{
		ChoosenOne = false;
		cout << "You are NOT the choosen one!" << endl;
		cout << "The Matrix CODE is above your potential. Come back in a few years..." << endl << endl;
	}

	if (ChoosenOne == true)
	{
		cout << "You are now entering The Matrix." << endl << endl;
	}

	else
	{
		cout << "You are stuck in the simulation, how sad!" << endl << endl;
	}

	system("pause");

	return 0;
}
