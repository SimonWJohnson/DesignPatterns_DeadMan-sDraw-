#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

/* Concrete Cards */ 
// Add Concrete Cards inclusions here **
#include "CannonCard.h"
#include "ChestCard.h"
#include "KeyCard.h"
#include "SwordCard.h"
#include "HookCard.h"
#include "OracleCard.h"
#include "MapCard.h"
#include "KrakenCard.h"
#include "MermaidCard.h"


// Constructor
Game::Game() 
	// Member initialiser list:
	// Set Player pointer to nullptr - no Player exists yet
	// Start Turn and ROund counters at 1
	// Set the _maxTurns (max turns allowed in the Game)
	: _player1(nullptr), _player2(nullptr), _currentPlayer(nullptr), _turnNumber(1), _roundNumber(1), _maxTurns(20)
{
	// Random number generator to produce different random names each time the Game runs - uses the current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

// Destructor
Game::~Game() 
{
	// Free dynamically allocated Player objects to avoid memory leaks
	delete _player1;
	delete _player2;
}

// Start the Game
void Game::start() 
{}

// initialise Players 
void Game::initialisePlayers() 
{
	// Array of possible Player names
	std::string names[] = { "Sam","Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge" };

	// Create two Players dynamically using random names
	// std::rand() % 10 gives a random index from 0 to 9
	_player1 = new Player(names[std::rand() % 10]);
	_player2 = new Player(names[std::rand() % 10]);

	// Set _player1 to take the first turn
	_currentPlayer = _player1;
}

// Create and populate the Deck
void Game::createDeck() 
{
	// For values 2 to 7, a Card of each Tpye is added
	for (int value = 2; value <= 7; ++value) 
	{
		_deck.addCard(new CannonCard(value));
		_deck.addCard(new ChestCard(value));
		_deck.addCard(new KeyCard(value));
		_deck.addCard(new SwordCard(value));
		_deck.addCard(new HookCard(value));
		_deck.addCard(new OracleCard(value));
		_deck.addCard(new MapCard(value));
		_deck.addCard(new KrakenCard(value));
	}

	// Add Mermaid Cards with value from 4 to 9
	for (int value = 4; value <=9; ++value) 
	{
		_deck.addCard(new MermaidCard(value));
	}
}

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