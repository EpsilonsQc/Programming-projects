#pragma once

#include <vector>
#include <string>
#include "Card.h"

class Player
{
public:
	Player(std::string);
	void drawCard(Card);
	void reveal();
private:
	std::string name;
	std::vector<Card> hand;
};

