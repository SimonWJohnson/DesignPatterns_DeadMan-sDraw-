#include "KrakenCard.h"

#include <iostream>

// Constructor
KrakenCard::KrakenCard(int pointValue)
	: Card(CardType::Kraken, pointValue)
{}

std::string KrakenCard::str() const
{
	return "Kraken(" + std::to_string(_pointValue) + ")";
}

void KrakenCard::play(Game& game, Player& player)
{
	std::cout << "" << std::endl;
}

void KrakenCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}