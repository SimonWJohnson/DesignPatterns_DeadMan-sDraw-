#include "KeyCard.h"
#include "Player.h"
#include "Game.h"

#include <iostream>

// Constructor
KeyCard::KeyCard(int pointValue)
	: Card(CardType::Key, pointValue)
{}

std::string KeyCard::str() const
{
	return "Key(" + std::to_string(_pointValue) + ")";
}

// Key has no immediate effect when drawn
void KeyCard::play(Game& game, Player& player)
{
	std::cout << "Key has no effect unless banked with a Chest" << std::endl;
}

// Key does not trigger the effect itself
// Chest handles Chest / Key banking effect to avoid the effect being triggererd twice
void KeyCard::willAddToBank(Game& game, Player& player)
{
	// Psuedocode
	// Check _playArea to see if ChestCard is present
	// IF no Chest is present, return
	// Else...
}