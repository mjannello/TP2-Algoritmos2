#include "Cell.h"
#include "Lista.h"
#include <iostream>

using namespace std;

int main() {
    Cell * cell = new Cell(ALIVE);

    Lista<Cell *> * cellsList = new Lista<Cell*>();

    cellsList->add(cell);

    cout << cellsList->get(1)->getState() << endl;

    delete cell;

    return 0;
}