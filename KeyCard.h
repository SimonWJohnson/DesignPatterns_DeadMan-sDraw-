#pragma once

#include "Card.h"

class KeyCard : public Card
{
public:
	KeyCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;
};