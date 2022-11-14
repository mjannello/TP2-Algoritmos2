#include "Cell.h"
#include <iostream>
#include "CellGenes.h"

using namespace std;

Cell::Cell(CellGenes* genes, CellState newState)
{
    this->genes = genes;
    this->state = newState;
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

void Cell::setBehaviour(CellBehaviour* behaviour)
{
    this->behaviour = behaviour;
}

CellGenes* Cell::getGenes()
{
    return this->genes;
}



RadioactiveCell::RadioactiveCell() : Cell() {
    this->setBehaviour(new RadiactiveBehaviour());
}


void RadioactiveCell::applyNextStateStrategy(List<Cell*>* neighboursCells) {

    for (int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }

}