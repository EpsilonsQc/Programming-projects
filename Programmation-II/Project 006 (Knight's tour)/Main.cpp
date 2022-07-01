// Knight's tour
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <iomanip>

using namespace std;

const int SIZE = 8;

void displayIntro();
void clearBoard(int[][SIZE]);
void printBoard(const int[][SIZE]);
bool validMove(int, int, const int[][SIZE]);
int endOfProgram();

int main()
{		
    int board[SIZE][SIZE];
    int currentRow;
    int currentColumn;
    int moveNumber = 0;
	
    int access[SIZE][SIZE] =
    {
        2, 3, 4, 4, 4, 4, 3, 2,
        3, 4, 6, 6, 6, 6, 4, 3,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        4, 6, 8, 8, 8, 8, 6, 4,
        3, 4, 6, 6, 6, 6, 4, 3,
        2, 3, 4, 4, 4, 4, 3, 2
    };
	
    int testRow;
    int testColumn;
    int minRow;
    int minColumn;
    int minAccess = 9;
    int accessNumber;
	
    int horizontal[SIZE] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int vertical[SIZE] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	
    bool done;
	
    srand(time(0));
    
    clearBoard(board);
    currentRow = rand() % 8;
    currentColumn = rand() % 8;
    board[currentRow][currentColumn] = ++moveNumber;
    done = false;
    
    while (!done) 
    {
        accessNumber = minAccess;
		
        for (int moveType = 0; moveType < SIZE; ++moveType) 
        {
            testRow = currentRow + vertical[moveType];
            testColumn = currentColumn + horizontal[moveType];
            
            if (validMove(testRow, testColumn, board)) 
            {
                
                if (access[testRow][testColumn] < accessNumber) 
                {
                    accessNumber = access[testRow][testColumn];
                    minRow = testRow;
                    minColumn = testColumn;
                }
				
                --access[testRow][testColumn];
            }
        }
		
        if (accessNumber == minAccess)
        {
			done = true;
		}
		else
		{
			currentRow = minRow;
			currentColumn = minColumn;
			board[currentRow][currentColumn] = ++moveNumber;
        }
    }
	
    displayIntro();
	
    cout << "The tour ended with " << moveNumber << " moves." << endl;
    
    if (moveNumber == 64)
    {
        cout << "This was a full tour!" << endl << endl;
    }
    else
    {
        cout << "This was not a full tour." << endl << endl;
    }

    cout << "The board for this test is:" << endl << endl;
	
    printBoard(board);
    
    endOfProgram();
}
    

void clearBoard(int workBoard[][SIZE])
{
    for (int row = 0; row < SIZE; ++row)
    {
        for (int col = 0; col < SIZE; ++col)
        {
            workBoard[row][col] = 0;
        }

    }
}

void printBoard(const int workBoard[][SIZE])
{
    cout << "   0  1  2  3  4  5  6  7" << endl;

    for (int row = 0; row < SIZE; ++row) 
    {
        cout << row;
        
        for (int col = 0; col < SIZE; ++col)
        {
            cout << setw(3) << workBoard[row][col];
        }
        cout << endl;
    }
}

bool validMove(int row, int column, const int workBoard[][SIZE])
{
    return (row >= 0 && row < SIZE&& column >= 0 && column < SIZE && workBoard[row][column] == 0);
}

void displayIntro()
{
    cout << "=====================" << endl;
    cout << ".:: KNIGHT'S TOUR ::." << endl;
    cout << "=====================" << endl << endl;
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