#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Game.h"

using namespace std;

int main() {
	Cell* c = new Cell(1);
	/*
	Board* b = new Board();
	b->setCell(2, 3, *c);
	b->setCell(2, 4, *c);
	b->setCell(2, 5, *c);
	cout << "Starting game:"<< b->getCell(0,0).getState() << endl;
	b->printBoard();
	Board* new_b = b->defineNewStatus();
	cout << '\n';
	new_b->printBoard();
	*/
	Game* game = new Game();
	game->setInitialCells(2, 3, *c);
	game->setInitialCells(2, 4, *c);
	game->setInitialCells(2, 5, *c);
	game->getCurrentBoardStatus();
	game->getNextBoardStatus();
	game->nextTurn();
	cout << '\n';
	game->getCurrentBoardStatus();
	game->getNextBoardStatus();
	return 0;
}