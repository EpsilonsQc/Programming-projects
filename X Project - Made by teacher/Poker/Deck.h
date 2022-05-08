#pragma once

#include "Player.h"
#include "Card.h"
#include <vector>

class Deck
{
public:
	Deck();
	void print();
	void shuffleDeck();
	void deal(Player&, Player&);

private:
	std::vector<Card> cards;
};

