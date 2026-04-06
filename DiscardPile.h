#pragma once


#include "Card.h"

class DiscardPile 
{
public:
	// Constructor
	DiscardPile();

	// Deconstructor
	~DiscardPile();

	// Add a Card to the DiscardPile
	void add(Card* card);

	// Draw a Card from the top of the DiscardPile (end of the vector)
	Card* drawTop();

	// Check if DiscardPile is empty
	bool empty() const;

	// Check how many Cards are in the DiscardPile
	int size() const;

	// Designate how many Cards to draw from the DiscardPile
	// Returns a collection of those Cards
	CardCollection drawUpTo(int count);

	// Return a reference to the _cards collection
	// Allows modification
	CardCollection& cards();

	// Returns a read only reference to _cards
	// Prevents modification
	const CardCollection& cards() const;

private:
	CardCollection _cards;
};
