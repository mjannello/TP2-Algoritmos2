#include "Lista.h"
#include "Board.h"
#include "Box.h"
#include <iostream>
#include "Cell.h"

using namespace std;

int main() {
    // Cell * cell = new Cell(ALIVE);
    int numero = 5;
    Box<int>* box = new Box<int>(numero);
    Box<int>* box2 = new Box<int>();
    cout << box->isEmpty() << endl; 
    cout << box2->isEmpty() << endl;
    // cout << box->getData() << endl;

    Board<int>* board = new Board<int>(10, 5, 4);
    board->append(numero);
    
    Box<int>* actualBox= board->getBox(1,1,1);
    
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
    
    // print all neighbours
    
    Lista<Box<int>*> * neighbours = actualBox->getAllNeighbours();
    
    for (int i = 1; i < 27; i++)
        {
        Box<int>* neighbour = neighbours->get(i);
        cout <<"x: "<< neighbour->getCoordX() << " y: " << neighbour->getCoordY()
            <<" z: " << neighbour->getCoordZ() << endl;
    }
    
    
    delete board;

    Board<int>* newBoard = new Board<int>(5, 5, 5);
    Lista<int>* elements = new Lista<int>();
    for (int i = 1; i <= 125; i++)
    {
        elements->add(i);
    }
    newBoard->fillWith(elements);
    cout <<"element in newBoard: " << newBoard->getBox(5,5,5)->getData() << endl;

    /*
    Board<Cell> * cellBoard = new Board<Cell>(3,3,3);
    cout<< "cell board: " << cellBoard->getBox(1, 1, 1) << endl;
    */
    return 0;
}