#include "Cell.h"

#include <iostream>
using namespace std;

Cell::Cell(CellBehaviour* behaviour, CellGenes* genes, CellState newState)
{
    this->genes = genes;
    this->state = newState;
    this->behaviour = behaviour;
}

Cell::~Cell() {}

void Cell::setState(CellState newState)
{
    this->state = newState;
}

CellState Cell::getState()
{
    return this->state;
}

bool Cell::isAlive()
{
    return this->getState() == ALIVE ? true : false;
}

void Cell::applyBehaviour(Cell* otherCell) {
   // otherCell->debugInt++;
    this->behaviour->apply(this->genes, otherCell->genes);
}



RadioactiveCell::RadioactiveCell(): Cell(new RadiactiveBehaviour()) {
}


void RadioactiveCell::applyNextStateStrategy(List<Cell*>* neighboursCells) {

    for (int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }
    
}