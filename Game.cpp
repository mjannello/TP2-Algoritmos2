#include "Game.h"

Game::Game() {

}

Board<Cell*>* Game::getBoard() {
	return this->board;
}

void Game::setBoard(int width, int large, int height) {
	this->board = new Board<Cell*>(width, large, height);

}


void Game::askBoardSize() {
	int width, large, height;
	cout << "Ingrese ancho:" << endl;
	cin >> width;
	cout << endl;
	cout << "Ingrese largo:" << endl;
	cin >> large;
	cout << endl;
	cout << "Ingrese alto:" << endl;
	cin >> height;
	cout << endl;

	this->setBoard(width, large, height);
}

void Game::askCellStateLimits() {
	int width, large, height;
	cout << "Ingrese ancho:" << endl;
	cin >> width;
	cout << endl;
	cout << "Ingrese largo:" << endl;
	cin >> large;
	cout << endl;
	cout << "Ingrese alto:" << endl;
	cin >> height;
	cout << endl;
}

void Game::setConfigOne() {
	setBoard(5, 5, 5);
	List<Cell*>* cells = new List<Cell*>();
	for (int i = 1; i <= 30; i++) {
		cells->add(new NormalCell(new CellGenes(0, 250, 0), ALIVE));
	}
	for (int i = 1; i <= 20; i++) {
		cells->add(new RadioactiveCell(new CellGenes(250, 0, 0), ALIVE));
	}
	for (int i = 1; i <= 10; i++) {
		cells->add(new NormalCell(new CellGenes(), DEAD));
	}
	for (int i = 1; i <= 25; i++) {
		cells->add(new ZombieCell(new CellGenes(0, 0, 250), ALIVE));
	}
	for (int i = 1; i <= 20; i++) {
		cells->add(new RadioactiveCell(new CellGenes(), DEAD));
	}
	for (int i = 1; i <= 10; i++) {
		cells->add(new NormalCell(new CellGenes(239, 247, 10), ALIVE));
	}
	for (int i = 1; i <= 5; i++) {
		PortalChildCell* portalChild = new PortalChildCell(new CellGenes(), ALIVE);
		PortalFatherCell* portalFather = new PortalFatherCell(portalChild, new CellGenes(), ALIVE);
		cells->add(portalChild);
		cells->add(portalFather);
	}

	this->board->fillWith(cells);
}

void Game::nextRound() {
	this->board->defineNewStates();

}