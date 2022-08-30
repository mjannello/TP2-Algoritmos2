#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main() {
	Cell* c = new Cell(1);

	Game* game = new Game();
	
	//game->setInitialCells(0,0, *c);
	/*
	game->setInitialCells(2, 3, *c);
	game->setInitialCells(2, 4, *c);
	game->setInitialCells(2, 5, *c);
	*/
	game->printInitialMenu();
	game->updateNextBoard();
	game->printContinueMenu();

	

	return 0;
}