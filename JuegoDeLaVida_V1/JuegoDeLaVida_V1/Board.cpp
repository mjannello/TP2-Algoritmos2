#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
	
}

Board::~Board()
{
}

Cell Board::getCell(int x, int y) {
	return this->matrix_cells[x][y];
}

void Board::setCell(int x, int y, Cell& cell) {
	this->matrix_cells[x][y] = cell;
}

Board* Board::defineNewStatus()
{
	Board* newStatusBoard = new Board();
	int neighborsAlive = 0;
	cleanBornsAndDeaths();
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLS; j++) {
			Cell currentCell = this->getCell(i, j);
			neighborsAlive = this->numberNeighborsAlive(i, j);
			Cell *nextCell = currentCell.getNextStatus(neighborsAlive);
			newStatusBoard->matrix_cells[i][j] = *nextCell;
			countBornsAndDeaths(currentCell.getState(), nextCell->getState(), i, j);
		}
	}

	return newStatusBoard;
}

int Board::numberNeighborsAlive(int x, int y) {
	int neighborsAlive = 0;
	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (i < 0 || j < 0 || i == BOARD_ROWS || j == BOARD_COLS) {
				continue;
			}
			if (i == x && j == y) {
				continue;
			}
			
			neighborsAlive += this->matrix_cells[i][j].getState();
		}
	}

	return neighborsAlive;
}

void Board::printBoard() {
	for (int i = 0; i < BOARD_ROWS; i++) {
		for (int j = 0; j < BOARD_COLS; j++) {
			cout<< this->matrix_cells[i][j].getState();
		}
		cout << '\n';
	}
}

void Board::countBornsAndDeaths(int currentCellState, int newCellState, int i, int j) {
	if (currentCellState == STATE_ALIVE && newCellState == STATE_DEAD) {
		deaths++;
	}
	if (currentCellState == STATE_DEAD && newCellState == STATE_ALIVE) {
		borns++;
	}
}

int Board::getBorns() {
	return borns;
}

int Board::getDeaths() {
	return deaths;
}

void Board::cleanBornsAndDeaths() {
	borns = 0;
	deaths = 0;
}