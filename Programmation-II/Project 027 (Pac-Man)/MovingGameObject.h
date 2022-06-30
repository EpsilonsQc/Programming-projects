#ifndef __PACMAN__MovingGameObject__
#define __PACMAN__MovingGameObject__

#include <iostream>

#include "Defines.h"
#include "GameObject.h"

class Maze;
class Ghost;
class Wall;
class PacDots;
class Pacman;
class Portal;

class MovingGameObject : public GameObject
{
public:
    MovingGameObject(const Maze* maze);
    
    inline Vector2i GetLastPosition() const { return lastPosition; }
    inline void SetLastPosition(Vector2i position) { this->lastPosition = position; }
    
    void SetDirection(DIRECTION value);
    void Move(double currentTime);
    void MoveBy(int deltaPosition);
    void OnCollision(const GameObject* other);

protected:
    static Vector2i GetNextPosition(DIRECTION dir, Vector2i position, int deltaPosition);
    virtual void OnCollisionWithWall(const Wall* wall) {}
    virtual void OnCollisionWithDot(const PacDots* dot) {}
    virtual void OnCollisionWithPortal(const Portal* portal);
    virtual void OnCollisionWithGhost(const Ghost* ghost) {}
    virtual void OnCollisionWithPacman(const Pacman* pacman) {}
    
protected:
    const Maze* maze;
    DIRECTION currentDirection;
    DIRECTION nextDirection; 
    double speed;//units per seconds //TODO check units
    double defaultSpeed;//units per seconds
    double lastMoveTime;
    Vector2i lastPosition;
};

#endif /* defined(__PACMAN__MovingGameObject__) */
