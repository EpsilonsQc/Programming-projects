// Snake
// Vector2i.cpp (Implementation file | Constructor and member functions definitions)

#include "Vector2i.h"

Vector2i::Vector2i() :
    x(0),
    y(0)
{
}

Vector2i::Vector2i(int x, int y) :
    x(x),
    y(y)
{
}

bool Vector2i::Equals(const Vector2i& otherRef) const
{
    return x == otherRef.x && y == otherRef.y;
}