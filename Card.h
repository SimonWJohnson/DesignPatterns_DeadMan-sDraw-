#pragma once // header file only included once during compilation

#include <string> 
#include <vector>

class Game;
class Player;

// Enum representing different types of Cards in the game
// Strongly typed, safer than regular enum
enum class CardType 
{
	Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken
};

class Card 
{
public:
	//Constructor
	// Card defines the rules, derived Classes define the behaviour
	Card(CardType type, int pointValue);

	// Virtual destructor to ensure proper cleanup when deleting derived classes
	virtual ~Card() = default;

	// Getters for card type & pointValue
	// Returns a reference to the card's type
	// Returns the card's point value
	// const ensures this function doesn't modify the object
	const CardType& type() const;
	int pointValue() const;

	// Pure virtual function - must be implemented by derived classes
	// Returns a string representation of the card
	virtual std::string str() const = 0;

	// Pure virtual function
	// Defines what happens when the card is played
	// Takes references to Game and POlayer to modify Game state
	virtual void play(Game& game, Player& player) = 0;

	// Virtual function with default implementation
	// Can be overridden by derived classes
	// used to define behaviour when card is added to a Player's Bank
	virtual void willAddToBank(Game& game, Player& player);

protected:
	// Stores the Card's type (Cannon, Sword, etc.)
	CardType _type;

	// Stores how many points the Card is worth
	int _pointValue;
};

// Alias for a collection of Card Pointers
// CardCollection is a vector of pointers to Card objects
// This allows storing different derived Card's polymorphically 
typedef std::vector<Card*> CardCollection;