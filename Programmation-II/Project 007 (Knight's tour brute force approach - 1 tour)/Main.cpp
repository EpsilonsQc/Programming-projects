// Knight's tour - Brute force approaches (1 tour)
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 8;

bool validMove(int, int, const int[][SIZE]);
void printBoard(const int[][SIZE]);

int main()
{
	int currentRow;
	int currentColumn;
	int moveType;
	int moveNumber = 0;
	int testRow;
	int testColumn;
	int board[SIZE][SIZE] = { 0 };
	
	int horizontal[SIZE] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int vertical[SIZE] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	bool done;
	bool goodMove;

	srand(time(0));

	currentRow = rand() % SIZE;
	currentColumn = rand() % SIZE;

	board[currentRow][currentColumn] = ++moveNumber;

	done = false;

	while (!done)
	{
		moveType = rand() % SIZE;
		testRow = currentRow + vertical[moveType];
		testColumn = currentColumn + horizontal[moveType];
		goodMove = validMove(testRow, testColumn, board);

		if (goodMove)
		{
			currentRow = testRow;
			currentColumn = testColumn;
			board[currentRow][currentColumn] = ++moveNumber;
		}
		else
		{
			for (int count = 0; count < SIZE - 1 && !goodMove; ++count)
			{
				moveType = ++moveType % SIZE;
				testRow = currentRow + vertical[moveType];
				testColumn = currentColumn + horizontal[moveType];
				goodMove = validMove(testRow, testColumn, board);

				if (goodMove)
				{
					currentRow = testRow;
					currentColumn = testColumn;
					board[currentRow][currentColumn] = ++moveNumber;
				}
			}
		}

		if (!goodMove)
		{
			done = true;
		}

		if (moveNumber == 64)
		{
			done = true;
		}
	}

	cout << "The tour has ended with " << moveNumber << " moves." << endl;

	if (moveNumber == 64)
	{
		cout << "This was a full tour!" << endl;
	}
	else
	{
		cout << "This was not a full tour." << endl;
	}

	cout << "The board for this random test was:" << endl << endl;
	printBoard(board);

	system("pause");

	return 0;
}

bool validMove(int row, int column, const int workBoard[][SIZE])
{
	return (row >= 0 && row < SIZE&& column >= 0 && column < SIZE&& workBoard[row][column] == 0);
}

void printBoard(const int board[][SIZE])
{
	cout << "   0  1  2  3  4  5  6  7" << endl;

	for (int row = 0; row < SIZE; ++row)
	{
		cout << row;

		for (int col = 0; col < SIZE; ++col)
		{
			cout << setw(3) << board[row][col];
		}

		cout << endl;
	}

	cout << endl;
}