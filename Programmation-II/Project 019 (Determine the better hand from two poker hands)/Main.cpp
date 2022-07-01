// Determine the better hand from two poker hands
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <iomanip>

using namespace std;

void displayIntro();
void shuffle(int[][13]);
void deal(const int[][13], const char* [], const char* [], int[][2]);
void pairs(const int[][13], const int[][2], const char* []);
void threeOfKind(const int[][13], const int[][2], const char* []);
void fourOfKind(const int[][13], const int[][2], const char* []);
void flushHand(const int[][13], const int[][2], const char* []);
void straightHand(const int[][13], const int[][2], const char* [], const char* []);
int endOfProgram();

int main()
{
	const char* suit[] =
	{
		"Hearts",
		"Diamonds",
		"Clubs",
		"Spades"
	},

	* face[] =
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

	displayIntro();
	
	for (int i = 0; i <= 1; i++)
	{	
		int deck[4][13] = { 0 };
		int hand[5][2] = { 0 };

		shuffle(deck);
		deal(deck, face, suit, hand);
		pairs(deck, hand, face);
		threeOfKind(deck, hand, face);
		fourOfKind(deck, hand, face);
		flushHand(deck, hand, suit);
		straightHand(deck, hand, suit, face);
	}

	endOfProgram();
}

void shuffle(int wDeck[][13])
{
	int row, column;

	for (int card = 1; card <= 52; ++card)
	{
		do
		{
			row = rand() % 4;
			column = rand() % 13;

		} while (wDeck[row][column] != 0);

		wDeck[row][column] = card;
	}
}

void deal(const int wDeck[][13], const char* wFace[], const char* wSuit[], int wHand[][2])
{
	int r = 0;

	cout << "The hand is:" << endl << endl;

	for (int card = 1; card < 6; ++card)
	{
		for (int row = 0; row <= 3; ++row)
		{
			for (int column = 0; column <= 12; ++column)
			{
				if (wDeck[row][column] == card)
				{
					wHand[r][0] = row;
					wHand[r][1] = column;
					cout << setw(5) << wFace[column]
						<< " of " << setw(8) << setiosflags(ios::left)
						<< wSuit[row] << (card % 2 == 0 ? '\n' : '\t')
						<< resetiosflags(ios::left);
					++r;
				}
			}
		}
	}

	cout << endl;
}

void pairs(const int wDeck[][13], const int wHand[][2], const char* wFace[])
{
	int counter[13] = { 0 };

	for (int r = 0; r < 5; ++r)
	{
		++counter[wHand[r][1]];
	}

	cout << endl;

	for (int p = 0; p < 13; ++p)
	{
		if (counter[p] == 2)
		{
			cout << "The hand contains a pair of " << wFace[p] << "'s." << endl;
		}
	}
}

void threeOfKind(const int wDeck[][13], const int wHand[][2], const char* wFace[])
{
	int counter[13] = { 0 };

	for (int r = 0; r < 5; ++r)
	{
		++counter[wHand[r][1]];
	}

	for (int t = 0; t < 13; t++)
	{
		if (counter[t] == 3)
		{
			cout << "The hand contains three " << wFace[t] << "'s." << endl;
		}
	}
}

void fourOfKind(const int wDeck[][13], const int wHand[][2], const char* wFace[])
{
	int counter[13] = { 0 };

	for (int r = 0; r < 5; ++r)
	{
		++counter[wHand[r][1]];
	}

	for (int k = 0; k < 13; ++k)
	{
		if (counter[k] == 4)
		{
			cout << "The hand contains four " << wFace[k] << "'s." << endl;
		}
	}
}

void flushHand(const int wDeck[][13], const int wHand[][2], const char* wSuit[])
{
	int count[4] = { 0 };

	for (int r = 0; r < 5; ++r)
	{
		++count[wHand[r][0]];
	}

	for (int f = 0; f < 4; ++f)
	{
		if (count[f] == 5)
		{
			cout << "The hand is a flush of " << wSuit[f] << "s." << endl;
		}
	}
}

void straightHand(const int wDeck[][13], const int wHand[][2], const char* wSuit[], const char* wFace[])
{
	int s[5] = { 0 }, temp;

	for (int r = 0; r < 5; ++r)
	{
		s[r] = wHand[r][1];
	}

	for (int pass = 1; pass < 5; ++pass)
	{
		for (int comp = 0; comp < 4; ++comp)
		{
			if (s[comp] > s[comp + 1])
			{
				temp = s[comp];
				s[comp] = s[comp + 1];
				s[comp + 1] = temp;
			}
		}
	}

	if (s[4] - 1 == s[3] && s[3] - 1 == s[2] && s[2] - 1 == s[1] && s[1] - 1 == s[0])
	{
		cout << "The hand contains a straight consisting of" << endl;

		for (int j = 0; j < 5; ++j)
		{
			cout << wFace[wHand[j][1]] << " of " << wSuit[wHand[j][0]] << endl;
		}
	}
}

void displayIntro()
{
	cout << "======================================================" << endl;
	cout << ".:: DETERMINE THE BETTER HAND FROM TWO POKER HANDS ::." << endl;
	cout << "======================================================" << endl << endl;
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