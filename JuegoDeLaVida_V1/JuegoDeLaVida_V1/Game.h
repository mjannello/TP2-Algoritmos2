#ifndef Game_h
#define Game_h
#include "Board.h"

class Game
{
private:
	Board *current_board;
	Board *next_board;
public:
	Game();
	~Game();
	void nextTurn();
	void setInitialCells(int, int, Cell&);
	void getCurrentBoardStatus();
	void getNextBoardStatus();
	void updateNextBoard();
};

#endif 