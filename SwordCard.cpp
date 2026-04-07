#include "SwordCard.h"
#include "Player.h"
#include "Game.h"

#include <iostream>
#include <limits>

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
	Player& other = game.otherPlayer();

	// Check the otherPlayer's _bank for Cards to steal
	if (other.bankEmpty())
	{
		std::cout << "No cards in other player's bank" << std::endl;
		return;
	}

	// Display otherPlayer's _bank
	std::cout << other.name() << "'s Bank: " << std::endl;

	const CardCollection& otherBank = other.bank();
	for (Card* card : otherBank) 
	{
		std::cout << " " << card->str() << std::endl;
	}

	// Use a while loop to handle incorrect selection
	while (true)
	{
		std::cout << "Choose a suit to steal from " << other.name() << "'s Bank: " << std::endl;
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

		// Remove highest pointValue Card of selected suit from _currentPlayer _bank
		Card* stolenCard = other.removeHighestOfSuitFromBank(chosenType);

		// IF no Card of that suit exists in _bank
		if (stolenCard == nullptr)
		{
			std::cout << "No card of that suit found in " << other.name() << "'s Bank. Try again" << std::endl;
			continue;
		}

		// Display action to the currentPlayer
		std::cout << "You stole " << stolenCard->str() << " from" << other.name() <<"'s Bank" << std::endl;

		// Check for bust
		bool bust = player.playCard(stolenCard, game);

		// If the moved Card causes a bust
		if (bust)
		{
			// Display bust message to currentPlayer
			std::cout << "BUST! " << player.name() << " loses all cards in Play Area" << std::endl;

			// Move all Cards in _playArea to _discardPile
			player.discardPlayArea(game.discardPile().cards());

		}
		// End while
		break;
	}
}

void SwordCard::willAddToBank(Game& game, Player& player) 
{
	// TO DO: implement logic
}