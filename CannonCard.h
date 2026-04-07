#pragma once

#include "Card.h"

class CannonCard : public Card
{
public:

	//Constructor
	CannonCard(int pointValue);

	// Return Card as text
	std::string str() const override;

	// Execute Special Ability
	void play(Game& game, Player& player) override;

	void willAddToBank(Game& game, Player& player) override;
};