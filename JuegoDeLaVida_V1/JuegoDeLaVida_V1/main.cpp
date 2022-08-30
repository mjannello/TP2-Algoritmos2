#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main() {

	Game* game = new Game();
	game->printInitialMenu();
	game->updateNextBoard();
	game->printContinueMenu();

	

	return 0;
}