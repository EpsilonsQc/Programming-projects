#ifndef __PACMAN__Game__
#define __PACMAN__Game__

#include <iostream>

#include "Defines.h"
#include "Maze.h"
#include "Pacman.h"

class GameWindow;

class Game
{
public:
    Game();
    ~Game();
    void OnTime(double time, double deltaTime);
    void OnGameEvent(GAME_EVENT event);
    void Draw(const GameWindow&) const;
    inline Vector2i GetGridSize() const { return maze.GetSize(); }
    inline const Pacman* GetPacman() const { return &pacman; }
    inline bool IsGameOver() const { return gameOver; }
    
private:
    void CheckGameOverConditions();

private:
    Pacman pacman;
    Maze maze;
    bool gameOver;
};

#endif /* defined(__PACMAN__Game__) */
