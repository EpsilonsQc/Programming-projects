// Snake
// Snake.cpp (Implementation file | Constructor and member functions definitions)

#include "Snake.h"
#include "SnakeWindow.h"

Snake::Snake(Vector2d position) :
direction(NORTH), // default direction
headPos(position),
headLastPos(position.ToVector2i()),
lastBodyElement(0),
movementSpeed(5) // 3 = slow, 5 = normal, 7 = fast, 9 = expert, 11 = godspeed
{
    bodyParts.push_front(headPos.ToVector2i());
}

void Snake::Move(double deltaTime)
{
    double deltaPosition = movementSpeed * deltaTime;

    MoveBy(deltaPosition);
}

void Snake::MoveBy(double deltaPosition)
{
    switch (direction)
    {
    case NORTH: headPos.y -= deltaPosition; break;
    case SOUTH: headPos.y += deltaPosition; break;
    case WEST: headPos.x -= deltaPosition; break;
    case EAST: headPos.x += deltaPosition; break;
    }

    MoveBodyParts();
}

void Snake::MoveBodyParts()
{
    if (!bodyParts[0].Equals(headPos.ToVector2i()))
    {
        if (bodyParts.size() == 1)
        {
            headLastPos = bodyParts[0];
        }
        else
        {
            lastBodyElement = bodyParts.size() - 1;

            for (size_t i = lastBodyElement; i > 0; i--)
            {
                bodyParts[i] = bodyParts[i - 1];
            }

            headLastPos = bodyParts[lastBodyElement];
        }
    }

    bodyParts[0] = headPos.ToVector2i();
}

void Snake::Draw(const SnakeWindow& windowRef) const
{
    windowRef.DrawTileAt(headPos.ToVector2i(), 100, 100, 100); // draw "dark-grey" head

    for (size_t i = 1; i < bodyParts.size(); i++)
    {
        windowRef.DrawTileAt(bodyParts[i]); // draw "black" body parts
    }
}

Vector2d Snake::GetPosition() const
{
    return headPos;
}

void Snake::SetDirection(DIRECTION value)
{
    direction = value;
}

void Snake::IncreaseLengthBy1()
{
    bodyParts.push_back(headLastPos);
}

bool Snake::IsRollOver() const
{
    for (size_t i = 1; i < bodyParts.size(); i++)
    {
        if (headPos.ToVector2i().Equals(bodyParts[i]))
        {
            return true;
        }
    }

    return false;
}

bool Snake::IsOnSnake(Vector2i pos) const
{
    for (size_t i = 0; i < bodyParts.size(); i++)
    {
        if (pos.Equals(bodyParts[i]))
        {            
            return true;
        }
    }

    return false;
}