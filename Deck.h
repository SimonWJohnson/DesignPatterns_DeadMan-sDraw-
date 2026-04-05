#pragma once

#include "Card.h"

class Deck
{
public:
	// Constructor
	Deck();

	// Destructor
	~Deck();

	// Add a Card to the Deck
	// Pushes a Card pointer into the Deck's Collection
	void addCard(Card* card);

	// Shuffle the Deck
	void shuffle();

	// Removes and returns the top Card from the Deck
	Card* draw();

	// Conditional check to see if deck is empty
	bool empty() const;

	// Returns the number of Cards in the Deck
	int size() const;

	// Check the Card at the top of the Deck without removing it
	// Returns a pointer to the top Card in the Deck
	Card* peekTop() const;

private:
	// Vector containing all cards in the Deck
	CardCollection _cards;
};
