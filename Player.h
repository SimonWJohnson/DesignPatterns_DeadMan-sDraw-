#pragma once

#include <string>
#include "Card.h"

/*
Responsibilities:
- manage play area
- detect bust
- manage bank
- calculate score
- print collections
*/

// Forward declaration of Game
// Tells the compiler Game exists without including Game.h here
class Game;

class Player 
{
public:
	// Constructor
	// Creates a Player object with a given name
	Player(const std::string& name);

	// Destructor
	// Clean up dynamically allocated Card pointers 
	~Player();

	// Getter for Player name
	// Returns Player name as a const reference to avoid copying and modification
	const std::string& name() const;


	/* Gameplay Actions */

	// Attempt tp play a Card
	// Returns True / False depending on if the play() was successful
	bool playCard(Card* card, Game& game);

	// Check whether the player has a card of a given type in their play area
	bool hasSuitInPlayArea(CardType type) const;

	// Check whether the Player's play area has caused them to bust
	bool isBust() const;


	/* Play Area Management */
	
	// Moves Cards from the play area into the Player's Bank
	// May also trigger Special Abilities
	void bankPlayArea(Game& game);
	
	// Move Cards from the play area into the discard pile
	void discardPlayArea(CardCollection& discardPile);
	
	//Add Cards to Collections (play area, bank)
	void addToPlayArea(Card* card);
	void addToBank(Card* card);

	/* Scoring */

	// Calculates and returns the Player's score
	// Score based on Cards in Player's Bank
	int score() const;

	/* Display */

	// Print the Cards currently in the play area
	void printPlayArea() const;

	// Print the Cards currently in the bank
	void printBank() const;


	/* Collections */
	// Return True if no Cards in Player's Bank
	bool bankEmpty() const;

	// Return True if no Cards in Player's Play Area
	bool playAreaEmpty() const;

	// Getters for both Collections
	// Both returned as const reference
	const CardCollection& bank() const;
	const CardCollection& playArea() const;

	// Card removal from Collections
	// Removes the highest value Card of a given type from the Player's Bank, then returns it
	Card* removeHighestOfSuitFromBank(CardType type);

	// Removes a number of Cards from discard choices and returns them as a Collection
	CardCollection removeTopFromDiscardedChoices(CardCollection& discardPile, int count);

private:
	// Store the Player's name
	std::string _name;

	// Store Cards the Player has played this round but not yet banked or discarded
	CardCollection _playArea;

	// Store Cards the Player has successfully banked
	// Contributed to Score
	CardCollection _bank;

};
