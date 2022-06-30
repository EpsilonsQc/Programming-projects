// Snake
// Game.h (Class definition | Function prototypes and data members)

#pragma once

#include <iostream>

#include "Defines.h"
#include "Snake.h"
#include "Apple.h"

class SnakeWindow;

class Game
{
public:
    Game();
    void OnTime(double time, double deltaTime);
    void OnGameEvent(GAME_EVENT event);
    void Draw(const SnakeWindow&) const;
    inline Vector2i GetGridSize() const { return gridSize; };
private:
    void DrawChessGrid(const SnakeWindow& windowRef) const; // Used for debug
    void CheckGameOverConditions();
    bool IsSnakeOutOfBounds() const;
    bool IsSnakeRollOver() const;
    bool DetectCollision(const Snake& s, const Apple& a) const;
    void FindPositionForApple();

private:
    Vector2i gridSize;
    Snake snake;
    Apple apple;
    bool gameOver;
};