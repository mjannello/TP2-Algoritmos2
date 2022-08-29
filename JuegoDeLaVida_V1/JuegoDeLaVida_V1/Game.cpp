#include "Game.h"
#include <iostream>
using namespace std;

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
	cout<<"Nacimientos: "<<current_board->getBorns();
	cout << "Muertes: " << current_board->getDeaths();
	Board aux = *next_board;
	current_board = next_board;
	updateNextBoard();

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
