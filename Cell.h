#ifndef CELL_H
#define CELL_H


#include "CellBehaviour.h"
#include "List.h"


enum CellState {
	DEAD,
	ALIVE
};

enum CellBehaviours { NORMAL, RADIOACTIVE, PORTAL, ZOMBIE, SCALOCELULA, ARIA };


class Cell
{
private:
	
	CellState state;
	CellGenes * genes;
	CellBehaviour* behaviour;

public:
	int debugInt;
	Cell(CellBehaviour* behaviour = NULL, CellGenes* genes = new CellGenes(), CellState newState = ALIVE);
	~Cell();
	void setState(CellState newState);
	CellState getState();
	bool isAlive();
	void applyBehaviour(Cell* otherCell);
	CellGenes * getGenes();
	void setGenes(CellGenes* genes);

	virtual void applyNextStateStrategy(List<Cell*>* neighboursCells)=0;


};


class RadioactiveCell : public Cell {
public:
	RadioactiveCell();
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

#endif 