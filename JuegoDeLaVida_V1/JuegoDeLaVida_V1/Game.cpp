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


void  Game::printInitialMenu() {
	int numberCells, row, col;
	cout << "Ingrese la cantidad de celulas que desea ingresar" << endl;
	cin >> numberCells;
	//TODO: validate is int
	for (int i = 0; i < numberCells; i++) {
		cout << "Celula " << i + 1 << endl;
		cout<< "Fila: " << endl;
		cin >> row;
		cout << "Columna: " << endl;
		cin >> col;
		Cell* c = new Cell(STATE_ALIVE);
		current_board->setCell(row, col, *c);
	}
	getCurrentBoardStatus();
	
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
	updateLastTurnBorns();
	updateLastTurnDeaths();
	current_board = next_board;
	showGameStatus();
	updateNextBoard();
}
void Game::updateLastTurnBorns() {
	lastTurnBorns = current_board->getBorns();
}
void Game::updateLastTurnDeaths() {
	lastTurnDeaths = current_board->getDeaths();
}
void Game::showGameStatus() {

	getCurrentBoardStatus();
	cout << "Celulas vivas: "<< current_board->getTotalCellsAlive() << endl;
	cout << "Nacimientos: " << lastTurnBorns << endl;
	cout << "Muertes: " << lastTurnDeaths << endl;
	cout << "Promedio de Nacimientos: " << totalBorns / turnNumber << endl;
	cout << "Promedio de Muertes: " << totalDeaths / turnNumber << endl;

	string gameFreezedString = gameIsFreezed ? "si" : "no";
	cout << "Juego congelado: " << gameFreezedString << endl;
}

void Game::printContinueMenu() {
	int input;
	cout << "1.Ejecutar un turno" << endl;
	cout << "2.Reiniciar juego" << endl;
	cout << "3.Terminar juego" << endl;

	cin >> input;

	switch (input)
	{
	case 1:
		nextTurn();
		//showGameStatus();
		printContinueMenu();
		break;
	case 2:
		current_board = new Board();
		updateNextBoard();
		printInitialMenu();
		printContinueMenu();
		break;
	case 3:
		cout << "Juego terminado!"<<endl;
		break;
	default:
		break;
	}

}