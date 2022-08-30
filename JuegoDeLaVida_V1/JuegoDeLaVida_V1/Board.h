#ifndef Board_h
#define Board_h
#include "Cell.h"

#define BOARD_ROWS 10
#define BOARD_COLS 10

class Board
{
private:
	Cell matrix_cells[BOARD_ROWS][BOARD_COLS];
	int borns = 0;
	int deaths = 0;

public:

	Board();
	~Board();
	Cell getCell(int, int);
	void setCell(int x, int y, Cell& cell);
	Board* defineNewStatus();
	int numberNeighborsAlive(int x, int y);
	void countBornsAndDeaths(int, int);
	void printBoard();
	int getTotalCellsAlive();
	int getBorns();
	int getDeaths();
	void cleanBornsAndDeaths();
};
#endif

