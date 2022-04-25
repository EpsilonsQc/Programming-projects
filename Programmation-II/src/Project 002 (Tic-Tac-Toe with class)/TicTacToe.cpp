// Tic-Tac-Toe with class
// TicTacToe.cpp (Implementation file | Constructor and member functions definitions)

#include <iostream>
#include "TicTacToe.h"

using namespace std;

// Default constructor (CTOR) with no parameter
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
	srand(static_cast<unsigned int> (time(0)));
}

// Determine who will play first for a new game (randomized)
void TicTacToe::determineWhoPlayFirst()
{
	determineWhoWillPlay = 1 + rand() % 2;
}

// Determine who will play after a turn
void TicTacToe::determineWhoPlayNext()
{
	if (humanIsPlaying)
	{
		determineWhoWillPlay = 2;
	}
	else if (!humanIsPlaying)
	{
		determineWhoWillPlay = 1;
	}
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
	cout << "The *COMPUTER* played." << endl;
	cout << "He placed a token on case * " << cpuMove << " * " << endl << endl;
}

// Filter player input (1 to 9)
int TicTacToe::checkPlayerInput()
{
	int playerInput = 0;
	bool checkInput = true;

	cout << "IT'S YOUR TURN TO PLAY NOW." << endl << "Please select an available case [1-9]: ";

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
		displayTicTacToe();
		cout << "==================================================" << endl;
		cout << ":: WARNING - This case has already been played. ::" << endl;
		cout << "             ***PLEASE PLAY AGAIN***              " << endl;
		cout << "==================================================" << endl << endl;
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
bool TicTacToe::checkForTicTacToe()
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

// Check win condition for player and CPU
void TicTacToe::checkWinCondition()
{
	if (determineWhoWillPlay == 1)
	{
		playerWin = checkForTicTacToe();
	}
	else if (determineWhoWillPlay == 2)
	{
		computerWin = checkForTicTacToe();
	}
}

// Return endGame
bool TicTacToe::getEndGame()
{
	return endGame;
}

// Return continueOrNot
char TicTacToe::getContinueOrNot()
{
	return continueOrNot;
}

// Return determineWhoWillPlay 
int TicTacToe::getDetermineWhoWillPlay()
{
	return determineWhoWillPlay;
}

// Display the game board
void TicTacToe::displayTicTacToe()
{
	TicTacToe::verifyIsFirstGame();

	cout << "TIC-TAC-TOE" << endl << endl;
	cout << " " << case_1 << " | " << case_2 << " | " << case_3 << endl;
	cout << "---+---+---" << endl;
	cout << " " << case_4 << " | " << case_5 << " | " << case_6 << endl;
	cout << "---+---+---" << endl;
	cout << " " << case_7 << " | " << case_8 << " | " << case_9 << endl << endl;
}

// Verify if it's the first or a subsequent matches and display the new game headers
void TicTacToe::verifyIsFirstGame()
{
	if (!isFirstGame)
	{
		cout << "=======================================" << endl;
		cout << ":: START OF A NEW GAME [FRESH BOARD] ::" << endl;
		cout << "=======================================" << endl << endl;
		isFirstGame = true;
	}
}

// Display win or draw messages
void TicTacToe::displaywinOrDrawMsg()
{
	if (playerWin == true)
	{
		cout << "================" << endl;
		cout << ":: PLAYER WIN ::" << endl;
		cout << "================" << endl << endl;
		endGame = true;
		playerWin = false;
	}
	else if (computerWin == true)
	{
		cout << "==================" << endl;
		cout << ":: COMPUTER WIN ::" << endl;
		cout << "==================" << endl << endl;
		endGame = true;
		computerWin = false;
	}
	else if (playerWin == false && computerWin == false && case_1 != '1' && case_2 != '2' && case_3 != '3' && case_4 != '4' && case_5 != '5' && case_6 != '6' && case_7 != '7' && case_8 != '8' && case_9 != '9')
	{
		cout << "=================" << endl;
		cout << ":: IT'S A DRAW ::" << endl;
		cout << "=================" << endl << endl;
		endGame = true;
	}
}

// Display end of program
int TicTacToe::endOfProgram()
{
	cout << "====================" << endl;
	cout << ":: END OF PROGRAM ::" << endl;
	cout << "====================" << endl << endl;

	system("pause");

	return 0;
}

// Prompt the user to press enter to continue
void TicTacToe::pressEnterToContinue()
{
	cout << "THE *COMPUTER* WILL PLAY NEXT.   " << endl;
	cout << "PLEASE PRESS _ENTER_ TO CONTINUE.";
	cin.ignore();
	cin.get();
	cout << endl;
}

// Prompt the user to start a new game (restarts the loop)
void TicTacToe::startNewGame()
{
	cout << "Do you want to start a new game? (Press any key to CONTINUE | Press 'Q' to QUIT)" << endl;
	cout << "Waiting for keyboard input: ";
	cin >> continueOrNot;
	cout << endl;

	if (continueOrNot != 'q' && continueOrNot != 'Q')
	{
		endGame = false;
		isFirstGame = false;
	}
}