//
//  TTTGame.h
//  TTT-22avril
//
//  Created by Simon Dansereau on 2022-04-25.
//

#ifndef TTTGame_h
#define TTTGame_h

#include "Defines.h"
#include <array>

class TTTGame
{
public:
    TTTGame();
    TTTGame(bool);
    void playGame();
    
private:
    bool determineWhoPlaysFirst();
    void displayWelcomeMessage();
    void printGrid();
    void playHuman(char);
    bool isValidSquare(int);
    void play(int, char);
    bool detectTTT(char, char, char);
    bool detectWinner(bool);
    void playAI(char);
    bool isGridFull();
    bool onPlayerTurn(char, bool);
    
private:
    std::array<char, NB_SLOTS> slots;
    bool isHumanFirst;
};

#endif /* TTTGame_h */
