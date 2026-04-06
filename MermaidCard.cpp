#include "MermaidCard.h"

#include <iostream>

// Constructor
MermaidCard::MermaidCard(int pointValue) 
	: Card(CardType::Mermaid, pointValue) 
{}

std::string MermaidCard::str() const 
{
	return "Mermaid(" + std::to_string(_pointValue) + ")";
}

void MermaidCard::play(Game& game, Player& player) 
{
	std::cout << "No ability but the cards have a higher point value" << std::endl;
}