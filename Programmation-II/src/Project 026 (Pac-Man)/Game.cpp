#include "Game.h"

#include <fstream>
#include "GameWindow.h"

using namespace std;

Game::Game():
pacman(&maze),
maze(&pacman),
gameOver(false)
{
}

Game::~Game()
{
    //cout << "Game DTOR" << endl;
    maze.Unload();
}

void Game::OnTime(double time, double deltaTime)
{
    if(!gameOver)
    {
        maze.PhysicStep(time, deltaTime);
        CheckGameOverConditions();
    }
}

void Game::OnGameEvent(GAME_EVENT event)
{
    switch(event)
    {
        case SET_DIRECTION_EAST:
            pacman.SetDirection(EAST);
            break;
        case SET_DIRECTION_WEST:
            pacman.SetDirection(WEST);
            break;
        case SET_DIRECTION_NORTH:
            pacman.SetDirection(NORTH);
            break;
        case SET_DIRECTION_SOUTH:
            pacman.SetDirection(SOUTH);
            break;
        case DEBUG_MOVE_BY:
            pacman.MoveBy(1);
            break;
        default:
            std::cerr << "Invalid event=" << event << std::endl;
    }
}

void Game::Draw(const GameWindow& windowRef) const
{
    maze.Draw(windowRef);
    pacman.Draw(windowRef);
}

void Game::CheckGameOverConditions()
{
    gameOver = maze.GetNbRemainingDots() == 0 || pacman.IsDead();
    
    if(gameOver)
    {
        cout << "GAME OVER - YOU WIN!" << endl;
        return;
    }
}
