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
	CellState nextState;
	CellGenes* genes;
	CellBehaviour* behaviour;
	int neighboursToBorn;
	int minNeighboursToDie;
	int maxNeighboursToDie;
public:
	int debugInt;
	Cell(CellGenes* genes = new CellGenes(), CellState newState = DEAD);
	~Cell();
	void setState(CellState newState);
	void setNextState(CellState newState);
	CellState getState();
	CellState getNextState();
	bool isAlive();
	void applyBehaviour(Cell* otherCell);
	void setBehaviour(CellBehaviour* behaviour);
	CellGenes* getGenes();
	void setGenes(CellGenes* genes);
	void defineNextState(int amountNeighboursAlive);

	int getAmountCellsAlive(List<Cell*>* cells);
	
	virtual void applyNextStateStrategy(List<Cell*>* neighboursCells) = 0;


};

class NormalCell : public Cell {
public:
	NormalCell();
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

class RadioactiveCell : public Cell {
public:
	RadioactiveCell();
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

class PortalChildCell : public Cell {
public:
	PortalChildCell();
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};


class PortalFatherCell : public Cell {
private:
	PortalChildCell* childCell;
public:
	PortalFatherCell(PortalChildCell* child);
	void setPortalChildCell(PortalChildCell* child);
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};


class ScaloCell : public Cell {
public:
	ScaloCell();
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

class ZombieCell : public Cell {
public:
	ZombieCell();
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

#endif 