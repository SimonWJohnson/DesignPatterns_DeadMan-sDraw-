#include "OracleCard.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <limits>


// Constructor
OracleCard::OracleCard(int pointValue)
	: Card(CardType::Oracle, pointValue)
{}

std::string OracleCard::str() const
{
	return "Oracle(" + std::to_string(_pointValue) + ")";
}

void OracleCard::play(Game& game, Player& player)
{
	// Psuedocode
	// std::cout << ability message
	std::cout << "Peek at the top card of the deck before choosing whether to draw" << std::endl;
	// Peek the top Card of Deck without removing it
	Card* topCard = game.deck().peekTop();
	
	// Check to see if the Deck is empty
	if (topCard == nullptr) 
	{
		std::cout << "No cards in the Deck to peek" << std::endl;
		return;
	}

	// Display topCard for _player to see
	std::cout << "The Oracle sees a " << topCard->str() << std::endl;

	// Prompt _player to choose to draw the Card
	std::cout << "Draw this card? (y/n): " << std::endl;

	std::string input;
	std::cin >> input;

	// Read / validate input
	if (input == "n")
	{
		std::cout << "Card left on the top of the Deck. Play continues" << std::endl;
		return;
	}

	// Player chooses to draw Card
	Card* drawnCard = game.deck().draw();

	// draw() should return the Card that was peeked
	if (drawnCard == nullptr) 
	{
		std::cout << "No card could be drawn.  Play continues" << std::endl;
		return;
	}

	// Display action to currentPLayer
	std::cout << player.name() << " draws " << drawnCard->str() << std::endl;

	bool bust = player.playCard(drawnCard, game);

	// If the moved Card causes a bust
	if (bust)
	{
		// Display bust message to currentPlayer
		std::cout << "BUST! " << player.name() << " loses all cards in Play Area" << std::endl;

		// Move all Cards in _playArea to _discardPile
		player.discardPlayArea(game.discardPile().cards());

	}
}

void OracleCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}