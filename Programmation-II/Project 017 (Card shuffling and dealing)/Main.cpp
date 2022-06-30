// Card shuffling and dealing
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <iomanip> 

using namespace std;

void shuffle(int[][13]);
void deal(const int[][13], const char* [], const char* []);

int main()
{
	int card = 1;
	int deck[4][13] = { 0 };
	
	const char* suit[4] = 
	{ 
		"Hearts",
		"Diamonds",
		"Clubs",
		"Spades" 
	};
	
	const char* face[13] = 
	{ 
		"Ace",
		"Deuce",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten",
		"Jack",
		"Queen",
		"King" 
	};

	srand(time(0));

	for (int row = 0; row <= 3; ++row)
	{
		for (int column = 0; column <= 12; ++column)
		{
			deck[row][column] = card++;
		}
	}

	shuffle(deck);
	deal(deck, face, suit);

	cout << endl;

	system("pause");

	return 0;
}

void shuffle(int workDeck[][13])
{
	int temp;
	int randRow;
	int randColumn;

	for (int row = 0; row <= 3; ++row)
	{
		for (int column = 0; column <= 12; ++column) 
		{
			randRow = rand() % 4;
			randColumn = rand() % 13;
			temp = workDeck[row][column];
			workDeck[row][column] = workDeck[randRow][randColumn];
			workDeck[randRow][randColumn] = temp;
		}
	}
}

void deal(const int workDeck2[][13], const char* workFace[], const char* workSuit[])
{
	for (int card = 1; card <= 52; ++card)
	{
		for (int row = 0; row <= 3; ++row)
		{
			for (int column = 0; column <= 12; ++column)
			{
				if (workDeck2[row][column] == card)
				{
					cout << setw(8) << workFace[column] << " of "
						 << setiosflags(ios::left) << setw(8)
						 << workSuit[row]
						 << (card % 2 == 0 ? '\n' : '\t')
						 << resetiosflags(ios::left);
					
					break;
				}
			}
		}
	}
}