#include "Game.h"

Game::Game()
{
	current_board = new Board();
	updateNextBoard();
}

Game::~Game()
{
}

void Game::nextTurn()
{
	Board aux = *next_board;
	current_board = next_board;
	next_board = aux.defineNewStatus();

}

void Game::setInitialCells(int x, int y, Cell& cell) {
	current_board->setCell(x, y, cell);
	updateNextBoard();
}

void Game::getCurrentBoardStatus() {
	return this->current_board->printBoard();
}

void Game::getNextBoardStatus() {
	return this->next_board->printBoard();
}

void Game::updateNextBoard() {
	next_board = current_board->defineNewStatus();
}