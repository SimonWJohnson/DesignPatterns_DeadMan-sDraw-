#include "HookCard.h"

#include <iostream>

// Constructor
HookCard::HookCard(int pointValue)
	: Card(CardType::Hook, pointValue)
{}

std::string HookCard::str() const
{
	return "Hook(" + std::to_string(_pointValue) + ")";
}

void HookCard::play(Game& game, Player& player)
{
	// Psuedocode
	// std::cout ability message
	std::cout << "Play the top card (i.e. highest value) of any suit from your Bank into your play area. You must select one card" << std::endl;
	// Check _currentPlayer _bank for Cards
	// IF _bank empty()
	//	std::cout << "No cards in Bank. Play continues " << std::endl;
	//	return
	// std::cout << _player's _bank so they can choose a suit
	// std::cin / Prompt _player to choose which Card / Suit they want to play
	//	validate input
	// convert imput into CardType
	// Remove hishest pointValue Card of selected suit from _currentPlayer _bank
	// IF no Card of that suit exists in _bank
	//	std::cout << "No card of that suit found in bank. Play continues " << std:endl;
	//	return
	// std::cout << which Card was 'Hooked' into _playArea
	// Play chosen card -> player.playCard(chosenCard, game)
	//		addToPlayArea()
	//		check for bust
	//		trigger ability of played Card
	//		IF playCard() returns true
	//			std:cout << bust message
	//			move all Cards in _playArea to _discardPile
}

void HookCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}