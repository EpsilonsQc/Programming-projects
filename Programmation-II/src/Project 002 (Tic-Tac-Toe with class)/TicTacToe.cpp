// Tic-Tac-Toe with class
// TicTacToe.cpp (Implementation file | Constructor and member functions definitions)

#include <iostream>
#include "TicTacToe.h"

using namespace std;

// Constructor (CTOR)
TicTacToe::TicTacToe() :
	endGame(false),
	playerWin(false),
	computerWin(false),
	humanIsPlaying(true),
	isFirstGame(true),
	case_1('1'),
	case_2('2'),
	case_3('3'),
	case_4('4'),
	case_5('5'),
	case_6('6'),
	case_7('7'),
	case_8('8'),
	case_9('9'),
	playersToken(' '),
	continueOrNot(' '),
	determineWhoWillPlay(0),
	caseTransfer(0),
	playerMove(0),
	cpuMove(0)
{
	// Empty constructor body
}

// Determine who will play first (randomized)
void TicTacToe::determineWhoPlayFirst()
{
	srand(static_cast<unsigned int> (time(0)));
	determineWhoWillPlay = 1 + rand() % 2;
}

// Output that verify if it's the first or a subsequent matches
void TicTacToe::verifyIsFirstGame()
{
	if (!isFirstGame)
	{
		cout << "   =========================================" << endl;
		cout << "   .:: START OF A NEW GAME [FRESH BOARD] ::." << endl;
		cout << "   =========================================" << endl << endl;
		isFirstGame = true;
	}
}

// Display the game board
void TicTacToe::drawTicTacToe()
{
	TicTacToe::verifyIsFirstGame();

	cout << "\t    **TIC-TAC-TOE**" << endl;
	cout << "\t     +---+---+---+" << endl;
	cout << "\t     | " << case_1 << " | " << case_2 << " | " << case_3 << " | " << endl;
	cout << "\t     +---+---+---+" << endl;
	cout << "\t     | " << case_4 << " | " << case_5 << " | " << case_6 << " | " << endl;
	cout << "\t     +---+---+---+" << endl;
	cout << "\t     | " << case_7 << " | " << case_8 << " | " << case_9 << " | " << endl;
	cout << "\t     +---+---+---+" << endl << endl;
}

// Reset the game board for a fresh game start
void TicTacToe::resetTicTacToe()
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

// Assign players token according to who play first
void TicTacToe::assignPlayersToken()
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

// Player turn logic
void TicTacToe::playerTurn()
{
	humanIsPlaying = true;

	playerMove = checkPlayerInput();

	caseTransfer = checkForOccupiedCase(playerMove);
	placeTokenOnBoard();
}


// Computer turn logic
void TicTacToe::cpuTurn()
{
	humanIsPlaying = false;

	cpuMove = checkCpuInput();

	caseTransfer = checkForOccupiedCase(cpuMove);
	placeTokenOnBoard();
}

// Output what the computer has played.
void TicTacToe::cpuHasPlayed()
{
	cout << "        The *COMPUTER* played." << endl;
	cout << "     He placed a token on case * " << cpuMove << " * " << endl << endl;
}

// Filter player input (1 to 9)
int TicTacToe::checkPlayerInput()
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

// Computer automatic play (randomized)
int TicTacToe::checkCpuInput()
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

// Determine if a case has already been played
int TicTacToe::checkForOccupiedCase(int move)
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

// Place token on board
void TicTacToe::placeTokenOnBoard()
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

// Check for "Tic-TacToe"
bool TicTacToe::checkTicTacToe()
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

// Display win or draw messages
void TicTacToe::winOrDrawMessages()
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

// Prompt the user to press enter to continue
void TicTacToe::pressEnterToContinue()
{
	cout << "    THE *COMPUTER* WILL PLAY NEXT." << endl;
	cout << "   PLEASE PRESS _ENTER_ TO CONTINUE.";
	cin.ignore();
	cin.get();
	cout << endl;
}

// Start a new game (restarts the loop)
void TicTacToe::startNewGame()
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

// End of program
int TicTacToe::endOfProgram()
{
	cout << "\t  ==================" << endl;
	cout << "\t  **END OF PROGRAM**" << endl;
	cout << "\t  ==================" << endl << endl;

	system("pause");

	return 0;
}