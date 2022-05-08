//
//  TTTGame.h
//  TTT-22avril
//
//  Created by Simon Dansereau on 2022-04-25.
//

#ifndef TTTGame_h
#define TTTGame_h

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
    
    char slot1;
    char slot2;
    char slot3;
    char slot4;
    char slot5;
    char slot6;
    char slot7;
    char slot8;
    char slot9;
    bool isHumanFirst;
};

#endif /* TTTGame_h */
