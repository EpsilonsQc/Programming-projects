#pragma once

const int NB_CARDS = 52;
const int NB_SUITS = 4;
const int NB_CARD_PER_SUIT = NB_CARDS / NB_SUITS;
const int NB_CARDS_IN_HAND = 5;

enum class Suit
{
	Heart = 0,
	Diamonds,
	Clubs,
	Spades
};