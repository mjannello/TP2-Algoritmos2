#include "Cell.h"
//#include "Tablero.cpp"
//#include "Lista.h"
//#include "Lista.cpp"
#include <iostream>

using namespace std;

int main() {
    Cell * cell = new Cell(ALIVE);

    cout << cell->getState() << endl;

    delete cell;

    return 0;
}