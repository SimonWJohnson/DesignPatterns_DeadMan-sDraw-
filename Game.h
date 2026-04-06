#pragma once

#include <string>
#include "Deck.h"
#include "DiscardPile.h"
#include "Player.h"


/*
Responsibilities:
- Initialising the Game state
- create and shuffle the Deck ** DOes this shuffle, or does the Card class?
- control turn flow
- track the current Player and Round
*/

class Game 
{
public:
	// Constructor
	Game();

	// Destructor
	~Game();

	// Start the Game
	void start();

	// initialise Players 
	void initialisePlayers();

	// Create and populate the Deck
	void createDeck();

	// Turn Flow
	void playTurn();
	void switchPlayer();

	// Display Player's final score without modifying Game state 
	void printFinalScores() const;

	/* Accessors for Player, Deck, and DiscardPile */ 
	// Access the current and other Player
	Player& currentPlayer();
	Player& otherPlayer();

	// Access the Deck and DiscardPile
	Deck& deck();
	DiscardPile& discardPile();

	// Game Tracking
	// Access current turn and round numbers
	int turnNumber() const;
	int roundNumber() const;

private:
	Deck _deck;
	DiscardPile _discardPile;

	// Pointers to Players
	Player* _player1;
	Player* _player2;
	Player* _currentPlayer;

	int _turnNumber;
	int _roundNumber;
	// Maximum allowed turns
	// Kept private for encapsulation - an internal Game rule that should NOT be exposed
	int _maxTurns;

};