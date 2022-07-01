// Sieve of Eratosthenes with bitset
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

void displayIntro();
int endOfProgram();

int main()
{
	displayIntro();
	
	const int size = 1024;
	int i;
	int value;
	int counter;
	
	bitset< size > sieve;

	sieve.flip();

	int finalBit = sqrt(sieve.size()) + 1;
	
	for (i = 2; i < finalBit; ++i)
	{
		if (sieve.test(i))
		{
			for (int j = 2 * i; j < size; j += i)
			{
				sieve.reset(j);
			}
		}
	}
	
	cout << "The prime numbers in the range 2 to 1023 are:" << endl;;

	for (i = 2, counter = 0; i < size; ++i)
	{
		if (sieve.test(i))
		{
			cout << setw(5) << i;

			if (++counter % 12 == 0)
			{
				cout << endl;
			}
				
		}
	}

	cout << endl << endl << "Enter a value from 1 to 1023 (-1 to end): ";
	cin >> value;

	while (value != -1) 
	{
		if (sieve[value])
		{
			cout << value << " is a prime number" << endl;;
		}
		else 
		{
			cout << value << " is not a prime number" << endl << "prime factor(s): ";

			bool print = true;
				
			for (int f = 2; f < size; )
			{
				if (sieve.test(f) && value % f == 0)
				{
					if (print)
					{
						cout << f << ' ';
					}

					value /= f;

					if (value <= 1)
					{
						break;
					}

					print = false;
				}
				else
				{
					++f;
					print = true;
				}
			}
			
			cout << endl;
		}
			
		cout << endl << "Enter a value from 2 to 1023 (-1 to end): ";
		cin >> value;
	}

	endOfProgram();
}

void displayIntro()
{
	cout << "=========================================" << endl;
	cout << ".:: SIEVE OF ERATOSTHENES WITH BITSET ::." << endl;
	cout << "=========================================" << endl << endl;
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