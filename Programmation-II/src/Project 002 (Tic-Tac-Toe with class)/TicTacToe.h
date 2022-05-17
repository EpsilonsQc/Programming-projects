// Tic-Tac-Toe with class
// TicTacToe.h (Class definition | Function prototypes and data members)

#pragma once

enum class playerType { notDetermined, human, computer };

class TicTacToe
{
public:

	TicTacToe();

	void randomizeWhoPlayFirst();
	void determineWhoPlayNext();
	void verifyIsFirstGame();
	void resetTicTacToe();
	void displayTicTacToe();
	void playerTurn();
	void cpuTurn();
	void displayCpuHasPlayed();
	void assignTokenType();
	void placeTokenOnBoard();
	void checkWinCondition();
	void displayWinOrDrawMsg();
	void pressEnterToContinue();
	void whoPlayedFirst();
	void promptStartNewGame();
	bool checkForTicTacToe();
	bool gameOver();
	bool continueToPlay();
	bool determineWhoWillPlay(playerType);
	char getContinueOrNot();
	int checkPlayerInput();
	int checkCpuInput();
	int endOfProgram();
	int checkForOccupiedCase(int);

private:

	playerType selectPlayer;
	bool humanIsPlaying;
	bool theGameIsOver;
	bool isFirstGame;
	bool playerWin;
	bool computerWin;
	bool startNewGame;
	bool humanPlayedFirst;
	char case_1;
	char case_2;
	char case_3;
	char case_4;
	char case_5;
	char case_6;
	char case_7;
	char case_8;
	char case_9;
	char continueOrNot;
	char playersToken;
	int caseTransfer;
	int playerMove;
	int cpuMove;
};