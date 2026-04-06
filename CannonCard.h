#pragma once

#include "Card.h"

class CannonCard : public Card
{
public:
	CannonCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;

	void willAddToBank(Game& game, Player& player) override;
};