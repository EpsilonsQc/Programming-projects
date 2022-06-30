#include "Ghost.h"

#include "Maze.h"
#include "Pacman.h"
#include "Wall.h"


using namespace std;

static vector<Ghost*> ghosts;

Ghost::Ghost(Maze* maze):
MovingGameObject(maze)
{
    SetColor(Color::Red);
    defaultSpeed = DEFAULT_GHOST_SPEED;
    speed = defaultSpeed;
    ghosts.push_back(this);
}

void Ghost::OnCollisionWithWall(const Wall* wall)
{
    SetPosition(GetLastPosition());
    currentDirection = static_cast<DIRECTION>(FIRST + rand() % LAST);
    nextDirection = static_cast<DIRECTION>(FIRST + rand() % LAST);
}

void Ghost::ReturnToInitialPosition()
{
    SetPosition(initialPosition);
}

void Ghost::OnCollisionWithPacman(const Pacman* pacman)
{

}
