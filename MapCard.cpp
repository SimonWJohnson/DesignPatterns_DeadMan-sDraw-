#include "MapCard.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <limits>

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

	// Get reference to the DiscardPile
	CardCollection& discard = game.discardPile().cards();

	// Check if discardPile is empty
	if (discard.empty()) 
	{
		std::cout << "No cards in the discard pile. Play continues" << std::endl;
		return;
	}

	CardCollection drawnCards;

	// Draw up to 3 Cards from the discardPile
	for (int i = 0; i < 3 && !discard.empty(); ++i) 
	{
		// Draw from the top of the discardPile
		drawnCards.push_back(discard.back());
		discard.pop_back();
	}

	// Display the drawn Cards as choices to the currentPlayer
	std::cout << "Choose 1 of the following cards to play: " << std::endl;

	for (size_t i =0; i < drawnCards.size(); ++i) 
	{
	std::cout << i + 1 << ". " << drawnCards[i]->str()<< std::endl;
	}

	// Get Player Card selection
	int choice;
	std::cin >> choice;

	// Validate the input
	while (std::cin.fail() || choice < 1 || choice > static_cast<int>(drawnCards.size())) 
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid choice. Enter a number from 1 to " << drawnCards.size() << ": ";
		std::cin >> choice;
	}

	// Extract the chosenCard from the index position
	Card* chosenCard = drawnCards[choice - 1];

	// Display chosenCard / selection to currentPLayer
	std::cout << "You selected " << chosenCard->str() << std::endl;

	// Return the unchosen Card(s) to the discardPile
	for (size_t i = 0; i < drawnCards.size(); ++i) 
	{
		// Card != PLayer choice
		if (i != static_cast<size_t>(choice - 1)) 
		{
			// Move Card(s) to the top of the discardPile 
			discard.push_back(drawnCards[i]);
		}
	}

	// Play the chosenCard and check for bust
	bool bust = player.playCard(chosenCard, game);

	// If playing chosenCard causes bust, end turn and clear playArea
	if (bust) 
	{
		std::cout << "BUST!" << player.name() << " loses all cards in Play Area" << std::endl;

		// Move all Cards in _playArea to _discardPile
		player.discardPlayArea(game.discardPile().cards());
	}

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