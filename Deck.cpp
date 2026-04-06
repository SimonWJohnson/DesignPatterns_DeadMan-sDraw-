#include "Deck.h"
#include <algorithm> // used for std::shuffle
#include <random> // used for shuffle function

/* Deck is the container that manages ordering of Cards, so shuffle() belongs here! */

// Constructor
// Deck is initialised empty by default
Deck::Deck() 
{
}

// Deconstructor
Deck::~Deck() 
{
	// Iterate through CardCollection _cards
	for (Card* card : _cards) 
	{
		// Delete each dynamically allocated Card
		// Deck is taking ownership of Card pointers here**
		delete card;
	}
}

/* Add a Card to the Deck */ 
void Deck::addCard(Card* card) 
{
	// Add a Card pointer to the end of the vector (CardCollection _cards)
	_cards.push_back(card);
}

/* Shuffle the Deck */
void Deck::shuffle() 
{
	std::shuffle(
		_cards.begin(),
		_cards.end(),
		std::mt19937{ std::random_device{}() }
	);
}

/* Draw the top Card from the Deck */
Card* Deck::draw() 
{
	// Check if the vector contains any Cards
	if (_cards.empty()) 
	{
		// No Cards, nothing to return
		return nullptr;
	}

	// If Cards are in the Deck, get the last Card in the vector / top of the Deck
	Card* top = _cards.back();

	// Remove the Card from the Deck
	_cards.pop_back();

	// Return the Drawn Card
	return top;
}

// Check if the Deck is empty
bool Deck::empty() const
{
	return _cards.empty();
}

// Get the number of Cards in hte DEck
int Deck::size() const
{
	// Convert size_t to int to avoid type mismatch
	return static_cast<int>(_cards.size());
}

// Check the Card at the top of the Deck without removing it
Card* Deck::peekTop() const 
{
	// Check to see if the Deck is empty first
	if (_cards.empty()) 
	{
		// No Card to check
		return nullptr;
	}

	// return the top Card without removing it
	return _cards.back();
}

