#ifndef __PACMAN__PacDots__
#define __PACMAN__PacDots__

#include <iostream>

#include "GameObject.h"

class GameWindow;
class Maze;

class PacDots : public GameObject
{
public:
    PacDots(Maze* maze);
    void OnCollision(const GameObject* other);
    void Draw(const GameWindow& windowRef) const;
    
private:
    Maze* maze;
};

#endif /* defined(__PACMAN__PacDots__) */
