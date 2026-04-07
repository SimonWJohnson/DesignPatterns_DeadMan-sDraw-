#include "ChestCard.h"

#include <iostream>

// Constructor
ChestCard::ChestCard(int pointValue)
	: Card(CardType::Chest, pointValue)
{}

std::string ChestCard::str() const
{
	return "Chest(" + std::to_string(_pointValue) + ")";
}

void ChestCard::play(Game& game, Player& player)
{
	std::cout << "No immediate effect. If banked with a Key card, draw as many bonus cards from the Discard pile as you moved into your Bank" << std::endl;
}

void ChestCard::willAddToBank(Game& game, Player& player)
{
	// Psuedocode
	// Check if _playArea also contains a KeyCard
	// IF Key not present, return
	// Determine number of Cards being moved into _bank this turn
	// This is the bonusCount
	// IF _discardPile empty()
	//	std::cout "No cards in the Discard Pile"
	//	return
	// Repeat action up to bonusCount
	//	IF _discardPile empty(), return
	//	draw() top Card from _discardPile
	// add card to _currentPlayer _bank
	// std::cout bonusCard added
	// use a guard so effect does NOT trigger twice 
}