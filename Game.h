#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "Cell.h"

class Game {
private:
	Board<Cell*>* board;
public:
	Game();
	~Game();
	void askBoardSize();
	Board<Cell*>* getBoard();
	void setBoard(int width, int large, int height);
	void askCellStateLimits();
	void nextRound();

	void setConfigOne();
	void setConfigTwo();

};

#endif
