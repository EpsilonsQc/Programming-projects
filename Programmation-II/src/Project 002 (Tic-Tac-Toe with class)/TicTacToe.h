// Tic-Tac-Toe with class
// TicTacToe.h (Class definition | Function prototypes and data members)

class TicTacToe
{
public :

	TicTacToe();

	void determineWhoPlayFirst();
	void determineWhoPlayNext();
	void verifyIsFirstGame();
	void resetTicTacToe();
	void displayTicTacToe();
	void playerTurn();
	void cpuTurn();
	void cpuHasPlayed();
	void assignPlayersToken();
	void placeTokenOnBoard();
	void checkWinCondition();
	void displaywinOrDrawMsg();
	void pressEnterToContinue();
	void startNewGame();
	bool checkForTicTacToe();
	bool getEndGame();
	char getContinueOrNot();
	int getDetermineWhoWillPlay();
	int checkPlayerInput();
	int checkCpuInput();
	int endOfProgram();
	int checkForOccupiedCase(int);

private:

	bool humanIsPlaying;
	bool endGame;
	bool isFirstGame;
	bool playerWin;
	bool computerWin;
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
	int determineWhoWillPlay;
	int playerMove;
	int cpuMove;
};
