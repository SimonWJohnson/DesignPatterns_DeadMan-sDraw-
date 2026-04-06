#include "SwordCard.h"

#include <iostream>

// Constructor
SwordCard::SwordCard(int pointValue)
	: Card(CardType::Sword, pointValue)
{}

std::string SwordCard::str() const
{
	return "Sword(" + std::to_string(_pointValue) + ")";
}

void SwordCard::play(Game& game, Player& player)
{
	std::cout << "Steal the top card (i.e. the highest value) of any suit from the other player's Bank into your Play Area. You must select one card" << std::endl;
}

void SwordCard::willAddToBank(Game& game, Player& player) 
{
	// TO DO: implement logic
}