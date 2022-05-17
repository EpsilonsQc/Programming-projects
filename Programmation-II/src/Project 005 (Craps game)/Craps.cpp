// Crap games - Simulation
// RollDice.cpp (Implementation file | Constructor and member functions definitions)

#include "Craps.h"
#include <iostream>
#include <iomanip>

using namespace std;

Status gameStatus; // can be CONTINUE, WON or LOST

// Default constructor (CTOR) with no parameter
Craps::Craps() :
    nbrOfGames(0),
    nbrOfRoll(0),
    nbrOfRollTotal(0),
	sumOfDice(0),
	myPoint(0),

	// Statistics
    gameWonFirstRoll(0),
    gameLostFirstRoll(0),
    gameWonSecondRoll(0),
    gameLostSecondRoll(0),
    gameWonThirdRoll(0),
    gameLostThirdRoll(0),
    gameWon20Roll(0),
    gameLost20Roll(0),
    gameWon50Roll(0),
    gameLost50Roll(0),
    gameWonTotal(0),
    gameLostTotal(0)
{
    // Empty CTOR body
}

// Display intro headers
void Craps::displayIntro()
{
	cout << "=============================" << endl;
	cout << ".:: CRAPS GAME SIMULATION ::." << endl;
	cout << "=============================" << endl << endl;
}

// Ask for user input to determine number of games to simulate
void Craps::userInput()
{
	cout << "How many games of CRAPS do you want to simulate/play?" << endl;
	cout << "Please enter a number: ";
	cin >> nbrOfGames;
	cout << endl;
}

// Run the simulation of crap games
void Craps::runSimulation()
{
	for (int i = 0; i <= nbrOfGames; ++i)
	{
		firstRoll();
		secondRoll();
		displayWinOrLostMsg();
	}
}

// First roll
void Craps::firstRoll()
{
	nbrOfRoll = 0; // reset number of roll for each run of the simulation

	sumOfDice = rollDice(); // first roll of the dice
	++nbrOfRoll; // with reset
	++nbrOfRollTotal; // no reset (for statistics)

	// Determine game status and point (if needed) based on first roll
	switch (sumOfDice)
	{
		// Win with 7 or 11 on first roll
	case 7:
	case 11:
		gameStatus = Status::WON;
		++gameWonFirstRoll;;
		break;
		// Lost with 2, 3 or 12 on first roll
	case 2:
	case 3:
	case 12:
		gameStatus = Status::LOST;
		++gameLostFirstRoll;
		break;
		// Did not win or lose, so remember point
	default:
		gameStatus = Status::CONTINUE;
		myPoint = sumOfDice; // remember the point
		// cout << "Point is: " << myPoint << endl;
		break;
	}
}

// Second roll
void Craps::secondRoll()
{
	// While game is not complete (not WON or LOST)
	while (Status::CONTINUE == gameStatus)
	{
		sumOfDice = rollDice(); // roll dice again
		++nbrOfRoll;
		++nbrOfRollTotal; // no reset for stats

		// Determine game status
		if (sumOfDice == myPoint) // Win by making point
		{
			gameStatus = Status::WON;
			++gameWonSecondRoll;
			if (nbrOfRoll == 3)
			{
				++gameWonThirdRoll;
			}
			else if (nbrOfRoll == 20)
			{
				++gameWon20Roll;
			}
			else if (nbrOfRoll == 50)
			{
				++gameWon50Roll;
			}
		}
		else if (sumOfDice == 7) // Lose by rolling 7 before point
		{
			gameStatus = Status::LOST;
			++gameLostSecondRoll;
			if (nbrOfRoll == 3)
			{
				++gameLostThirdRoll;
			}
			else if (nbrOfRoll == 20)
			{
				++gameLost20Roll;
			}
			else if (nbrOfRoll == 50)
			{
				++gameLost50Roll;
			}
		}
	}
}

// Display win or lost message
void Craps::displayWinOrLostMsg()
{
	// Display won or lost message
	if (Status::WON == gameStatus)
	{
		// cout << "Player wins" << endl;
		++gameWonTotal;
	}
	else
	{
		// cout << "Player loses" << endl;
		++gameLostTotal;
	}
}

// Statistics of the simulation
void Craps::statisticsRetrieval()
{
	firstRollStats();
	secondRollStats();
	thirdRollStats();
	twentyRollStats();
	fiftyRollStats();
	allGamesStats();
	overallStatistics();
	averageLengthStats();
}

