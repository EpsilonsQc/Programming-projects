// Telephone-number word generator
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <fstream>

using namespace std;

void wordGenerator(const int* const);

int main()
{
	int phoneNumber[7] = { 0 };

	cout << "Enter a phone number (digits 2 through 9) " << "in the form: xxx-xxxx" << endl;

	for (int u = 0, v = 0; u < 8; ++u) 
	{
		int i = cin.get();

		if (isdigit(i))
		{
			phoneNumber[v++] = i - '0';
		}
		wordGenerator(phoneNumber);
	}

	cout << endl;

	system("pause");

	return 0;
}

void wordGenerator(const int* const n)
{
	ofstream outFile("phone.dat");
	
	const char* phoneLetters[10] = 
	{ 
		"",
		"",
		"ABC",
		"DEF",
		"GHI",
		"JKL",
		"MNO",
		"PRS",
		"TUV",
		"WXY" 
	};

	if (!outFile) 
	{
		cerr << "\"phone.dat\" could not be opened." << endl;
		exit(EXIT_FAILURE);
	}

	int count = 0;

	for (int i1 = 0; i1 <= 2; ++i1)
	for (int i2 = 0; i2 <= 2; ++i2)
	for (int i3 = 0; i3 <= 2; ++i3)
	for (int i4 = 0; i4 <= 2; ++i4)
	for (int i5 = 0; i5 <= 2; ++i5)
	for (int i6 = 0; i6 <= 2; ++i6)
	for (int i7 = 0; i7 <= 2; ++i7) 
	{
	outFile << phoneLetters[n[0]][i1]
			<< phoneLetters[n[1]][i2]
			<< phoneLetters[n[2]][i3]
			<< phoneLetters[n[3]][i4]
			<< phoneLetters[n[4]][i5]
			<< phoneLetters[n[5]][i6]
			<< phoneLetters[n[6]][i7] 
			<< ' ';

		if (++count % 9 == 0)
		{
			outFile << endl;
		}
	}

	outFile <<  endl << "Phone number is ";

		for (int i = 0; i < 7; ++i) 
		{
			if (i == 3)
			{
				outFile << '-';
			}

			outFile << n[i];
		}

	outFile.close();
}