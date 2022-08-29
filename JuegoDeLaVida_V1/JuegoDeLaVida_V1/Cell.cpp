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