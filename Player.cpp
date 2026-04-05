#include "Player.h"
#include "Game.h"
#include <iostream> // std::cout, std::endl in print functions
#include <map> // std::map - count card types and track card values
#include <algorithm> // std::count_if used in playCard()

// Constructor
Player::Player(const std::string& name) : _name(name)
{}

// Destructor
// Cards (or their pointers) NOT deleted here - this should be handled by Game or Collections
Player::~Player() {}

// Getter
// returns Player name as a const reference
const std::string& Player::name() const 
{
	return _name;
}

// Play Card and check for bust condition
bool Player::playCard(Card* card, Game& game) 
{
	// Add the Card to the Player's play area
	addToPlayArea(card);

	// Consditional check for Card drawn
	// If there is now more than 1 card of the same type/suit in the play area, the Player busts and the function returns True
	if (hasSuitInPlayArea(card->type()) && std::count_if(_playArea.begin(), _playArea.end(), [card](Card* c) {return c->type(); }) > 1)
	{
		// Bust
		return true;
	}

	// If Player has not bust, trigger the Card's special ability
	card->play(game, *this);

	// If Player is NOT bust, return False
	return false;
}

