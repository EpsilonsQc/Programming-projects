#include "Player.h"

#include <iostream>

using namespace std;

Player::Player(std::string name):
	name(name)
{
}

void Player::reveal()
{
	cout << "Player " << name << " hand:" << endl;
	for(Card c : hand)
	{
		c.print();
	}
}

void Player::drawCard(Card c)
{
	hand.push_back(c);
}