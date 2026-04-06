#include "KeyCard.h"

#include <iostream>

// Constructor
KeyCard::KeyCard(int pointValue)
	: Card(CardType::Key, pointValue)
{}

std::string KeyCard::str() const
{
	return "Key(" + std::to_string(_pointValue) + ")";
}

void KeyCard::play(Game& game, Player& player)
{
	std::cout << "" << std::endl;
}

void KeyCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}