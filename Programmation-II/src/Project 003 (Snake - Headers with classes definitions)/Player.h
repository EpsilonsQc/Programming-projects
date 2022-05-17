// Snake - Headers with classes definitions
// Player.h (Class definition | Function prototypes and data members)

#pragma once

#include <string>

class Player
{
public:

	Player();

	void playerName();
	void setLevel();
	void score();

private:

	std::string playerName;
	int level;
	int score;
};