// First roll stats
void Craps::firstRollStats()
{
	int sumFirstRoll = gameWonFirstRoll + gameLostFirstRoll;
	double percentageWonFirstRoll = percentageCalc(gameWonFirstRoll);
	double percentageLostFirstRoll = percentageCalc(gameLostFirstRoll);

	int sumTotal1 = gameWonFirstRoll + gameLostFirstRoll;
	double percentageW1 = static_cast<double>(gameWonFirstRoll) * 100 / sumTotal1;
	double percentageL1 = static_cast<double>(gameLostFirstRoll) * 100 / sumTotal1;

	if (sumFirstRoll == 0)
	{
		gameWonFirstRoll = 0;
		percentageWonFirstRoll = 0;

		gameLostFirstRoll = 0;
		percentageLostFirstRoll = 0;

		percentageW1 = 0;
		percentageL1 = 0;
	}

	cout << "FIRST ROLL STATS" << endl;
	cout << "Games won on first roll:  " << gameWonFirstRoll << " (" << setprecision(4) << percentageWonFirstRoll << "%) (" << percentageW1 << "%)" << endl;
	cout << "Games lost on first roll: " << gameLostFirstRoll << " (" << setprecision(4) << percentageLostFirstRoll << "%) (" << percentageL1 << "%)" << endl;
}

// Second roll stats
void Craps::secondRollStats()
{
	int sumSecondRoll = gameWonSecondRoll + gameLostSecondRoll;
	double percentageWonSecondRoll = percentageCalc(gameWonSecondRoll);
	double percentageLostSecondRoll = percentageCalc(gameLostSecondRoll);

	int sumTotal2 = gameWonSecondRoll + gameLostSecondRoll;
	double percentageW2 = static_cast<double>(gameWonSecondRoll) * 100 / sumTotal2;
	double percentageL2 = static_cast<double>(gameLostSecondRoll) * 100 / sumTotal2;

	if (sumSecondRoll == 0)
	{
		gameWonSecondRoll = 0;
		percentageWonSecondRoll = 0;

		gameLostSecondRoll = 0;
		percentageLostSecondRoll = 0;

		percentageW2 = 0;
		percentageL2 = 0;
	}

	cout << endl << "SECOND ROLL STATS" << endl;
	cout << "Games won on second roll:  " << gameWonSecondRoll << " (" << setprecision(4) << percentageWonSecondRoll << "%) (" << percentageW2 << "%)" << endl;
	cout << "Games lost on second roll: " << gameLostSecondRoll << " (" << setprecision(4) << percentageLostSecondRoll << "%) (" << percentageL2 << "%)" << endl;
}

// Third roll stats
void Craps::thirdRollStats()
{
	int sumThirdRoll = gameWonThirdRoll + gameLostThirdRoll;
	double percentageWonThirdRoll = percentageCalc(gameWonThirdRoll);
	double percentageLostThirdRoll = percentageCalc(gameLostThirdRoll);

	int sumTotal3 = gameWonThirdRoll + gameLostThirdRoll;
	double percentageW3 = static_cast<double>(gameWonThirdRoll) * 100 / sumTotal3;
	double percentageL3 = static_cast<double>(gameLostThirdRoll) * 100 / sumTotal3;

	if (sumThirdRoll == 0)
	{
		gameWonThirdRoll = 0;
		percentageWonThirdRoll = 0;

		gameLostThirdRoll = 0;
		percentageLostThirdRoll = 0;

		percentageW3 = 0;
		percentageL3 = 0;
	}

	cout << endl << "THIRD ROLL STATS" << endl;
	cout << "Games won on third roll:  " << gameWonThirdRoll << " (" << setprecision(4) << percentageWonThirdRoll << "%) (" << percentageW3 << "%)" << endl;
	cout << "Games lost on third roll: " << gameLostThirdRoll << " (" << setprecision(4) << percentageLostThirdRoll << "%) (" << percentageL3 << "%)" << endl;
}

