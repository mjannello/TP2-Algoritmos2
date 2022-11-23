#ifndef GAME_H
#define GAME_H

#include "EasyBMP.h"
#include "Board.h"
#include "Cell.h"

enum initializationOptions
{
	MANUAL,
	CONFIG_ONE,
	CONFIG_TWO,
	CONFIG_THREE
};

enum gameOptions
{
	NEXT_ROUND,
	RESTART,
	END_GAME
};

class Game
{
private:
	Board<Cell*>* board;
	int round;
	int cellsBornLastRound;
	int cellsDiedLastRound;
	int totalCellsBorn;
	int totalCellsDied;
	float meanBirths;
	float meanDeaths;
	int roundsFrozen;
	bool gameChangedLastRound;
	bool gameChangedThisRound;
	bool isGameFrozen;
	bool ongoingGame;

public:
	Game();
	~Game();
	void askBoardSize();
	Board<Cell*>* getBoard();
	void setBoard(int width, int large, int height);
	void initializeGame();
	void nextRound();

	void showInitializationMenu();			 // Muestra el menú para la inicialización del tablero
	void showManualInitializationMenu(); // Muestra el menú para la inicialización manual del tablero
	void showOptionsMenu();							 // Muestra el menú con las opciones del juego
	void printBoard();
	void printStatistics();
	
	void askInitialCellsAlive();
	void askPositionForSingleCellAlive();
	void askPositionForAllCellsAlive();
	void endGame();
	void showEndingGameMessage();
	void showGameStatus();
	int countCellsAlive();
	void cleanLastTransitions();
	void updateCellsStates();
	void countTransitions(TransitionState transition);
	void updateFrozenState();
	void updateTotalTransitions();
	void setConfigOne();
	void setConfigTwo();
	void setConfigThree();
};

#endif
