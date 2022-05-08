#pragma once

#include "Defines.h"
#include <string>

class Card
{
public:
	//Card();
	Card(int, ::Suit);
	void set(int, ::Suit);
	void print();
private:
	std::string getSuitName();

private:
	int value;
	Suit suit;
};

