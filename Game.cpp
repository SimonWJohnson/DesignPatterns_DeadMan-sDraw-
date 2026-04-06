#include "Game.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

/* Concrete Cards */ 

// Constructor
Game::Game() {}

// Destructor
Game::~Game() {}

// Start the Game
void Game::start() {}

// initialise Players 
void Game::initialisePlayers() {}

// Create and populate the Deck
void Game::createDeck() {}

// Turn Flow
void Game::playTurn() {}
void Game::switchPlayer() {}

// Display Player's final score without modifying Game state 
void Game::printFinalScores() const {}

/* Accessors for Player, Deck, and DiscardPile */
// Access the current and other Player
Player& Game::currentPlayer() {}
Player& Game::otherPlayer() {}

// Access the Deck and DiscardPile
Deck& Game::deck() {}
DiscardPile& Game::discardPile() {}

// Game Tracking
// Access current turn and round numbers
int Game::turnNumber() const {}
int Game::roundNumber() const {}