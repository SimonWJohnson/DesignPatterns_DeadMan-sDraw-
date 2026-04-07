#include "MapCard.h"

#include <iostream>

// Constructor
MapCard::MapCard(int pointValue)
	: Card(CardType::Map, pointValue)
{}

std::string MapCard::str() const
{
	return "Map(" + std::to_string(_pointValue) + ")";
}

void MapCard::play(Game& game, Player& player)
{
	// Psuedocode
	// Print Card Special Ability
	std::cout << "Draw 3 cards from the discard pile. You must play one of the cards drawn into your play area" << std::endl;
	// Check _discardPile
	// IF _discardPile empty()
	//		std::cout << "No cards in the Discard Pile" << std::endl;
	//		return
	// Draw up to 3 Cards from the _discardPile and place in temp collection (up to 3 Cards depending on _discardPile size)
	// Display the drawn Cards as choices to _currentPlayer
	// Prompt _currentPLayer to make a selection std::cin >>
	// Validate input
	// Extract chosen Card and displey to _currentPLayer
	// Return unchosen Cards to _discardPile
	// Call player.playCard(chosenCard, game) to play selected Card
	//		IF bust
	//			print bust message
	//			transfer Cards in _playArea to _discardPile

}

void MapCard::willAddToBank(Game& game, Player& player)
{
	// TO DO: implement logic
}