//
//  TTTGame.cpp
//  TTT-22avril
//
//  Created by Simon Dansereau on 2022-04-25.
//

#include <iostream>
#include "TTTGame.h"

using namespace std;

TTTGame::TTTGame(bool isHumanFirst) :
    slots{'1', '2', '3', '4', '5', '6', '7', '8', '9'},
    isHumanFirst(isHumanFirst)
{
    displayWelcomeMessage();
    printGrid();
}

TTTGame::TTTGame() :
    slots{'1', '2', '3', '4', '5', '6', '7', '8', '9'},
    isHumanFirst(determineWhoPlaysFirst())
{
    displayWelcomeMessage();
    printGrid();
}

void TTTGame::displayWelcomeMessage()
{
    cout << "Welcome to TTT" << endl;
}

void TTTGame::printGrid()
{
    cout << " " << slots[0] << " | " << slots[1] << " | " << slots[2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << slots[3] << " | " << slots[4] << " | " << slots[5] << endl;
    cout << "---|---|---" << endl;
    cout << " " << slots[6] << " | " << slots[7] << " | " << slots[8] << endl << endl;
}

bool TTTGame::determineWhoPlaysFirst()
{
    bool isHumanFirst = rand() % 2 == 0;
    
    if(isHumanFirst)
    {
        cout << "You play first." << endl;
    }
    else
    {
        cout << "Computer plays first." << endl;
    }
    
    return isHumanFirst;
}

bool TTTGame::onPlayerTurn(char mark, bool isHuman)
{
    if(isHuman)
    {
        playHuman(mark);
    }
    else
    {
        playAI(mark);
    }
    
    printGrid();
    
    return detectWinner(isHuman);
}

void TTTGame::playHuman(char mark)
{
    int square = 0;
    
    bool isValid = false;
    while(!isValid)
    {
        cout << "Select an empty square:" << endl;
        cin >> square;
        isValid = isValidSquare(square);
    }
    
    play(square, mark);
}

void TTTGame::playAI(char mark)
{
    bool isValid = false;
    int square = rand() % NB_SLOTS + 1;
    while(!isValid)
    {
        square++;
        if(square > NB_SLOTS)
        {
            square = 1;
        }
        isValid = isValidSquare(square);
    }

    play(square, mark);
}

bool TTTGame::isValidSquare(int square)
{
    return slots[square - 1] == '1' + square - 1;
}

void TTTGame::play(int square, char mark)
{
    slots[square - 1] = mark;
}

bool TTTGame::detectTTT(char c1, char c2, char c3)
{
    return c1 == c2 && c2 == c3;
}

bool TTTGame::detectWinner(bool isHuman)
{
    bool isGameOver = false;
    
    isGameOver |= detectTTT(slots[0], slots[1], slots[2]);
    isGameOver |= detectTTT(slots[3], slots[4], slots[5]);
    isGameOver |= detectTTT(slots[6], slots[7], slots[8]);
    isGameOver |= detectTTT(slots[0], slots[3], slots[6]);
    isGameOver |= detectTTT(slots[1], slots[4], slots[7]);
    isGameOver |= detectTTT(slots[2], slots[5], slots[8]);
    isGameOver |= detectTTT(slots[0], slots[4], slots[8]);
    isGameOver |= detectTTT(slots[2], slots[4], slots[6]);
    
    if(isGameOver)
    {
        if(isHuman)
        {
            cout << "You win" << endl;
        }
        else
        {
            cout << "You lose" << endl;
        }
    }
    else if (isGridFull())
    {
        cout << "Tie game!" << endl;
        isGameOver = true;
    }

    return isGameOver;
}

bool TTTGame::isGridFull()
{
    for(int i = 1; i <= NB_SLOTS; i++)
    {
        if(isValidSquare(i))
        {
            return false;
        }
    }
    return true;
}

void TTTGame::playGame()
{
    bool isHuman = isHumanFirst;
    char mark = X;
    
    bool isGameOver = false;
    
    while(!isGameOver)
    {
        isGameOver = onPlayerTurn(mark, isHuman);
        
        mark = (mark == X) ? O : X;//toggle mark by ref
        
        isHuman = !isHuman;
    }
}

