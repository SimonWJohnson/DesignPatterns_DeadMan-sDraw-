#include "CannonCard.h"

#include <iostream>

// Constructor
CannonCard::CannonCard(int pointValue)
	: Card(CardType::Cannon, pointValue)
{}

std::string CannonCard::str() const
{
	return "Cannon(" + std::to_string(_pointValue) + ")";
}

void CannonCard::play(Game& game, Player& player)
{
	std::cout << "Discard the top card (i.e. the highest value) of any suit from the other player's Bank to the Discard Pile" << std::endl;
}

void CannonCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}