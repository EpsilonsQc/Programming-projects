// Tic-Tac-Toe with class
// Main.cpp (Main function | Program execution begins and ends there)

#include "TicTacToe.h"

using namespace std;

int main()
{
	// Create an object of type TicTacToe
	TicTacToe TicTacToeObject;

	do
	{
		TicTacToeObject.determineWhoPlayFirst();
		TicTacToeObject.resetTicTacToe();
		TicTacToeObject.drawTicTacToe();

		while (TicTacToeObject.endGame == false)
		{
			// Player turn
			if (TicTacToeObject.determineWhoWillPlay == 1) 
			{
				TicTacToeObject.assignPlayersToken();
				TicTacToeObject.playerTurn();
				TicTacToeObject.drawTicTacToe();
				TicTacToeObject.playerWin = TicTacToeObject.checkTicTacToe();
				TicTacToeObject.winOrDrawMessages();
				TicTacToeObject.determineWhoWillPlay = 2;
			}
			// Computer turn
			else if (TicTacToeObject.determineWhoWillPlay == 2)
			{
				TicTacToeObject.pressEnterToContinue();
				TicTacToeObject.assignPlayersToken();
				TicTacToeObject.cpuTurn();
				TicTacToeObject.drawTicTacToe();
				TicTacToeObject.cpuHasPlayed();
				TicTacToeObject.computerWin = TicTacToeObject.checkTicTacToe();
				TicTacToeObject.winOrDrawMessages();
				TicTacToeObject.determineWhoWillPlay = 1;
			}
		}

		TicTacToeObject.startNewGame();

	} while (TicTacToeObject.continueOrNot != 'q' && TicTacToeObject.continueOrNot != 'Q');

	TicTacToeObject.endOfProgram();
}