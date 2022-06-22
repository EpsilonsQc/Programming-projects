#include "Pacman.h"

#include "Defines.h"
#include "Ghost.h"
#include "PacDots.h"
#include "Vector2i.h"
#include "Wall.h"

using namespace std;

Pacman::Pacman(Maze* maze):
MovingGameObject(maze)
{
    Color originalColor = Color::Yellow;
    SetColor(originalColor);
    
    defaultSpeed = DEFAULT_PACMAN_SPEED;
    speed = 0;
}

void Pacman::OnCollisionWithWall(const Wall* wall)
{
    speed = 0;
    SetPosition(GetLastPosition());
}

void Pacman::OnCollisionWithGhost(const Ghost* ghost)
{
	speed = 0;
	dead = true;
}

void Pacman::OnCollisionWithDot(const PacDots* dot)
{

}

void Pacman::Move(double currentTime)
{
    MovingGameObject::Move(currentTime);
}

