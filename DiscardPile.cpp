#include "DiscardPile.h"

// Constructor
DiscardPile::DiscardPile() 
{

}

// Deconstructor
DiscardPile::~DiscardPile() 
{
	// Iterate through the DiscardPile
	for (Card* card : _cards)
	{
		// Delete the pointer to each Card
		delete card;
	}
}

// Add a Card to the DiscardPile
// Card is placed at the end of the vector
void DiscardPile::add(Card* card) 
{
	_cards.push_back(card);
}

// Draw a Card from the top of the DiscardPile (end of the vector)
Card* DiscardPile::drawTop() 
{
	// Check if DiscardPile contains Cards
	if (_cards.empty()) 
	{
		// Nothing to return
		return nullptr;
	}

	// Set the Card to Draw as the last in the vector
	Card* top = _cards.back();
	// pop the top Card and return it
	_cards.pop_back();
	return top;
}

// Check if DiscardPile is empty
bool DiscardPile::empty() const 
{
	return _cards.empty();
}

// Check how many Cards are in the DiscardPile
int DiscardPile::size() const 
{
	// Explicitly convert the size of the DiscardPile to an int to avoid implicit conversion
	return static_cast<int>(_cards.size());
}

// Designate how many Cards to draw from the DiscardPile
// Returns a collection of those Cards
CardCollection DiscardPile::drawUpTo(int count) 
{
	// Initialise a Collection to return
	CardCollection result;

	// Iterate through the DiscardPile up to the given/required number (count)
	for (int i = 0; i < count && !_cards.empty(); i++) 
	{
		// Transfer Cards from DiscardPile to result CardCollection
		// pop the Cards from the top of the DiscardPile (end of the vector)
		result.push_back(_cards.back());
		_cards.pop_back();
	}

	// Return the result CardCollection
	return result;
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