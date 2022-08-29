#include "Board.h"

Board::Board() {
	
}

Cell Board::getCell(int x, int y) {
	return this->matrix_cells[x][y];
}

void Board::setCell(int x, int y, Cell& cell) {
	this->matrix_cells[x][y] = cell;
}