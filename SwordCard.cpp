#include "SwordCard.h"

#include <iostream>

// Constructor
SwordCard::SwordCard(int pointValue)
	: Card(CardType::Sword, pointValue)
{}

std::string SwordCard::str() const
{
	return "Sword(" + std::to_string(_pointValue) + ")";
}

void SwordCard::play(Game& game, Player& player)
{
	// Psuedocode
	// std::cout abilty
	std::cout << "Steal the top card (i.e. the highest value) of any suit from the other player's Bank into your Play Area. You must select one card" << std::endl;
	// Get reference to _otherPlayer
	// IF _otherPlayer _bank empty()
	//	std::cout << "No cards in other player's bank" << std::endl;
	//	return
	// Display numbered list of selectable Cards from _otherPlayer _bank
	// Prompt _currentPlayer for selection
	// Determine chosen suit
	// Remove highest pointValue Card of chosen suit from _otherPlayer _bank
	// IF no matching Card
	//	std:cout << "No matching card " << std::endl;
	//	return
	// std:cout stolen Card
	// Play stolen Card
	//	player.playCard(stolenCard, game)
	//		playCard() will:
	//			add stolenCard to _playArea
	//			check for bust()
	//			trigger stolenCard ability IF !bust()
	//	IF playCard() == true
	//		std::cout << bust message
	//		move all Cards in _playArea to _discardPile
	//		end turn for _currentPlayer
}

void SwordCard::willAddToBank(Game& game, Player& player) 
{
	// TO DO: implement logic
}