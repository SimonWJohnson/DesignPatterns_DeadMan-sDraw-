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

/* Getters */
// returns Player name as a const reference
const std::string& Player::name() const 
{
	return _name;
}

// Returns _bank Collection
const CardCollection& Player::bank() const
{
	return _bank;
}

// Returns _playArea Collection
const CardCollection& Player::playArea() const 
{
	return _playArea;
}

// Conditional checks for _bank and _playArea state
// Returns True if _bank / _playArea are empty
bool Player::bankEmpty() const 
{
	return _bank.empty();
}

bool Player::playAreaEmpty() const
{
	return _playArea.empty();
}

/* Print / Display */
// Print Player's current _playArea
void Player::printPlayArea() const 
{
	// Print Player's name
	std::cout << _name << "'s Play Area:" << std::endl;

	// Print each Card's string representation
	for (Card* card : _playArea) 
	{
		std::cout << card->str() << std::endl;
	}
}

// Print Player's current _bank ** should this function print Player Score as well?
void Player::printBank() const 
{
	std::cout << _name << "'s Bank:" << std::endl;

	// Print each card in the Bank
	for (Card* card : _bank) 
	{
		std::cout << card->str() << std::endl;
	}
}

/* Add Card to _playArea and _bank */
void Player::addToPlayArea(Card* card) 
{
	_playArea.push_back(card);
}

void Player::addToBank(Card* card) 
{
	_bank.push_back(card);
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

// Check if a given Card suit/type exists in the play area
