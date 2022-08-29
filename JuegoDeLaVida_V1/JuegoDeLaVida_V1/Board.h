#ifndef Board_h
#define Board_h
#include "Cell.h"

class Board
{
private:
	Cell matrix_cells[80][20];
public:

	Board();
	Cell getCell(int, int);
	void setCell(int x, int y, Cell& cell);
};
#endif

