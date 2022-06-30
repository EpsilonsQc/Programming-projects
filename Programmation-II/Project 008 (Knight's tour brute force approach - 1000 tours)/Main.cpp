// Knight's tour - Brute force approaches (1000 tours)
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 8;
const int TOURS = 1000;
const int MAXMOVES = 65;

bool validMove(int, int, int, const int[][SIZE]);

int main()
{
	int currentRow;
	int currentColumn;
	int moveType;
	int moveNumber;
	int testRow;
	int testColumn;
	int moveTotal[MAXMOVES] = { 0 };
	int goodMove;
	int board[SIZE][SIZE];
	
	int horizontal[SIZE] = { 2, 1, -1, -2, -2, -1, 1, 2 };
	int vertical[SIZE] = { -1, -2, -2, -1, 1, 2, 2, 1 };

	bool done;

	srand(time(0));

	for (int i = 0; i < TOURS; ++i)
	{
		for (int row = 0; row < SIZE; ++row)
		{
			for (int col = 0; col < SIZE; ++col)
			{
				board[row][col] = 0;
			}
		}

		moveNumber = 0;

		currentRow = rand() % SIZE;
		currentColumn = rand() % SIZE;
		board[currentRow][currentColumn] = ++moveNumber;
		done = false;

		while (!done)
		{
			moveType = rand() % SIZE;
			testRow = currentRow + vertical[moveType];
			testColumn = currentColumn + horizontal[moveType];
			goodMove = validMove(testRow, testColumn, moveType, board);

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
					goodMove = validMove(testRow, testColumn, moveType, board);

					if (goodMove)
					{
						currentRow = testRow;
						currentColumn = testColumn;
						board[currentRow][currentColumn] = ++moveNumber;
					}
				}
				if (!goodMove)
				{
					done = true;
				}
			}
			if (moveNumber == 64)
			{
				done = true;
			}
		}
		++moveTotal[moveNumber];
	}
	for (int j = 1; j < MAXMOVES; ++j)
	{
		if (moveTotal[j])
		{
			cout << "There were " << moveTotal[j] << " tours of " << j << " moves." << endl;
		}
	}

	cout << endl;

	system("pause");

	return 0;
}
bool validMove(int testRow, int testColumn, int moveType, const int board[][SIZE])
{
	if (testRow >= 0 && testRow < SIZE && testColumn >= 0 && testColumn < SIZE)
	{
		return board[testRow][testColumn] != 0 ? false : true;
	}
	else
	{
		return false;
	}
}