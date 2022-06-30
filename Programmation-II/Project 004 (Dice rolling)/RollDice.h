// Dice rolling - Simulates the rolling of two dice
// RollDice.h (Class definition | Function prototypes and data members)

#pragma once

#include <array>

class RollDice
{
public:

	RollDice();

	void rollTwoDices();
	int rollDice();
	void calculateSum();
	void displayHeaders();
	void printResultTabularFormat();
	int endOfProgram();

private:

	int dice_1;
	int dice_2;
	int nbrDiceRolls;
	std::array<int, 11> statsTotal;
};