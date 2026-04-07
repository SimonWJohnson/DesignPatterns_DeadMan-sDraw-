#include "CannonCard.h"

#include <iostream>

// Constructor
CannonCard::CannonCard(int pointValue)
	: Card(CardType::Cannon, pointValue)
{}

std::string CannonCard::str() const
{
	return "Cannon(" + std::to_string(_pointValue) + ")";
}

void CannonCard::play(Game& game, Player& player)
{
	// Psuedocode
	// Print Card ability
	std::cout << "Discard the top card (i.e. the highest value) of any suit from the other player's Bank to the Discard Pile" << std::endl;
	// Get reference to other Player / game.otherPlayer()
	// IF _otherPLayer's _bank.empty()
	// std::cout << "No cards in _otherPlayer's _bank" Play continues (return)
	// Display _otherPLayer's _bank so _currentPLayer can choose a suit
	// std::cout
	// Prompt _currentPlayer to select a suit 
	// Determine which suit has been chosen
	// Remove highest pointValue Card from selected suit from _otherPlayer's _bank
	// IF no Card is found
	// std::cout no card found message, return
	// Add removed Card to _discardPile
	// std::cout which Card was discarded
}

void CannonCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}