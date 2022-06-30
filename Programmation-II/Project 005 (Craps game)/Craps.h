// Crap games - Simulation
// Craps.h (Class definition | Function prototypes and data members)

#pragma once

enum class Status { CONTINUE, WON, LOST };

class Craps
{
public:

	Craps(); 

	void displayIntro();
	void userInput();
	void runSimulation();
	void firstRoll();
	void secondRoll();
	void displayWinOrLostMsg();
	void statisticsRetrieval();
	void firstRollStats();
	void secondRollStats();
	void thirdRollStats();
	void twentyRollStats();
	void fiftyRollStats();
	void allGamesStats();
	void overallStatistics();
	void averageLengthStats();
	double percentageCalc(int);
	unsigned int rollDice();
	unsigned int endOfProgram();

private:

	unsigned int nbrOfGames;
	unsigned int nbrOfRoll;
	unsigned int nbrOfRollTotal;
	unsigned int sumOfDice;
	unsigned int myPoint; // point if no win or loss on first roll

	// Statistics
	unsigned int gameWonFirstRoll;
	unsigned int gameLostFirstRoll;
	unsigned int gameWonSecondRoll;
	unsigned int gameLostSecondRoll;
	unsigned int gameWonThirdRoll;
	unsigned int gameLostThirdRoll;
	unsigned int gameWon20Roll;
	unsigned int gameLost20Roll;
	unsigned int gameWon50Roll;
	unsigned int gameLost50Roll;
	unsigned int gameWonTotal;
	unsigned int gameLostTotal;
};