#ifndef Board_h
#define Board_h
#include "Cell.h"

#define BOARD_ROWS 5
#define BOARD_COLS 7

class Board
{
private:
	Cell matrix_cells[BOARD_ROWS][BOARD_COLS];
public:

	Board();
	~Board();
	Cell getCell(int, int);
	void setCell(int x, int y, Cell& cell);
	Board* defineNewStatus();
	int numberNeighborsAlive(int x, int y);
	void printBoard();
};
#endif

