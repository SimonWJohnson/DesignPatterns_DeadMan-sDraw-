#include "CannonCard.h"
#include "Game.h"
#include "Player.h"

#include <iostream>
#include <limits>

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
	Player& other = game.otherPlayer();
	// IF _otherPLayer's _bank.empty()
	if (other.bankEmpty()) 
	{
		std::cout << "No cards in other player's bank. Play continues" << std::endl;
		return;
	}
	
	// Display _otherPLayer's _bank so _currentPLayer can choose a suit
	std::cout << other.name() << "'s Bank: " << std::endl;
	
	const CardCollection& otherBank = other.bank();
	for (Card* card : otherBank) 
	{
		std::cout << " " << card->str() << std::endl;
	}
	while (true) 
	{
		// Prompt _currentPlayer to select a suit to discard
		std::cout << "Choose a suit to discard from " << other.name() << "'s Bank: " << std::endl;
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
			std::cout << "Invalid choice. Play continues" << std::endl;
			return;
		}

		// Remove highest pointValue Card from selected suit from _otherPlayer's _bank
		Card* removedCard = other.removeHighestOfSuitFromBank(chosenType);

		// IF no Card is found
		if (removedCard == nullptr)
		{
			std::cout << "No card of that suit found in " << other.name() << "'s Bank" << std::endl;
			continue;
		}

		// Add removed Card to _discardPile
		game.discardPile().add(removedCard);

		// Display which Card was discarded
		std::cout << removedCard->str() << " was discarded from " << other.name() << "'s Bank" << std::endl;

		break;
	}

}


void CannonCard::willAddToBank(Game& game, Player& player)
{
	// Not required
}