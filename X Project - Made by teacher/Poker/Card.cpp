#include "Card.h"
#include <iostream>

using namespace std;

//Card::Card() :
//	value(1),
//	suit(Suit::Heart)
//{
//}

Card::Card(int value, ::Suit suit):
	value(value),
	suit(suit)
{
}
void Card::set(int v, ::Suit s)
{
	value = v;
	suit = s;
}

void Card::print()
{
	cout << value << " " << getSuitName() << endl;
}

std::string Card::getSuitName()
{
	switch (suit)
	{
	case Suit::Heart:
		return "Heart";
	case Suit::Diamonds:
		return "Diamonds";
	case Suit::Clubs:
		return "Clubs";
	case Suit::Spades:
		return "Spades";
	default:
		return "ERROR";
	}
}