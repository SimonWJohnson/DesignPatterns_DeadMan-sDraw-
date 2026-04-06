#include "OracleCard.h"

#include <iostream>

// Constructor
OracleCard::OracleCard(int pointValue)
	: Card(CardType::Oracle, pointValue)
{}

std::string OracleCard::str() const
{
	return "Oracle(" + std::to_string(_pointValue) + ")";
}

void OracleCard::play(Game& game, Player& player)
{
	std::cout << "Peek at the top card of the deck before choosing whether to draw" << std::endl;
}

void OracleCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}