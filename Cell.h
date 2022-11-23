#ifndef CELL_H
#define CELL_H

#include "CellBehaviour.h"
#include "List.h"


enum CellState {
	DEAD,
	ALIVE
};

enum CellBehaviours { NORMAL, RADIOACTIVE, PORTAL, ZOMBIE, SCALOCELULA, ARIA };
enum TransitionState { NO_CHANGE, NEW_BORN, NEW_DEATH};

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
	Cell(CellGenes* genes = new CellGenes(), CellState newState = DEAD);
	~Cell();
	CellState getState();
	void setState(CellState newState);
	CellState getNextState();
	void setNextState(CellState newState);
	CellGenes* getGenes();
	void setGenes(CellGenes* genes);
	int countCellsAliveIn(List<Cell*>* cells);
	void setNeighboursToBorn(int neighboursToBorn);
	void setMinNeighboursToDie(int minNeighboursToDie);
	void setMaxNeighboursToDie(int miaxNeighboursToDie);
	bool isAlive();
	void setBehaviour(CellBehaviour* behaviour);
	void applyBehaviour(Cell* otherCell);
	void defineNextState(int amountNeighboursAlive);
	
	TransitionState switchStates();

	virtual void applyNextStateStrategy(List<Cell*>* neighboursCells) = 0;


};

class NormalCell : public Cell {
public:
	NormalCell(CellGenes* genes, CellState state);
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

class RadioactiveCell : public Cell {
public:
	RadioactiveCell(CellGenes* genes, CellState state);
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

class PortalChildCell : public Cell {
public:
	PortalChildCell(CellGenes* genes, CellState state);
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};


class PortalFatherCell : public Cell {
private:
	PortalChildCell* childCell;
public:
	PortalFatherCell(PortalChildCell* child, CellGenes* genes, CellState state);
	void setPortalChildCell(PortalChildCell* child);
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};


class ScaloCell : public Cell {
public:
	ScaloCell(CellGenes* genes, CellState state);
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

class ZombieCell : public Cell {
public:
	ZombieCell(CellGenes* genes, CellState state);
	void applyNextStateStrategy(List<Cell*>* neighboursCells);
};

#endif 