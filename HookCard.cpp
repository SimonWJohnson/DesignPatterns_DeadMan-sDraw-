#include "HookCard.h"
#include "Game.h"
#include "Player.h"

#include <iostream>
#include <limits>

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
	if (player.bankEmpty()) 
	{
		std::cout << "No cards in your Bank. Play continues " << std::endl;
		return;
	}

	// Display currentPlayer's _bank so they can choose a suit
	std::cout << player.name() << "'s Bank: " << std::endl;

	const CardCollection& bank = player.bank();
	for (Card* card : bank) 
	{
		std::cout << " " << card->str() << std::endl;
	}

	// Prompt _player to choose which Card / Suit they want to play
	// Use a while loop to handle incorrect selection
	while (true) 
	{
		std::cout << "Choose a suit to move to your Play Area" << std::endl;
		std::cout << "1. Cannon" << std::endl;
		std::cout << "2. Chest" << std::endl;
		std::cout << "3. Key" << std::endl;
		std::cout << "4. Sword" << std::endl;
		std::cout << "5. Hook" << std::endl;
		std::cout << "6. Oracle" << std::endl;
		std::cout << "7. Map" << std::endl;
		std::cout << "8. Mermaid" << std::endl;
		std::cout << "9. Kraken" << std::endl;
		std::cout << "Enter choice: ";

		int choice;
		std::cin >> choice;

		// Validate input
		while (std::cin.fail() || choice < 1 || choice > 9)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid choice. Enter a number from 1 to 9: ";
			std::cin >> choice;
		}

		// Convert numeric choice to CardType
		CardType chosenType;

		// Use a Switch case to convert 
		switch (choice)
		{
		case 1: chosenType = CardType::Cannon; break;
		case 2: chosenType = CardType::Chest; break;
		case 3: chosenType = CardType::Key; break;
		case 4: chosenType = CardType::Sword; break;
		case 5: chosenType = CardType::Hook; break;
		case 6: chosenType = CardType::Oracle; break;
		case 7: chosenType = CardType::Map; break;
		case 8: chosenType = CardType::Mermaid; break;
		case 9: chosenType = CardType::Kraken; break;
		default:
			// Validation should prevent default case
			// Added as an extrra safety net
			std::cout << "Invalid choice. Try again" << std::endl;
			return;
		}

		// Remove hishest pointValue Card of selected suit from _currentPlayer _bank
		Card* selectedCard = player.removeHighestOfSuitFromBank(chosenType);

		// IF no Card of that suit exists in _bank
		if (selectedCard == nullptr)
		{
			std::cout << "No card of that suit found in your Bank. Try again" << std::endl;
			continue;
		}

		// Display action to the currentPlayer
		std::cout << "You played " << selectedCard->str() << " from your Bank int Play Area" << std::endl;

		// Check for bust
		bool bust = player.playCard(selectedCard, game);

		// If the moved Card causes a bust
		if (bust) 
		{
			// Display bust message to currentPlayer
			std::cout << "BUST! " << player.name() << " loses all cards in Play Area" << std::endl;
			
			// Move all Cards in _playArea to _discardPile
			player.discardPlayArea(game.discardPile().cards());

		}
		break;
	}

}

void HookCard::willAddToBank(Game& game, Player& player)
{
	// Not required
}