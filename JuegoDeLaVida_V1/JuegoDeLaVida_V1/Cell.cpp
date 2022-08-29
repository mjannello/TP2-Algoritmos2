#include "cell.h"

Cell::Cell()
{
	this->setState(0);

}

Cell::Cell(int state)
{
	this->setState(state);
}

Cell::~Cell()
{
}

void Cell::setState(int state)
{
	this->state = state;
}

int Cell::getState()
{
	return this->state;
}

Cell& Cell ::operator= (const Cell& b)
{
	state = b.state;
	return *this;
}

Cell* Cell::getNextStatus(int neighborsAlive) {
	//TODO: calculate cell's next state
	if (this->getState() == STATE_DEAD && neighborsAlive == 3) {
		return new Cell(STATE_ALIVE);
	}
	if (this->getState() == STATE_ALIVE && neighborsAlive != 2 && neighborsAlive != 3) {
		return new Cell(STATE_DEAD);
	}
	return this;
}