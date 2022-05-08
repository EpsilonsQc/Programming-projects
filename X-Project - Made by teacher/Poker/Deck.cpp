#include "Deck.h"
#include <random>
#include <algorithm>

using namespace std;

Deck::Deck():
	cards{}
{
	for(int i = 0; i < NB_CARDS; i++)
	{
		int value = i % NB_CARD_PER_SUIT + 1;
		Suit s = static_cast<Suit>(i / NB_CARD_PER_SUIT);
		cards.push_back(Card(value, s));
		//cards[i].set(value, s);
	}
}

void Deck::shuffleDeck()
{
	default_random_engine randomEngine{ random_device{}() };
	shuffle(cards.begin(), cards.end(), randomEngine);
}

void Deck::deal(Player &p1, Player &p2)
{
	shuffleDeck();

	for(int i = 0; i < NB_CARDS_IN_HAND; i++)
	{
		p1.drawCard(cards.back());
		cards.pop_back();
		p2.drawCard(cards.back());
		cards.pop_back();
	}
}

void Deck::print()
{
	for(Card c : cards)
	{
		c.print();
	}
}