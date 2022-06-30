// Crap games - Simulation
// Main.cpp (Main function | Program execution begins and ends there) 

#include "Craps.h"
#include <iostream>

using namespace std;

void initRandom();

int main()
{
	initRandom();

	Craps CrapsObj;

	CrapsObj.displayIntro();
	CrapsObj.userInput();
	CrapsObj.runSimulation();
	CrapsObj.statisticsRetrieval();
	CrapsObj.endOfProgram();
}

void initRandom()
{
	srand(static_cast<unsigned int> (time(0)));
}