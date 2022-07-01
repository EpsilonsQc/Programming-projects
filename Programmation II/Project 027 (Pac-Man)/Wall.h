#ifndef __PACMAN__Wall__
#define __PACMAN__Wall__

#include <iostream>

#include "GameObject.h"
class GameWindow;

class Wall : public GameObject
{
public:
    Wall();
    void OnCollision(const GameObject* other);
};

#endif /* defined(__PACMAN__Wall__) */
