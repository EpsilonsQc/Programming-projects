#include "HUD.h"

#include <string>
#include <sstream>

#include "Game.h"
#include "Pacman.h"
#include "GameWindow.h"

using namespace std;

void HUD::Draw(const GameWindow& windowRef) const
{
    int nbLifes = 99;
    int score = 666;
    int highscore = 999;
    
    stringstream buffer;
    buffer << "SCORE:" << score << " HIGH SCORE:" << highscore << " LIFE:" << nbLifes;
    
    int x, y, w, h;
    
    x = 0;
    y = 0;

    windowRef.DrawText(buffer.str(), x, y, Color::Black);
    
    if(game->IsGameOver())
    {
        const string text = "GAME OVER";
        
        windowRef.MeasureText(text, w, h);
        
        x =  (WINDOW_SIZE - w) / 2;
        y =  (WINDOW_SIZE - h) / 2;

        windowRef.DrawText(text, x, y, Color::Red);
    }
}
