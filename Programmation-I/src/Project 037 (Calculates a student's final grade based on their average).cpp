// Calculates a student's final grade based on their average.

#include <iostream>

using namespace std;

int main()
{
	int note_1 = 0;
	int note_2 = 0;
	int note_3 = 0;
	int note_4 = 0;
	int note_5 = 0;

	int total = 0;
	int average = 0;

	cout << ":: CALCULATES A STUDENT'S FINAL GRADE BASED ON THEIR AVERAGE ::" << endl << endl;

	for (int i = 1; i > 0; ++i)
	{
		cout << "Please enter your note (1) to obtain your grade : ";
		cin >> note_1;

		cout << "Please enter your note (2) to obtain your grade : ";
		cin >> note_2;

		cout << "Please enter your note (3) to obtain your grade : ";
		cin >> note_3;

		cout << "Please enter your note (4) to obtain your grade : ";
		cin >> note_4;

		cout << "Please enter your note (5) to obtain your grade : ";
		cin >> note_5;

		total = note_1 + note_2 + note_3 + note_4 + note_5;
		average = total / 5;

		if (average <= 100 && average >= 91)
			cout << "Your grade is : A" << endl << endl;
		else if (average <= 90 && average >= 75)
			cout << "Your grade is : B" << endl << endl;
		else if (average <= 74 && average >= 65)
			cout << "Your grade is : C" << endl << endl;
		else if (average <= 64 && average >= 60)
			cout << "Your grade is : D" << endl << endl;
		else if (average <= 59 && average >= 0)
			cout << "Your grade is : E" << endl << endl;
		else
			cout << "Invalid input!" << endl << endl;
	}

	system("pause");

	return 0;
}