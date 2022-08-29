#ifndef Board_h
#define Board_h
#include "Cell.h"

#define BOARD_ROWS 20
#define BOARD_COLS 80

class Board
{
private:
	Cell matrix_cells[BOARD_ROWS][BOARD_COLS];
public:

	Board();
	Cell getCell(int, int);
	void setCell(int x, int y, Cell& cell);
	Board* defineNewStatus();
	int numberNeighborsAlive(int x, int y);
	void printBoard();
};
#endif

