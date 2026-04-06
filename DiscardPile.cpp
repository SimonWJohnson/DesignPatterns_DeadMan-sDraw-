#include "DiscardPile.h"

// Constructor
DiscardPile::DiscardPile() 
{
	// Iterate through the DiscardPile
	for (Card* card : _cards) 
	{
		// Delete the pointer to each Card
		delete card;
	}
}

// Deconstructor
DiscardPile::~DiscardPile() 
{

}

// Add a Card to the DiscardPile
void DiscardPile::add(Card* card) 
{

}

// Draw a Card from the top of the DiscardPile (end of the vector)
Card* DiscardPile::drawTop() 
{

}

// Check if DiscardPile is empty
bool DiscardPile::empty() const 
{

}

// Check how many Cards are in the DiscardPile
int DiscardPile::size() const 
{

}

// Designate how many Cards to draw from the DiscardPile
// Returns a collection of those Cards
CardCollection DiscardPile::drawUpTo(int count) 
{

}

// Return a reference to the _cards collection
// Allows modification
CardCollection& DiscardPile::cards() 
{

}

// Returns a read only reference to _cards
// Prevents modification
const CardCollection& DiscardPile::cards() const 
{

}