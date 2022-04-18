// TIC TAC TOE v1.0

#include <iostream>

using namespace std;

// FUNCTIONS PROTOTYPES
void determineWhoPlayFirst();
void verifyIsFirstGame();
void drawTicTacToe();
void resetTicTacToe();
void playerTurn();
void cpuTurn();
void cpuHasPlayed();
void placeTokenOnBoard();
void assignPlayersToken();
void winOrDrawMessages();
void pressEnterToContinue();
void startNewGame();
bool checkTicTacToe();
int checkForOccupiedCase(int);
int checkPlayerInput();
int checkCpuInput();
int endOfProgram();

// GLOBAL SCOPE VARIABLES
char case_1 = '1';
char case_2 = '2';
char case_3 = '3';
char case_4 = '4';
char case_5 = '5';
char case_6 = '6';
char case_7 = '7';
char case_8 = '8';
char case_9 = '9';

char continueOrNot = ' ';
char playersToken = ' ';

bool playerWin = false;
bool computerWin = false;
bool humanIsPlaying = true;
bool isFirstGame = true;
bool endGame = false;

int determineWhoWillPlay = 0;
int caseTransfer = 0;
int playerMove = 0;
int cpuMove = 0;

int main()
{
	do
	{
		determineWhoPlayFirst();
		resetTicTacToe();
		drawTicTacToe();

		while (endGame == false)
		{
			if (determineWhoWillPlay == 1) // PLAYER TURN
			{
				assignPlayersToken();
				playerTurn();
				drawTicTacToe();
				playerWin = checkTicTacToe();
				winOrDrawMessages();
				determineWhoWillPlay = 2;
			}
			else if (determineWhoWillPlay == 2) // COMPUTER TURN
			{
				pressEnterToContinue();
				assignPlayersToken();
				cpuTurn();
				drawTicTacToe();
				cpuHasPlayed();
				computerWin = checkTicTacToe();
				winOrDrawMessages();
				determineWhoWillPlay = 1;
			}
		}

		startNewGame();

	} while (continueOrNot != 'q' && continueOrNot != 'Q');

	endOfProgram();
}

// DETERMINE WHO WILL PLAY FIRST (RANDOMIZED)
void determineWhoPlayFirst()
{
	srand(static_cast<unsigned int> (time(0)));
	determineWhoWillPlay = 1 + rand() % 2;
}

// OUTPUT THAT VERIFY IF IT'S THE FIRST OR A SUBSEQUENT MATCHES
void verifyIsFirstGame()
{
	if (!isFirstGame)
	{
		cout << "   =========================================" << endl;
		cout << "   .:: START OF A NEW GAME [FRESH BOARD] ::." << endl;
		cout << "   =========================================" << endl << endl;
		isFirstGame = true;
	}
}

// DISPLAY THE GAME BOARD
void drawTicTacToe()
{
	verifyIsFirstGame();

	cout << "\t    **TIC-TAC-TOE**" << endl;
	cout << "\t     +---+---+---+" << endl;
	cout << "\t     | " << case_1 << " | " << case_2 << " | " << case_3 << " | " << endl;
	cout << "\t     +---+---+---+" << endl;
	cout << "\t     | " << case_4 << " | " << case_5 << " | " << case_6 << " | " << endl;
	cout << "\t     +---+---+---+" << endl;
	cout << "\t     | " << case_7 << " | " << case_8 << " | " << case_9 << " | " << endl;
	cout << "\t     +---+---+---+" << endl << endl;
}

// RESET THE GAME BOARD FOR A FRESH GAME START
void resetTicTacToe()
{
	case_1 = '1';
	case_2 = '2';
	case_3 = '3';
	case_4 = '4';
	case_5 = '5';
	case_6 = '6';
	case_7 = '7';
	case_8 = '8';
	case_9 = '9';
}

// ASSIGN PLAYERS TOKEN ACCORDING TO WHO PLAY FIRST
void assignPlayersToken()
{
	if (determineWhoWillPlay == 1)
	{
		playersToken = 'X';
	}
	else if (determineWhoWillPlay == 2)
	{
		playersToken = 'O';
	}
}

// PLAYER TURN LOGIC
void playerTurn()
{
	humanIsPlaying = true;

	playerMove = checkPlayerInput();

	caseTransfer = checkForOccupiedCase(playerMove);
	placeTokenOnBoard();
}


// COMPUTER TURN LOGIC
void cpuTurn()
{
	humanIsPlaying = false;

	cpuMove = checkCpuInput();

	caseTransfer = checkForOccupiedCase(cpuMove);
	placeTokenOnBoard();
}

// OUTPUT WHAT THE COMPUTER HAS PLAYED.
void cpuHasPlayed()
{
	cout << "        The *COMPUTER* played." << endl;
	cout << "     He placed a token on case * " << cpuMove << " * " << endl << endl;
}

// FILTER PLAYER INPUT (1 to 9)
int checkPlayerInput()
{
	int playerInput = 0;
	bool checkInput = true;

	cout << "     IT'S YOUR TURN TO PLAY NOW." << endl << "Please select an available case [1-9]: ";

	while (checkInput == true)
	{
		cin >> playerInput;
		cout << endl;

		if (playerInput >= 1 && playerInput <= 9)
		{
			checkInput = false;
		}
		else
		{
			cout << "Wrong input. Please try again: ";
		}
	}
	return playerInput;
}

