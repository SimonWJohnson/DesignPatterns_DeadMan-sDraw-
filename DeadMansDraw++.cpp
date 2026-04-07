// DeadMansDraw++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Game.h"
#include "game_title.h"

int main()
{
	// ASCII Game Title at startup
	std::cout << GAME_TITLE;
	std::cout << "\n\n";
	Game game;
	game.start();
	return 0;
}

