#pragma once

#include "Card.h"

class SwordCard : public Card
{
public:
	SwordCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;

	void willAddToBank(Game& game, Player& player) override;
};