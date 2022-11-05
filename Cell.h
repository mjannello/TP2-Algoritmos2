#ifndef CELL_H
#define CELL_H
class Cell
{
private:
	enum State {
		ALIVE = 0,
		DEATH = 1,
		WILL_BORN = 2,
		WILL_DIE = 3
	};
	/*
	CellBehaviour behaviour;
	Gen genA;
	Gen genB;
	Gen genC;
	*/
public:
	Cell();
	~Cell();
};	

#endif


