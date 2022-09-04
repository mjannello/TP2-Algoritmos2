#include <iostream>
#include "Game.h"

using namespace std;

int main_poo() {
	Game * game = new Game();
	game->printInitialMenu();
	game->updateNextBoard();
	game->printContinueMenu();

	return 0;
}