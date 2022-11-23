#include "Cell.h"
#include "CellGenes.h"


Cell::Cell(CellGenes* genes, CellState newState)
{
    this->genes = genes;
    this->state = newState;
    this->nextState = newState;

    this->neighboursToBorn = 5;
    this->minNeighboursToDie = 1;
    this->maxNeighboursToDie = 20;
}

Cell::Cell(CellState newState)
{
    this->state = newState;
    this->nextState = newState;

    this->neighboursToBorn = 5;
    this->minNeighboursToDie = 1;
    this->maxNeighboursToDie = 20;
}

Cell::~Cell() {}

void Cell::setState(CellState newState)
{
    this->state = newState;
}

void Cell::setNextState(CellState newState)
{
    this->nextState = newState;
}

CellState Cell::getState()
{
    return this->state;
}

CellState Cell::getNextState()
{
    return this->nextState;
}

bool Cell::isAlive()
{
    return this->getState() == ALIVE ? true : false;
}

void Cell::applyBehaviour(Cell* otherCell) {
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

void Cell::setGenes(CellGenes* genes)
{
    this->genes = genes;
}

void Cell::defineNextState(int amountNeighboursAlive) {
    if (this->state == DEAD && amountNeighboursAlive == neighboursToBorn) {
        this->nextState = ALIVE;
    }
    if (this->state == ALIVE) {
        if (minNeighboursToDie <= amountNeighboursAlive && amountNeighboursAlive <= maxNeighboursToDie) {
            this->nextState = DEAD;
        }
    }
}

int Cell::countCellsAliveIn(List<Cell*>* cells) {
    int cellsAlive = 0;
    for (unsigned int i = 1; i <= cells->countElements(); i++)
    {
        if (cells->get(i)->isAlive()) {
            cellsAlive++;
        }
    }
    return cellsAlive;
}

void Cell::setNeighboursToBorn(int neighboursToBorn) { this->neighboursToBorn = neighboursToBorn; }
void Cell::setMinNeighboursToDie(int minNeighboursToDie) { this->minNeighboursToDie = minNeighboursToDie; }
void Cell::setMaxNeighboursToDie(int miaxNeighboursToDie) { this->maxNeighboursToDie = maxNeighboursToDie; }

TransitionState Cell::switchStates() {
    
    TransitionState transition = NO_CHANGE;
    if (this->state == ALIVE && this->nextState == DEAD) {
        transition = NEW_DEATH;
    }
    if (this->state == DEAD && this->nextState == ALIVE) {
        transition = NEW_BORN;
    }
    this->state = this->nextState;
    return transition;

}
   


RadioactiveCell::RadioactiveCell(CellState state) : Cell(state) {
    this->setGenes(new CellGenes(255, 0, 0));
    this->setBehaviour(new RadiactiveBehaviour());
}


void RadioactiveCell::applyNextStateStrategy(List<Cell*>* neighboursCells) {
    // evaluar mi proximo estado
    defineNextState(countCellsAliveIn(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }

}

PortalFatherCell::PortalFatherCell(PortalChildCell* child,CellState state) : Cell(state) {
    this->setGenes(new CellGenes(0, 0, 255));
    this->setBehaviour(new PortalBehaviour());
    this->setPortalChildCell(child);
}

void PortalFatherCell::setPortalChildCell(PortalChildCell* child)
{
    this->childCell = child;
}

void PortalFatherCell::applyNextStateStrategy(List<Cell*>* neighboursCells) {
    // evaluar mi proximo estado
    defineNextState(countCellsAliveIn(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    if (this->getNextState() == ALIVE) {
        for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
        {
            Cell* neighbourCell = neighboursCells->get(i);
            neighbourCell->applyBehaviour(this);
        }
    }
    this->childCell->setNextState(this->getNextState());
    this->childCell->setGenes(this->getGenes());
}

PortalChildCell::PortalChildCell(CellState state) : Cell(state) {
    this->setGenes(new CellGenes(0, 255, 255));
    this->setBehaviour(new PortalBehaviour());
}

void PortalChildCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
    // don't have any particular next state strategy. It reflects whatever happens to its father
}

ScaloCell::ScaloCell(CellState state) : Cell(state) {
    this->setGenes(new CellGenes(0, 255, 0));
    this->setBehaviour(new ScaloCellBehaviour());
}

void ScaloCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
    this->setNextState(ALIVE);
    if (this->getNextState() == ALIVE) {
        for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
        {
            Cell* neighbourCell = neighboursCells->get(i);
            neighbourCell->applyBehaviour(this);
        }
    }

}

ZombieCell::ZombieCell(CellState state) : Cell(state) {
    this->setGenes(new CellGenes(0, 0, 0));
    this->setBehaviour(new ZombieBehaviour());
}

void ZombieCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
    // evaluar mi proximo estado
    defineNextState(countCellsAliveIn(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    if (this->getNextState() == ALIVE) {
        for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
        {
            Cell* neighbourCell = neighboursCells->get(i);
            neighbourCell->applyBehaviour(this);
        }
    }
}

NormalCell::NormalCell(CellState state) : Cell(state) {
    this->setGenes(new CellGenes(255, 255, 0));
    this->setBehaviour(new NormalBehaviour());
}

void NormalCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
    // evaluar mi proximo estado
    defineNextState(countCellsAliveIn(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    if (this->getNextState() == ALIVE) {
        for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
        {
            Cell* neighbourCell = neighboursCells->get(i);
            neighbourCell->applyBehaviour(this);
        }
    }
}