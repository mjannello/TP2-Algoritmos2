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

void Game::updateTotalBorns() {
	totalBorns += current_board->getBorns();
}

void Game::updateTotalDeaths() {
	totalDeaths += current_board->getDeaths();
}

void Game::updateFreezeStatus() {
	int lastTurnBorns = current_board->getBorns();
	int lastTurnDeaths = current_board->getDeaths();
	if (lastTurnBorns == 0 && lastTurnDeaths == 0) {
		turnsFreezed += 1;
		if (turnsFreezed >= 2) {
			gameIsFreezed = true;
		}
	}
	else {
		turnsFreezed = 0;
		gameIsFreezed = false;
	}

}

void Game::updateTurnNumber() {
	turnNumber++;
}

void Game::nextTurn()
{
	updateTotalBorns();
	updateTotalDeaths();
	updateFreezeStatus();
	updateTurnNumber();
	/*
	cout<<"Nacimientos: "<<current_board->getBorns();
	cout << "Muertes: " << current_board->getDeaths();
	*/
	current_board = next_board;
	showGameStatus();
	updateNextBoard();
}

void Game::showGameStatus() {
	int lastTurnBorns = current_board->getBorns();
	int lastTurnDeaths = current_board->getDeaths();
	getCurrentBoardStatus();
	cout << "Celulas vivas: "<< current_board->getTotalCellsAlive() << endl;
	cout << "Nacimientos: " << lastTurnBorns << endl;
	cout << "Muertes: " << lastTurnDeaths << endl;
	if (totalBorns !=0){
		cout << "Promedio de Nacimientos: " << lastTurnBorns / totalBorns << endl;
	}
	else {
		cout << "Promedio de Nacimientos: 0" << endl;
	}
	if (totalDeaths != 0) {
		cout << "Promedio de Muertes: " << lastTurnDeaths / totalDeaths << endl;
	}
	else {
		cout << "Promedio de Muertes: 0" << endl;
	}

	string gameFreezedString = gameIsFreezed ? "si" : "no";
	cout << "Juego congelado: " << gameFreezedString << endl;
}