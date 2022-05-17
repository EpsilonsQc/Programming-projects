// Dice rolling - Simulates the rolling of two dice 
// Main.cpp (Main function | Program execution begins and ends there) 

#include "RollDice.h"
#include <iostream>

using namespace std;

void initRandom();

int main()
{
    initRandom();

    RollDice RollDiceObj;

    RollDiceObj.rollTwoDices();
    RollDiceObj.displayHeaders();
    RollDiceObj.printResultTabularFormat();
    RollDiceObj.endOfProgram();
}

void initRandom()
{
    srand(static_cast<unsigned int> (time(0)));
}
