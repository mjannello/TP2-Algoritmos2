#ifndef Game_h
#define Game_h
#include "Board.h"

class Game
{
private:
	Board *current_board;
	Board *next_board;
	int lastTurnBorns = 0;
	int lastTurnDeaths = 0;
	bool gameIsFreezed = false;
	int turnsFreezed = 0;
	int turnNumber = 1;
	int totalBorns = 0;
	int totalDeaths = 0;

public:
	Game();
	~Game();
	void setInitialCells(int, int, Cell&);
	void getCurrentBoardStatus();
	void getNextBoardStatus();
	void updateNextBoard();
	void showGameStatus();
	void updateLastTurnBorns();
	void updateLastTurnDeaths();
	void updateTotalBorns();
	void updateTotalDeaths();
	void updateFreezeStatus();
	void updateTurnNumber();
	void nextTurn();
	void printInitialMenu();
	void printContinueMenu();

};

#endif 