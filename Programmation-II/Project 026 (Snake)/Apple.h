// Snake
// Apple.h (Class definition | Function prototypes and data members)

#pragma once

#include <iostream>

#include "Vector2i.h"

class SnakeWindow;

class Apple
{
public:
    Apple() {}

    inline Vector2i GetPosition() const { return position; }
    inline void SetPosition(Vector2i value) { position = value; }

    void Draw(const SnakeWindow& windowRef) const;

private:
    Vector2i position;
};