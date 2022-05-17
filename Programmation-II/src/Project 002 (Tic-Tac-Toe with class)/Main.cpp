// Tic-Tac-Toe with class 
// Main.cpp (Main function | Program execution begins and ends there)

#include "TicTacToe.h"

using namespace std;

int main()
{
	TicTacToe TicTacToeObj;

	do 
	{
		TicTacToeObj.randomizeWhoPlayFirst();
		TicTacToeObj.whoPlayedFirst();
		TicTacToeObj.resetTicTacToe();
		TicTacToeObj.displayTicTacToe();

		while (!TicTacToeObj.gameOver())
		{
			if (TicTacToeObj.determineWhoWillPlay(playerType::human))
			{
				TicTacToeObj.assignTokenType();
				TicTacToeObj.playerTurn();
				TicTacToeObj.placeTokenOnBoard();
				TicTacToeObj.displayTicTacToe();
				TicTacToeObj.checkWinCondition();
				TicTacToeObj.displayWinOrDrawMsg();
				TicTacToeObj.determineWhoPlayNext();
			}
			else if (TicTacToeObj.determineWhoWillPlay(playerType::computer))
			{
				TicTacToeObj.assignTokenType();
				TicTacToeObj.cpuTurn();
				TicTacToeObj.placeTokenOnBoard();
				TicTacToeObj.displayTicTacToe();
				TicTacToeObj.displayCpuHasPlayed();
				TicTacToeObj.checkWinCondition();
				TicTacToeObj.displayWinOrDrawMsg();
				TicTacToeObj.determineWhoPlayNext();
			}
		}

		TicTacToeObj.promptStartNewGame();

	} while (TicTacToeObj.continueToPlay());

	TicTacToeObj.endOfProgram();
}
