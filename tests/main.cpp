#include "Lista.h"
#include "Board.h"
#include "Box.h"
#include <iostream>
#include "Cell.h"

using namespace std;

int main() {
    int lado = 7;

    Board<Cell*>* newBoard = new Board<Cell*>(lado, lado, lado);
    Lista<Cell*>* elements = new Lista<Cell*>();
    for (int i = 1; i <= lado*lado*lado; i++)
    {
        Cell* cell = new Cell(ALIVE);
        cell->debugInt = i;
        elements->add(cell);
    }
    newBoard->fillWith(elements);
    newBoard->defineNewStates();
    cout <<"element in newBoard: " << newBoard->getBox(1,1,1)->getData()->debugInt << endl;

    /*
    Board<Cell> * cellBoard = new Board<Cell>(3,3,3);
    cout<< "cell board: " << cellBoard->getBox(1, 1, 1) << endl;
    */
    return 0;
}