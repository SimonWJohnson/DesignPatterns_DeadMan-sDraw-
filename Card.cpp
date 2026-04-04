#include "Card.h"

/*
Responsibilities:
- Presenting the card type back to the Player
- Playing that type of Card
*/

// Constructor implementation
Card::Card(CardType type, int pointValue) 
	: _type(type), _pointValue(pointValue) 
{
}

// Getter for CardType
// To avoid copying and modification, a const reference to the Card's type is returned
const CardType& Card::type() const 
{
	return _type;
}


// Getter for pointValue
// Simple value return
int Card::pointValue() const
{
	return _pointValue;
}

// Default implementation of willAddToBank()
void Card::willAddToBank(Game& game, Player& player)
{
	// Default action is no Banking effect
	// Intentionally blank
	// Derived classes can override this method to define special behaviour when added to a Player's Bank
}