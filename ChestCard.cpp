#include "ChestCard.h"

#include <iostream>

// Constructor
ChestCard::ChestCard(int pointValue)
	: Card(CardType::Chest, pointValue)
{}

std::string ChestCard::str() const
{
	return "Chest(" + std::to_string(_pointValue) + ")";
}

void ChestCard::play(Game& game, Player& player)
{
	std::cout << "" << std::endl;
}

void ChestCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}