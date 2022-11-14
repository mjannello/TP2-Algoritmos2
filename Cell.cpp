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

void Cell::setGenes(CellGenes* genes)
{
    this->genes = genes;
}

void Cell::defineNextState(int amountNeighboursAlive) {
    if (this->state == DEAD && amountNeighboursAlive == neighboursToBorn) {
        this->nextState = ALIVE;
    }
    if (this->state == ALIVE) {
        if (minNeighboursToDie > amountNeighboursAlive || amountNeighboursAlive > maxNeighboursToDie) {
            this->nextState = DEAD;
        }
    }
}

int Cell::getAmountCellsAlive(List<Cell*>* cells) {
    int cellsAlive = 0;
    for (unsigned int i = 1; i <= cells->countElements(); i++)
    {
        if (cells->get(i)->isAlive()) {
            cellsAlive++;
        }
    }
    return cellsAlive;
}


RadioactiveCell::RadioactiveCell() : Cell() {
    this->setBehaviour(new RadiactiveBehaviour());
}


void RadioactiveCell::applyNextStateStrategy(List<Cell*>* neighboursCells) {
    // evaluar mi proximo estado
    defineNextState(getAmountCellsAlive(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }

}

PortalFatherCell::PortalFatherCell(PortalChildCell* child) : Cell() {
    this->setBehaviour(new PortalBehaviour());
    this->setPortalChildCell(child);
}

void PortalFatherCell::setPortalChildCell(PortalChildCell* child)
{
    this->childCell = child;
}

void PortalFatherCell::applyNextStateStrategy(List<Cell*>* neighboursCells) {
    // evaluar mi proximo estado
    defineNextState(getAmountCellsAlive(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }
    this->childCell->setNextState(this->getNextState());
    this->childCell->setGenes(this->getGenes());
}

PortalChildCell::PortalChildCell() : Cell() {
    this->setBehaviour(new PortalBehaviour());
}

void PortalChildCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
}

ScaloCell::ScaloCell() : Cell() {
    this->setBehaviour(new ScaloCellBehaviour());
}

void ScaloCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
    this->setNextState(ALIVE);
    for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }

}

ZombieCell::ZombieCell() : Cell() {
    this->setBehaviour(new ZombieBehaviour());
}

void ZombieCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
    // evaluar mi proximo estado
    defineNextState(getAmountCellsAlive(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }
}

NormalCell::NormalCell() : Cell() {
    this->setBehaviour(new NormalBehaviour());
}

void NormalCell::applyNextStateStrategy(List<Cell*>* neighboursCells)
{
    // evaluar mi proximo estado
    defineNextState(getAmountCellsAlive(neighboursCells));
    //aplicarme los comportamientos de mis vecinos
    for (unsigned int i = 1; i <= neighboursCells->countElements(); i++)
    {
        Cell* neighbourCell = neighboursCells->get(i);
        neighbourCell->applyBehaviour(this);
    }
}