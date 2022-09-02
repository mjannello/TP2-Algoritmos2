#include <iostream>
#include "Cell.h"
#include "Board.h"
#include "Game.h"
#include "Celula.h"

using namespace std;

int main() {
	/*
	Game* game = new Game();
	game->printInitialMenu();
	game->updateNextBoard();
	game->printContinueMenu();
	*/
	Celula c;
	initCelula(&c, VIVA);
	
	cout << "El estado de la celula es: " << getEstado(&c) <<endl;
	

	

	return 0;
}