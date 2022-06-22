#ifndef __PACMAN__HUD__
#define __PACMAN__HUD__

#include <iostream>

class Game;
class GameWindow;

class HUD
{
public:
    void Draw(const GameWindow& windowRef) const;
    inline void SetGame(const Game* game) { this->game = game; }
private:
	const Game* game;
};

#endif /* defined(__PACMAN__HUD__) */