// Twenty roll stats
void Craps::twentyRollStats()
{
	int sum20Roll = gameWon20Roll + gameLost20Roll;
	double percentageWon20Roll = percentageCalc(gameWon20Roll);
	double percentageLost20Roll = percentageCalc(gameLost20Roll);

	int sumTotal20 = gameWon20Roll + gameLost20Roll;
	double percentageW20 = static_cast<double>(gameWon20Roll) * 100 / sumTotal20;
	double percentageL20 = static_cast<double>(gameLost20Roll) * 100 / sumTotal20;

	if (sum20Roll == 0)
	{
		gameWon20Roll = 0;
		percentageWon20Roll = 0;

		gameLost20Roll = 0;
		percentageLost20Roll = 0;

		percentageW20 = 0;
		percentageL20 = 0;
	}

	cout << endl << "TWENTY ROLL STATS" << endl;
	cout << "Games won on twenty roll:  " << gameWon20Roll << " (" << setprecision(4) << percentageWon20Roll << "%) (" << percentageW20 << "%)" << endl;
	cout << "Games lost on twenty roll: " << gameLost20Roll << " (" << setprecision(4) << percentageLost20Roll << "%) (" << percentageL20 << "%)" << endl;
}

// Fifty roll stats
void Craps::fiftyRollStats()
{
	int sum50Roll = gameWon50Roll + gameLost50Roll;
	double percentageWon50Roll = percentageCalc(gameWon50Roll);
	double percentageLost50Roll = percentageCalc(gameLost50Roll);

	int sumTotal50 = gameWon50Roll + gameLost50Roll;
	double percentageW50 = static_cast<double>(gameWon50Roll) * 100 / sumTotal50;
	double percentageL50 = static_cast<double>(gameLost50Roll) * 100 / sumTotal50;

	if (sum50Roll == 0)
	{
		gameWon50Roll = 0;
		percentageWon50Roll = 0;

		gameLost50Roll = 0;
		percentageLost50Roll = 0;

		percentageW50 = 0;
		percentageL50 = 0;
	}

	cout << endl << "FIFTY ROLL STATS" << endl;
	cout << "Games won on fifty roll:  " << gameWon50Roll << " (" << setprecision(4) << percentageWon50Roll << "%) (" << percentageW50 << "%)" << endl;
	cout << "Games lost on fifty roll: " << gameLost50Roll << " (" << setprecision(4) << percentageLost50Roll << "%) (" << percentageL50 << "%)" << endl;
}

// Statistics of all games ran during the simulation (defined by 'number of games')
void Craps::allGamesStats()
{
	// STATISTICS OF ALL GAMES RAN DURING THE SIMULATION
	double percentageWon = percentageCalc(gameWonTotal);
	double percentageLost = percentageCalc(gameLostTotal);

	cout << endl << "ALL GAMES STATS" << endl;
	cout << right << "Total of games won:  " << gameWonTotal << " (" << percentageWon << "%)" << endl;
	cout << right << "Total of games lost: " << gameLostTotal << " (" << percentageLost << "%)" << endl;
}

// Overall statistics
void Craps::overallStatistics()
{
	cout << endl << "OVERALL STATISTICS" << endl;
	cout << right << "Total number of games played: " << nbrOfGames << " games played" << endl;
	cout << right << "Total number of dice rolled:  " << nbrOfRollTotal << " dice rolled" << endl;
}

// Average length stats
void Craps::averageLengthStats()
{
	cout << endl << "AVERAGE LENGTH" << endl;
	double averageLength = static_cast<double>(nbrOfRollTotal) / static_cast<double>(nbrOfGames);
	cout << right << "Average length: " << setprecision(3) << averageLength << " rolls per game" << endl;
}

// Percentage calculator
double Craps::percentageCalc(int param)
{
	double percentage = static_cast<double>(param) * 100 / nbrOfGames;
	return percentage;
}

// Roll dice, calculate sum and display results
unsigned int Craps::rollDice()
{
	int die1{ 1 + rand() % 6 }; // 1st die roll
	int die2{ 1 + rand() % 6 }; // 2nd die roll
	int sum{ die1 + die2 }; // compute sum of die values

	// Display results of this roll
	// cout << "Player rolled: " << die1 << " + " << die2 << " = " << sum << endl;
	return sum;
}

// Display end of program
unsigned int Craps::endOfProgram()
{
	cout << endl;
	cout << "====================" << endl;
	cout << ":: END OF PROGRAM ::" << endl;
	cout << "====================" << endl << endl;

	system("pause");

	return 0;
}