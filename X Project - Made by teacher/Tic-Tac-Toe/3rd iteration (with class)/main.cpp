#include <iostream>
#include <time.h>
#include "TTTGame.h"

using namespace std;

void initRandom();
bool determineWhoPlaysFirst();

int main()
{
    initRandom();
        
    //TTTGame game(determineWhoPlaysFirst());
    
    char playAgain = 'y';
    
    do
    {
        TTTGame game(true);
        game.playGame();
        
        cout << "Play again ?" << endl;
        cin >> playAgain;
        
    } while(playAgain == 'y');
}

void initRandom()
{
    srand(static_cast<unsigned>(time(0)));
}

bool determineWhoPlaysFirst()
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
