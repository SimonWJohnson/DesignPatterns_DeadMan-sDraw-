#include "MapCard.h"

#include <iostream>

// Constructor
MapCard::MapCard(int pointValue)
	: Card(CardType::Map, pointValue)
{}

std::string MapCard::str() const
{
	return "Map(" + std::to_string(_pointValue) + ")";
}

void MapCard::play(Game& game, Player& player)
{
	std::cout << "" << std::endl;
}

void MapCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}