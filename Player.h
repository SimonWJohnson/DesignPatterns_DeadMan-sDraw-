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
	bool hasCardTypeInPlayArea(CardType type) const;

	// Check whether the Player's play area has caused them to bust
	bool isBust() const;


	/* Play Area Management */


	/* Scoring */


	/* Display */


	/* Collections */

private:
	// Store the Player's name
	std::string _name;

	// Store Cards the Player has played this round but not yet banked or discarded
	CardCollection _playArea;

	// Store Cards the Player has successfully banked
	// Contributed to Score
	CardCollection _bank;

};
