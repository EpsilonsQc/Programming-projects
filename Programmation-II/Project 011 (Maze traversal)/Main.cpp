// Maze traversal
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>

using namespace std;

enum Direction 
{ 
	DOWN,
	RIGHT,
	UP,
	LEFT
};

const int X_START = 2;
const int Y_START = 0;

void mazeTraversal(char[][12], int, int, int);
void printMaze(const char[][12]);
bool validMove(const char[][12], int, int);
bool coordsAreEdge(int, int);

int main()
{
	char maze[12][12] =
	{ 
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#'},
		{'.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#'},
		{'#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.'},
		{'#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#'},
		{'#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'} 
	};

	mazeTraversal(maze, X_START, Y_START, RIGHT);

	system("pause");

	return 0;
}


void mazeTraversal(char maze[][12], int xCoord, int yCoord, int direction)
{
	static bool flag = false;
	
	maze[xCoord][yCoord] = 'x';
	printMaze(maze);
	
	if (coordsAreEdge(xCoord, yCoord) && xCoord != X_START && yCoord != Y_START) 
	{
		cout << endl << "Maze successfully exited!" << endl << endl;
		return;
	}
	else if (xCoord == X_START && yCoord == X_START && flag) 
	{
		cout << endl << "Arrived back at the starting location." << endl << endl;;
		return;
	}
	else 
	{
		flag = true;
		
		for (int move = direction, count = 0; count < 4; ++count, ++move, move %= 4)
		{
			switch (move)
			{
			case DOWN:
				if (validMove(maze, xCoord + 1, yCoord))
				{
					mazeTraversal(maze, xCoord + 1, yCoord, LEFT);
					return;
				}
				break;

			case RIGHT:
				if (validMove(maze, xCoord, yCoord + 1))
				{
					mazeTraversal(maze, xCoord, yCoord + 1, DOWN);
					return;
				}
				break;

			case UP:
				if (validMove(maze, xCoord - 1, yCoord))
				{
					mazeTraversal(maze, xCoord - 1, yCoord, RIGHT);
					return;
				}
				break;

			case LEFT:
				if (validMove(maze, xCoord, yCoord - 1))
				{
					mazeTraversal(maze, xCoord, yCoord - 1, UP);
					return;
				}
				break;
			}
		}
	}
}

bool validMove(const char maze[][12], int r, int c)
{
	return (r >= 0 && r <= 11 && c >= 0 && c <= 11 && maze[r][c] != '#');
}

bool coordsAreEdge(int x, int y)
{
	if ((x == 0 || x == 11) && (y >= 0 && y <= 11))
	{
		return true;
	}
	else if ((y == 0 || y == 11) && (x >= 0 && x <= 11))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void printMaze(const char maze[][12])
{
	for (int x = 0; x < 12; ++x) 
	{
		for (int y = 0; y < 12; ++y)
		{
			cout << maze[x][y] << ' ';
		}

		cout << endl;
	}
	
	cout << endl << "Hit return to see next move" << endl;
	cin.get();
}