#include "Vector2i.h"

#include <string>

Vector2i::Vector2i():
x(0),
y(0)
{
    
}

Vector2i::Vector2i(int x, int y):
x(x),
y(y)
{
    
}

bool Vector2i::Equals(const Vector2i& otherRef) const
{
    return x == otherRef.x && y == otherRef.y;
}

std::string Vector2i::ToString() const
{
    return "(" + std::to_string(x) + "," + std::to_string(y) + ")";
}