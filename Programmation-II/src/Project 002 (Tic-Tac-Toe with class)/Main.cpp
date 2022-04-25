// Tic-Tac-Toe with class
// Main.cpp (Main function | Program execution begins and ends there)

#include "TicTacToe.h"

using namespace std;

int main()
{
	TicTacToe TicTacToeObj;

	while (TicTacToeObj.getContinueOrNot() != 'Q' && TicTacToeObj.getContinueOrNot() != 'q');
	{
		TicTacToeObj.determineWhoPlayFirst();
		TicTacToeObj.resetTicTacToe();
		TicTacToeObj.displayTicTacToe();

		while (!TicTacToeObj.getEndGame())
		{	
			if (TicTacToeObj.getDetermineWhoWillPlay() == 1) // Player turn
			{
				TicTacToeObj.assignPlayersToken();
				TicTacToeObj.playerTurn();
				TicTacToeObj.displayTicTacToe();
				TicTacToeObj.checkWinCondition();
				TicTacToeObj.displaywinOrDrawMsg();
				TicTacToeObj.determineWhoPlayNext();
			}
			else if (TicTacToeObj.getDetermineWhoWillPlay() == 2) // Computer turn
			{
				TicTacToeObj.pressEnterToContinue();
				TicTacToeObj.assignPlayersToken();
				TicTacToeObj.cpuTurn();
				TicTacToeObj.displayTicTacToe();
				TicTacToeObj.cpuHasPlayed();
				TicTacToeObj.checkWinCondition();
				TicTacToeObj.displaywinOrDrawMsg();
				TicTacToeObj.determineWhoPlayNext();
			}
		}
		TicTacToeObj.startNewGame();
	} 
	TicTacToeObj.endOfProgram();
}