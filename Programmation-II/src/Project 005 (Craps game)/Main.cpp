// Crap games - Simulation
// Main.cpp (Main function | Program execution begins and ends there) 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

unsigned int rollDice();
double percentageCalc(int); // Not used for now

unsigned int nbrOfGames = 10000;

int main()
{
	enum class Status {CONTINUE, WON, LOST};

	srand(static_cast<unsigned int>(time(0)));

	unsigned int nbrOfRoll = 0;

	unsigned int gameWonFirstRoll = 0;
	unsigned int gameLostFirstRoll = 0;

	unsigned int gamesWon = 0;
	unsigned int gamesLost = 0;

	unsigned int myPoint = 0; // point if no win or loss on first roll
	Status gameStatus; // can be CONTINUE, WON or LOST

	for (int i = 0; i < nbrOfGames; ++i)
	{
		unsigned int sumOfDice = rollDice(); // first roll of the dice

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

		// While game is not complete (not WON or LOST)
		while (Status::CONTINUE == gameStatus)
		{
			sumOfDice = rollDice(); // roll dice again

			// Determine game status
			if (sumOfDice == myPoint) // Win by making point
			{
				gameStatus = Status::WON;
			}
			else if (sumOfDice == 7) // Lose by rolling 7 before point
			{
				gameStatus = Status::LOST;
			}
		}

		// Display won or lost message
		if (Status::WON == gameStatus)
		{
			// cout << "Player wins" << endl;
			++gamesWon;
		}
		else
		{
			// cout << "Player loses" << endl;
			++gamesLost;
		}
	}

	int sum = gameWonFirstRoll + gameLostFirstRoll;
	double percentageWonFirstRoll = static_cast<double>(gameWonFirstRoll) * 100 / sum;
	double percentageLostFirstRoll = static_cast<double>(gameLostFirstRoll) * 100 / sum;

	cout << "Games won on first roll: " << gameWonFirstRoll << setprecision(4) << " (" << percentageWonFirstRoll << "%)" << endl;
	cout << "Game lost on first roll: " << gameLostFirstRoll << setprecision(4) << " (" << percentageLostFirstRoll << "%)" << endl;

	double percentageWon = static_cast<double>(gamesWon) * 100 / nbrOfGames;
	double percentageLost = static_cast<double>(gamesLost) * 100 / nbrOfGames;

	cout << right << "Total of games won:  " << gamesWon << " (" << percentageWon <<  "%)" << endl;
	cout << right << "Total of games lost: " << gamesLost << " (" << percentageLost << "%)" << endl;

	cout << endl;
	cout << "====================" << endl;
	cout << ":: END OF PROGRAM ::" << endl;
	cout << "====================" << endl << endl;

	system("pause");

	return 0;
}

// Roll dice, calculate sum and display results
unsigned int rollDice()
{
	int die1{ 1 + rand() % 6 }; // 1st die roll
	int die2{ 1 + rand() % 6 }; // 2nd die roll
	int sum{ die1 + die2 }; // compute sum of die values

	// Display results of this roll
	// cout << "Player rolled: " << die1 << " + " << die2 << " = " << sum << endl;
	return sum;
}

// Percentage calculator
double percentageCalc(int param)
{
	double percentage = static_cast<double>(param) * 100 / nbrOfGames;
	return percentage;
}

