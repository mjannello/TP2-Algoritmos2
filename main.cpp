// #include "Cell.h"
#include "Lista.h"
#include "Board.h"
#include <iostream>

using namespace std;

int main() {
    // Cell * cell = new Cell(ALIVE);
    int numero = 5;
    // Box<int> * box = new Box(numero);
    // cout << box->getData() << endl;

    Board<int>* b = new Board<int>(1, 2, 3);


    // Lista<Cell *> * cellsList = new Lista<Cell*>();

    // cellsList->add(cell);

    // cout << cellsList->get(1)->getState() << endl;

    // delete cell;

    return 0;
}