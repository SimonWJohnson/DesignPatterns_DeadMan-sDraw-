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

private:
	// Store the Player's name
	std::string _name;

	// Store Cards the Player has played this round but not yet banked or discarded
	CardCollection _playArea;

	// Store Cards the Player has successfully banked
	// Contributed to Score
	CardCollection _bank;

};
