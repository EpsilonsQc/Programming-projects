// Snake
// Vector2i.h (Class definition | Function prototypes and data members)

#pragma once

#include <iostream>

class Vector2i
{
public:
    Vector2i();
    Vector2i(int x, int y);
    bool Equals(const Vector2i&) const;
    int x;
    int y;
};