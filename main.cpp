#include "Lista.h"
#include "Board.h"
#include "Box.h"
#include <iostream>

using namespace std;

int main() {
    // Cell * cell = new Cell(ALIVE);
    int numero = 5;
    Box<int>* box = new Box<int>(numero);
    Box<int>* box2 = new Box<int>();
    cout << box->isEmpty() << endl; 
    cout << box2->isEmpty() << endl;
    // cout << box->getData() << endl;

    Board<int>* b = new Board<int>(1, 2, 3);
    b->append(numero);
    cout << b->getBox(0, 0, 0).getData() << endl;


    // Lista<Cell *> * cellsList = new Lista<Cell*>();

    // cellsList->add(cell);

    // cout << cellsList->get(1)->getState() << endl;

    // delete cell;

    return 0;
}