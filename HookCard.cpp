#include "HookCard.h"

#include <iostream>

// Constructor
HookCard::HookCard(int pointValue)
	: Card(CardType::Hook, pointValue)
{}

std::string HookCard::str() const
{
	return "Hook(" + std::to_string(_pointValue) + ")";
}

void HookCard::play(Game& game, Player& player)
{
	std::cout << "Play the top card (i.e. highest value) of any suit from your Bank into your play area. You must select one card" << std::endl;
}

void HookCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}