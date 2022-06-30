#include "MovingGameObject.h"

#include "Ghost.h"
#include "Maze.h"
#include "PacDots.h"
#include "Pacman.h"
#include "Portal.h"
#include "Wall.h"

using namespace std;

MovingGameObject::MovingGameObject(const Maze* maze):
maze(maze),
currentDirection(INITIAL_DIRECTION),
nextDirection(currentDirection),
lastMoveTime(0),
lastPosition(GetPosition())
{
}

void MovingGameObject::Move(double currentTime)
{
    if(speed > 0)
    {
        double deltaTime = 1 / speed;
        if(currentTime - lastMoveTime >= deltaTime)
        {
            MoveBy(1);
            lastMoveTime = currentTime;
        }
    }
}

void MovingGameObject::MoveBy(int deltaPosition)
{
    lastPosition = GetPosition();
    
    if(currentDirection != nextDirection && !maze->IsWallAt(GetNextPosition(nextDirection, GetPosition(), deltaPosition)))
    {
        currentDirection = nextDirection;
    }
    
    SetPosition(GetNextPosition(currentDirection, GetPosition(), deltaPosition));
}

Vector2i MovingGameObject::GetNextPosition(DIRECTION dir, Vector2i position, int deltaPosition)
{
    switch(dir)
    {
        case EAST:
            position.x += deltaPosition;
            break;
        case WEST:
            position.x -= deltaPosition;
            break;
        case NORTH:
            position.y -= deltaPosition;
            break;
        case SOUTH:
            position.y += deltaPosition;
            break;
        default:
            std::cerr << "Invalid direction=" << dir << std::endl;
    }
    return position;
}

void MovingGameObject::SetDirection(DIRECTION value)
{
    speed = defaultSpeed;
    nextDirection = value;
}

void MovingGameObject::OnCollision(const GameObject* other)
{
    const Wall* wall = dynamic_cast<const Wall*>(other);
    if(wall != nullptr)
    {
        OnCollisionWithWall(wall);
        return;
    }
    
    const PacDots* dot = dynamic_cast<const PacDots*>(other);
    if(dot != nullptr)
    {
        OnCollisionWithDot(dot);
        return;
    }
    
    const Ghost* ghost = dynamic_cast<const Ghost*>(other);
    if(ghost != nullptr)
    {
        OnCollisionWithGhost(ghost);
        return;
    }
    
    const Portal* portal = dynamic_cast<const Portal*>(other);
    if(portal != nullptr)
    {
        OnCollisionWithPortal(portal);
        return;
    }
    
    const Pacman* pacman = dynamic_cast<const Pacman*>(other);
    if(pacman != nullptr)
    {
        OnCollisionWithPacman(pacman);
        return;
    }
}

void MovingGameObject::OnCollisionWithPortal(const Portal* portal)
{
    SetPosition(portal->GetOther()->GetPosition());
    MoveBy(1);
}