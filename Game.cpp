#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

/* Concrete Cards */ 

// Constructor
Game::Game() 
{}

// Destructor
Game::~Game() 
{}

// Start the Game
void Game::start() 
{}

// initialise Players 
void Game::initialisePlayers() 
{}

// Create and populate the Deck
void Game::createDeck() 
{}

// Turn Flow
void Game::playTurn() 
{}

void Game::switchPlayer() 
{}

// Display Player's final score without modifying Game state 
void Game::printFinalScores() const 
{}

/* Accessors for Player, Deck, and DiscardPile */
// Access the current and other Player
Player& Game::currentPlayer() 
{
	// Return a reference to the currentPlayer object
	return *_currentPlayer;
}

Player& Game::otherPlayer() 
{
	// Return a reference to the Player who is NOT currently taking their turn
	// Players are initialised at the start of the Game, but a safety check is here just in case
	if (_player1 == nullptr || _player2 == nullptr || _currentPlayer == nullptr) 
	{
		throw std::runtime_error("Players not initialised");
	}
	// If the current Player is _player1, return a reference to _player2
	// Else return a reference to _player1
	if (_currentPlayer == _player1) 
	{
		return *_player2;
	}
	else if (_currentPlayer == _player2)
	{
		return *_player1;
	}
	else 
	{
		throw std::runtime_error("Invalid current player");
	}
}

// Access the Deck and DiscardPile
Deck& Game::deck() 
{
	return _deck;
}

DiscardPile& Game::discardPile() 
{
	return _discardPile;
}

// Game Tracking
// Access current turn and round numbers
int Game::turnNumber() const 
{
	return _turnNumber;
}

int Game::roundNumber() const 
{
	return _roundNumber;
}