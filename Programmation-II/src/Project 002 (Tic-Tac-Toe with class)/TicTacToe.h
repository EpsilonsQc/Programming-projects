// Tic-Tac-Toe with class
// TicTacToe.h (Class definition | Function prototypes and data members)

class TicTacToe
{
public :

	TicTacToe();

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

	// Public data members
	bool endGame;
	bool playerWin;
	bool computerWin;
	char continueOrNot;
	int determineWhoWillPlay;

private:

	// Private data members
	bool humanIsPlaying;
	bool isFirstGame;
	char case_1;
	char case_2;
	char case_3;
	char case_4;
	char case_5;
	char case_6;
	char case_7;
	char case_8;
	char case_9;
	char playersToken;
	int caseTransfer;
	int playerMove;
	int cpuMove;
};