// Snake
// Apple.cpp (Implementation file | Constructor and member functions definitions)

#include "Apple.h"
#include "SnakeWindow.h"

void Apple::Draw(const SnakeWindow& windowRef) const
{
    windowRef.DrawTileAt(position, 255, 0, 0);
}