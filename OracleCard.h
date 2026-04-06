#pragma once

#include "Card.h"

class OracleCard : public Card
{
public:
	OracleCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;
};