#pragma once

#include "Card.h"

class MapCard : public Card
{
public:
	MapCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;

	void willAddToBank(Game& game, Player& player) override;
};