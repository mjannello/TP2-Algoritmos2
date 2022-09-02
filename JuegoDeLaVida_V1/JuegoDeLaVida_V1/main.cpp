#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Game.h"
#include "Juego.h"

using namespace std;

int main() {
	/*
	Game* game = new Game();
	game->printInitialMenu();
	game->updateNextBoard();
	game->printContinueMenu();
	*/
	Juego j;
	initJuego(&j);
	imprimirMenuInicial(&j);
	imprimirMenuContinuacion(&j);
	

	

	return 0;
}