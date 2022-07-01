// Sizeof operator
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

void displayIntro();
int endOfProgram();

int main()
{
	displayIntro();
	
	ofstream outFile("datasize.dat");

	if (!outFile) 
	{
		cerr << "Unable to open \"datasize.dat\"." << endl;
		exit(EXIT_FAILURE);
	}

	outFile << "Data type" << setw(24) << "Size"
			<< endl << "char" << setw(21) << sizeof(char)
			<< endl << "unsigned char" << setw(12) << sizeof(unsigned char)
			<< endl << "short int" << setw(16) << sizeof(short int)
			<< endl << "unsigned short int" << setw(7) << sizeof(unsigned short)
			<< endl << "int" << setw(22) << sizeof(int)
			<< endl << "unsigned int" << setw(13) << sizeof(unsigned)
			<< endl << "long int" << setw(17) << sizeof(long)
			<< endl << "unsigned long int" << setw(8) << sizeof(unsigned long)
			<< endl << "double" << setw(19) << sizeof(double)
			<< endl << "long double" << setw(14) << sizeof(long double);

	outFile.close();

	cout << "The file \"datasize.dat\" has been created sucessfully." << endl;

	endOfProgram();
}

void displayIntro()
{
	cout << "=======================" << endl;
	cout << ".:: SIZEOF OPERATOR ::." << endl;
	cout << "=======================" << endl << endl;
}

int endOfProgram()
{
	cout << endl;
	cout << "====================" << endl;
	cout << ":: END OF PROGRAM ::" << endl;
	cout << "====================" << endl << endl;

	system("pause");

	return 0;
}