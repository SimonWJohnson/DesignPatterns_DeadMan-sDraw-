#pragma once

#include "Card.h"

class KrakenCard : public Card
{
public:
	KrakenCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;
};