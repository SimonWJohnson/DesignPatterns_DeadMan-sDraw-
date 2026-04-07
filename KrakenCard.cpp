#include "KrakenCard.h"

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
	//		IF _deck empty(), no more draws can occur
	//		std::cout << "" << std::endl;
	//		return
	//		Draw next Card from _deck
	//		Validate Card for nullptr (end of _deck)
	//			std:cout message for empty _deck
	//			return
	// Display drawn Card to _currentPlayer - std::cout <<
	// Call player.playCard()
	//		drawn Card tranferred to _playArea
	//		_player checked for bust
	//		IF bust:
	//			print bust message
	//			Cards removed from _playArea, transferred to _discardPile
	//			_currentPlayer turn ends, switch to _otherPlayer
	//		ELSE
	//			All forced Draws complete without bust
	//			Play resumes as normal for _currentPlayer
	//	Print message to signify end of Kraken effect
	//		std::cout << "Kraken effect complete" << std::endl;

}

void KrakenCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}