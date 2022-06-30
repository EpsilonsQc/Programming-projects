#ifndef __PACMAN__Ghost__
#define __PACMAN__Ghost__

#include <iostream>

#include "Defines.h"
#include "MovingGameObject.h"
#include "Vector2i.h"

class Maze;
class Wall;
class Pacman;

class Ghost : public MovingGameObject
{
public:
    Ghost(Maze* maze);
    inline void SetInitialPosition(Vector2i initialPosition) { this->initialPosition = initialPosition; }
    void ReturnToInitialPosition();

private:
    void OnCollisionWithWall(const Wall* wall);
    void OnCollisionWithPacman(const Pacman* pacman);
    Vector2i initialPosition;
};

#endif /* defined(__PACMAN__Ghost__) */
