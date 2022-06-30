// Snake
// Vector2d.cpp (Implementation file | Constructor and member functions definitions)

#include "Vector2d.h"

Vector2d::Vector2d() :
    x(0),
    y(0)
{
}

Vector2d::Vector2d(double x, double y) :
    x(x),
    y(y)
{
}

Vector2i Vector2d::ToVector2i() const
{
    return Vector2i((int)x, (int)y);
}