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

    Board<int>* board = new Board<int>(3, 3, 3);
    board->append(numero);
    
    Box<int>* actualBox= board->getBox(3,3,3);
    
    cout << actualBox->getData() << endl;
    /*
    cout << "x: " 
        << actualBox->getCoordX() 
        << " y: " 
        << actualBox->getCoordY() 
        << " z: " 
        << actualBox->getCoordZ() << endl;
        */
    cout << actualBox->getAllNeighbours()->contarElementos() << endl;
    
    
    Lista<Box<int>*> * neighbours = actualBox->getAllNeighbours();
    
    for (int i = 1; i < 26; i++)
        {
        Box<int>* neighbour = neighbours->get(i);
        cout <<"x: "<< neighbour->getCoordX() << " y: " << neighbour->getCoordY()
            <<" z: " << neighbour->getCoordZ() << endl;
    }
    
    

    delete board;
    // Lista<Cell *> * cellsList = new Lista<Cell*>();

    // cellsList->add(cell);

    // cout << cellsList->get(1)->getState() << endl;

    // delete cell;

    return 0;
}