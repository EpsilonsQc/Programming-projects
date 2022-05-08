#include <iostream>
#include <time.h>
#include "TTTGame.h"

using namespace std;

void initRandom();
bool determineWhoPlaysFirst();
void promptPlayAgain(bool&);

int main()
{
    initRandom();
        
    //TTTGame game(determineWhoPlaysFirst());

    bool playAgain = true;
    do
    {
        TTTGame game(true);
        game.playGame();
        promptPlayAgain(playAgain);
    } while(playAgain);
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

void promptPlayAgain(bool &playAgain)
{
    char input = 'y';
    cout << "Play again ?" << endl;
    cin >> input;
    playAgain = input == 'y';
}
