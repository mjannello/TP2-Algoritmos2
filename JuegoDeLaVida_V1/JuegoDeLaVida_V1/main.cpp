#include <iostream>
#include "Cell.h"
#include "Board.h"

using namespace std;

int main() {
	Cell* c = new Cell(1);
	Board* b = new Board();
	b->setCell(0, 0, *c);
	cout << "Starting game:"<< b->getCell(0,0).getState() << endl;
	return 0;
}