// COMPUTER AUTOMATIC PLAY (RANDOMIZED)
int checkCpuInput()
{
	int cpuInput = 0;
	bool validCase = false;

	while (!validCase)
	{
		int randomizedCpuInput = 1 + rand() % 9;
		if (randomizedCpuInput == checkForOccupiedCase(randomizedCpuInput))
		{
			cpuInput = randomizedCpuInput;
			validCase = true;
		}
	}
	return cpuInput;
}

// DETERMINE IF A CASE HAS ALREADY BEEN PLAYED
int checkForOccupiedCase(int move)
{
	if (move == 1 && case_1 == '1')
	{
		return 1;
	}
	else if (move == 2 && case_2 == '2')
	{
		return 2;
	}
	else if (move == 3 && case_3 == '3')
	{
		return 3;
	}
	else if (move == 4 && case_4 == '4')
	{
		return 4;
	}
	else if (move == 5 && case_5 == '5')
	{
		return 5;
	}
	else if (move == 6 && case_6 == '6')
	{
		return 6;
	}
	else if (move == 7 && case_7 == '7')
	{
		return 7;
	}
	else if (move == 8 && case_8 == '8')
	{
		return 8;
	}
	else if (move == 9 && case_9 == '9')
	{
		return 9;
	}
	else if (humanIsPlaying == true)
	{
		drawTicTacToe();
		cout << "    ==================================    " << endl;
		cout << "\t\tWARNING" << endl;
		cout << ".:: This case has already been played. ::." << endl;
		cout << "\t***PLEASE PLAY AGAIN***" << endl;
		cout << "    ==================================    " << endl << endl;
		playerTurn();
		return 0;
	}
}

// PLACE TOKEN ON BOARD
void placeTokenOnBoard()
{
	if (caseTransfer == 1)
	{
		case_1 = playersToken;
	}
	else if (caseTransfer == 2)
	{
		case_2 = playersToken;
	}
	else if (caseTransfer == 3)
	{
		case_3 = playersToken;
	}
	else if (caseTransfer == 4)
	{
		case_4 = playersToken;
	}
	else if (caseTransfer == 5)
	{
		case_5 = playersToken;
	}
	else if (caseTransfer == 6)
	{
		case_6 = playersToken;
	}
	else if (caseTransfer == 7)
	{
		case_7 = playersToken;
	}
	else if (caseTransfer == 8)
	{
		case_8 = playersToken;
	}
	else if (caseTransfer == 9)
	{
		case_9 = playersToken;
	}
}

// CHECK FOR "TIC TAC TOE"
bool checkTicTacToe()
{
	if (case_1 != '1' && case_1 == case_2 && case_1 == case_3)
	{
		return true;
	}
	else if (case_4 != '4' && case_4 == case_5 && case_4 == case_6)
	{
		return true;
	}
	else if (case_7 != '7' && case_7 == case_8 && case_7 == case_9)
	{
		return true;
	}
	else if (case_1 != '1' && case_1 == case_4 && case_1 == case_7)
	{
		return true;
	}
	else if (case_2 != '2' && case_2 == case_5 && case_2 == case_8)
	{
		return true;
	}
	else if (case_3 != '3' && case_3 == case_6 && case_3 == case_9)
	{
		return true;
	}
	else if (case_1 != '1' && case_1 == case_5 && case_1 == case_9)
	{
		return true;
	}
	else if (case_3 != '3' && case_3 == case_5 && case_3 == case_7)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// WIN OR DRAW MESSAGES
void winOrDrawMessages()
{
	if (playerWin == true)
	{
		cout << "\t   ================" << endl << endl;
		cout << "\t   :: PLAYER WIN ::" << endl << endl;
		cout << "\t   ================" << endl << endl;
		endGame = true;
		playerWin = false;
	}
	else if (computerWin == true)
	{
		cout << "\t  ==================" << endl << endl;
		cout << "\t  :: COMPUTER WIN ::" << endl << endl;
		cout << "\t  ==================" << endl << endl;
		endGame = true;
		computerWin = false;
	}
	else if (playerWin == false && computerWin == false && case_1 != '1' && case_2 != '2' && case_3 != '3' && case_4 != '4' && case_5 != '5' && case_6 != '6' && case_7 != '7' && case_8 != '8' && case_9 != '9')
	{
		cout << "\t   =================" << endl << endl;
		cout << "\t   :: IT'S A DRAW ::" << endl << endl;
		cout << "\t   =================" << endl << endl;
		endGame = true;
	}
}

// PRESS ENTER TO CONTINUE
void pressEnterToContinue()
{
	cout << "    THE *COMPUTER* WILL PLAY NEXT." << endl;
	cout << "   PLEASE PRESS _ENTER_ TO CONTINUE.";
	cin.ignore();
	cin.get();
	cout << endl;
}

// START A NEW GAME (RESTARTS THE LOOP)
void startNewGame()
{
	cout << "Do you want to start a new game? (Press any key for YES or press 'Q' to QUIT)" << endl;
	cout << "Waiting for keyboard input: ";
	cin >> continueOrNot;
	cout << endl;

	if (continueOrNot != 'q' && continueOrNot != 'Q')
	{
		endGame = false;
		isFirstGame = false;
	}
}

// END OF PROGRAM
int endOfProgram()
{
	cout << "\t  ==================" << endl;
	cout << "\t  **END OF PROGRAM**" << endl;
	cout << "\t  ==================" << endl << endl;

	system("pause");

	return 0;
}