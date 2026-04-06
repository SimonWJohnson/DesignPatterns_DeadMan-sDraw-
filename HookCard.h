#pragma once

#include "Card.h"

class HookCard : public Card
{
public:
	HookCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;
};