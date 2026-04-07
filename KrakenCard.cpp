#include "KrakenCard.h"
#include "Player.h"
#include "Game.h"

#include <iostream>

// Constructor
KrakenCard::KrakenCard(int pointValue)
	: Card(CardType::Kraken, pointValue)
{}

std::string KrakenCard::str() const
{
	return "Kraken(" + std::to_string(_pointValue) + ")";
}

void KrakenCard::play(Game& game, Player& player)
{
	// Psuedocode
	// Print Card special ability
	std::cout << "Must draw and play three cards consecutively" << std::endl;

	// Repeat 3 forced draws using FOR loop
	for (int i = 0; i < 3; ++i) 
	{
		// Check if the Deck is empty - forced draws cannot occur if no Cards present
		if (game.deck().empty()) 
		{
			std::cout << "Deck is empty; no more cards can be drawn" << std::endl;
			return;
		}

		// Draw the next Card from the Deck
		Card* drawnCard = game.deck().draw();

		// Safety check to avoid null
		if (drawnCard == nullptr)
		{
			std::cout << "No card could be drawn. Play continues" << std::endl;
			return;
		}

		// Display Action tothe currentPlayer
		std::cout << player.name() << " draws " << drawnCard->str() << std::endl;

		// Play each drawn card
		bool bust = player.playCard(drawnCard, game);

		// If Player busts during the 3 Card draw, discard playArea and stop turn
		if (bust)
		{
			// Display bust message to currentPlayer
			std::cout << "BUST! " << player.name() << " loses all cards in Play Area" << std::endl;

			// Move all Cards in _playArea to _discardPile
			player.discardPlayArea(game.discardPile().cards());

			return;
		}
	}

	// If all three draws complete without BUST
	// Play resumes as normal
	std::cout << "Kraken effect complete " << std::endl;
}

void KrakenCard::willAddToBank(Game& game, Player& player)
{
	// Not required
}