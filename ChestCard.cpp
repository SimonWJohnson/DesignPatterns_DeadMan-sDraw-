#include "ChestCard.h"
#include "Player.h"
#include "Game.h"

#include <iostream>

// Constructor
ChestCard::ChestCard(int pointValue)
	: Card(CardType::Chest, pointValue)
{}

std::string ChestCard::str() const
{
	return "Chest(" + std::to_string(_pointValue) + ")";
}

// ChestCard has no immediate effect when drawn
void ChestCard::play(Game& game, Player& player)
{
	std::cout << "No immediate effect. If banked with a Key card, draw as many bonus cards from the Discard pile as you moved into your Bank" << std::endl;
}

void ChestCard::willAddToBank(Game& game, Player& player)
{
	// Pseudocode
	// Check if _playArea also contains a KeyCard
	bool hasKey = false;

	for (Card* card : player.playArea()) 
	{
		if (card->type() == CardType::Key) 
		{
			hasKey = true;
			break;
		}
	}

	// IF Key not present, return 
	if (!hasKey) // ** Check this
	{
		return;
	}

	// Determine number of Cards being moved into _bank this turn
	// The number of bonusCards drwan = number of Cards moved from _playArea to _bank this turn
	// This is the bonusCount
	int bonusCount = static_cast<int>(player.playArea().size());

	// If the _discardPile is empty, no Cards can be drawn
	// IF _discardPile empty()
	if (game.discardPile().empty())
	{
		std::cout << "No cards in the Discard Pile. Play continues" << std::endl;
		return;
	}

	// Display Special Ability message to _currentPlayer
	std::cout << "Chest + Key! Draw " << bonusCount << " bonus cards from the Discard Pile into the Bank" << std::endl;

	// Repeat action up to bonusCount
	//	IF _discardPile empty(), return
	for (int i = 0; i < bonusCount && !game.discardPile().empty(); ++i )
	{
		//	draw() top Card from _discardPile
		Card* bonusCard = game.discardPile().drawTop();
		
		if (bonusCard != nullptr) 
		{
			// add card to _currentPlayer _bank
			player.addToBank(bonusCard);

			// std::cout message bonusCard added
			std::cout << "Bonus card banked: " << bonusCard->str() << std::endl;
		}
	}
}