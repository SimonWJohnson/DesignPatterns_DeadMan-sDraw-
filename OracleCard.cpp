#include "OracleCard.h"

#include <iostream>

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
	// Peek top Card of Deck - game.deck().peekTop()
	// IF _deck enpty()
	//		std::cout << "No cards in deck" << std::endl;
	//		return
	// Print topCard for _player to see
	// std::cout << ""The Oracle sees a <topCard>" << std::endl;
	// Prompt _player to choose to draw the Card
	// Read / validate input
	// IF input = "n"
	//		no action
	//		return
	// IF input = "y"
	//		draw Card from _deck
	//		Print "<_player> draws a <topCard>"
	//		call player.playCard(drawnCard, game)
	//		IF bust:
	//			std:cout bust message
	//			move Cards in _playArea to _discardPile
	// ELSE play continues
	//		std::cout << "Play continues" << std::endl; 
}

void OracleCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}