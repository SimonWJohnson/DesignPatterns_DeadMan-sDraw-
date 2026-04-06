#pragma once

#include "Card.h"

class MermaidCard : public Card 
{
public:
	MermaidCard(int pointValue);

	std::string str() const override;

	void play(Game& game, Player& player) override;
};