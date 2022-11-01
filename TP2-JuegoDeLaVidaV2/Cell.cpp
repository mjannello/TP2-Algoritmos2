#include "Cell.h"

Cell::Cell( CellState newState)
{
    this->state = newState;
}

Cell::~Cell(){}

void Cell::setState( CellState newState )
{
    this->state = newState;
}

CellState Cell::getState()
{
    return this->state;
}

bool Cell::isAlive()
{
    return this->getState() == ALIVE ? true: false;
}