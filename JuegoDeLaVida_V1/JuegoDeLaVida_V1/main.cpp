#include <iostream>
#include "Cell.h"
#include "Board.h"

using namespace std;

int main() {
	Cell* c = new Cell(1);
	Board* b = new Board();
	b->setCell(2, 3, *c);
	b->setCell(2, 4, *c);
	b->setCell(2, 5, *c);
	cout << "Starting game:"<< b->getCell(0,0).getState() << endl;
	b->printBoard();
	Board* new_b = b->defineNewStatus();
	cout << '\n';
	new_b->printBoard();
	return 0;
}