// Snake
// Vector2d.h (Class definition | Function prototypes and data members)

#pragma once

#include <iostream>

#include "Vector2i.h"

class Vector2d
{
public:
    Vector2d();
    Vector2d(double x, double y);
    Vector2i ToVector2i() const;
    double x;
    double y;
};