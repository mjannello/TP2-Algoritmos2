#include "Lista.h"
#include "Board.h"
#include "Box.h"
#include <iostream>
#include "Cell.h"

using namespace std;

int main() {
    /*
    // Cell * cell = new Cell(ALIVE);
    int numero = 5;
    Box<int>* box = new Box<int>(numero);
    Box<int>* box2 = new Box<int>();
    cout << box->isEmpty() << endl;
    cout << box2->isEmpty() << endl;
    // cout << box->getData() << endl;

    Board<int>* board = new Board<int>(3,3,3);
    
    for (int i = 1; i < 27; i++)
    {
        board->append(i);
    }
    
    for (int x = 1; x <= board->getWidth(); x++) {
        for (int y = 1; y <= board->getLength(); y++) {
            for (int z = 1; z <= board->getHeight(); z++) {
                Box<int>* actualBox = board->getBox(x, y, z);
                cout << "x: "
                    << actualBox->getCoordX()
                    << " y: "
                    << actualBox->getCoordY()
                    << " z: "
                    << actualBox->getCoordZ() << endl;

            }
        }
    }

    

    delete board;*/
    int lado = 3;
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
    cout <<"element in newBoard: " << newBoard->getBox(1,2,1)->getData()->debugInt << endl;
    
    /*
    Board<Cell> * cellBoard = new Board<Cell>(3,3,3);
    cout<< "cell board: " << cellBoard->getBox(1, 1, 1) << endl;
    
    return 0;
    */
}