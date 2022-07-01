// Snake
// Snake.h (Class definition | Function prototypes and data members)

#pragma once

#include <iostream>
#include <deque>

#include "Vector2d.h"
#include "Defines.h"

class SnakeWindow;

class Snake
{
public:
    Snake(Vector2d position);
    void Move(double deltaTime);
    void MoveBy(double deltaPosition);
    void Draw(const SnakeWindow& windowRef) const;
    Vector2d GetPosition() const;
    void SetDirection(DIRECTION value);
    void IncreaseLengthBy1();
    bool IsRollOver() const;
    bool IsOnSnake(Vector2i pos) const;

private:
    void MoveBodyParts();

private:
    DIRECTION direction;
    Vector2d headPos; // double
    Vector2i headLastPos; // int
    std::deque<Vector2i> bodyParts; // int
    size_t lastBodyElement;
    float movementSpeed;
};