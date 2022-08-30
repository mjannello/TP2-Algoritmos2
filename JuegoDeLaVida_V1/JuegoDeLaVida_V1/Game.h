#ifndef Game_h
#define Game_h
#include "Board.h"

class Game
{
private:
	Board *current_board;
	Board *next_board;
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
	void updateTotalBorns();
	void updateTotalDeaths();
	void updateFreezeStatus();
	void updateTurnNumber();
	void nextTurn();

};

#endif 