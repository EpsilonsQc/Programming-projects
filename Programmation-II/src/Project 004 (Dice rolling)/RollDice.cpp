// Dice rolling - Simulates the rolling of two dice
// RoleDice.cpp (Implementation file | Constructor and member functions definitions)

#include "rollDice.h"
#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

// Default constructor (CTOR) with no parameter
RollDice::RollDice() :
    dice_1(0),
    dice_2(0),
    nbrDiceRolls(36000000),
    statsTotal{ 0 }
{
    // Empty CTOR body
}

// Roll two dices for X amount of times
void RollDice::rollTwoDices()
{
    for (int i = 0; i <= nbrDiceRolls; ++i)
    {
        dice_1 = rollDice();
        dice_2 = rollDice();
        calculateSum();
    }
}

// Roll a 6 sided dice and return the result
int RollDice::rollDice()
{
    int dice = 1 + rand() % 6;

    return dice;
}

// Calculate the sum of a roll of two dice
void RollDice::calculateSum()
{
    int sum = dice_1 + dice_2;
    statsTotal[sum - 2]++;
}

// Display a headers
void RollDice::displayHeaders()
{
    cout << ":: NUMBER OF OCCURENCES FOR THE SUM OF TWO DICES ROLLED " << nbrDiceRolls << " TIMES ::" << endl << endl;
    cout << right << setw(3) << "SUM" << "  " << "OCCURENCES" << "  " << "PERCENTAGE" << endl;
}

// Print the result of the rolled dice in a tabular format
void RollDice::printResultTabularFormat()
{
    for (int i = 0; i < 11; ++i)
    {
        double percentage = static_cast<double>(statsTotal[i]) * 100 / nbrDiceRolls;
        cout << right << setw(3) << i + 2 << "  " << right << setw(10) << statsTotal[i] << setw(3) << setprecision(3) << " (" << percentage << "%)" << endl;
    }
}


// Display end of program
int RollDice::endOfProgram()
{
    {
        cout << endl;
        cout << "====================" << endl;
        cout << ":: END OF PROGRAM ::" << endl;
        cout << "====================" << endl << endl;

        system("pause");

        return 0;
    }
}