#include "List.h"
#include "Board.h"
#include "Box.h"
#include "Cell.h"
#include "Game.h"
#include "EasyBMP.h"

#include <string>
#include <iostream>

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
    Board<Cell*>* newBoard = new Board<Cell*>(lado, lado, 4);
    List<Cell*>* elements = new List<Cell*>();
    for (unsigned int i = 1; i <= newBoard->countAllBoxes() - 5; i++)
    {
        Cell* cell = new NormalCell(new CellGenes(), ALIVE);
        elements->add(cell);
    }
    for (unsigned int i = 1; i <= 5; i++)
    {
        Cell* cell = new NormalCell(new CellGenes(), DEAD);
        elements->add(cell);
    }

    newBoard->fillWith(elements);
    /*
    int* genes = newBoard->getBox(1, 1, 1)->getData()->getGenes()->getGenesValues();
    cout << "element in newBoard: " << genes[0]<< genes[1]<< genes[2] << endl;
    newBoard->defineNewStates();
    genes = newBoard->getBox(1, 1, 1)->getData()->getGenes()->getGenesValues();
    cout << "element in newBoard: " << genes[0] << genes[1] << genes[2] << endl;
    */
    Game* game = new Game();
    game->setConfigTwo();
    game->nextRound();
    int* genes = game->getBoard()->getBox(1, 1, 1)->getData()->getGenes()->getGenesValues();
    cout << "element in game board: " << genes[0] << genes[1] << genes[2] << endl;

    BMP AnImage;
    // Set size to 640 × 480
    AnImage.SetSize(1024, 768);
    // Set its color depth to 8-bits
    AnImage.SetBitDepth(16);


    for (int i = 1; i <= game->getBoard()->getWidth(); i++) {
        for (int k = 1; k <= game->getBoard()->getLength(); k++) {
            for (int j = 1; j <= game->getBoard()->getHeight(); j++) {
                int* genes = game->getBoard()->getBox(i, j, k)->getData()->getGenes()->getGenesValues();
                //AnImage(i, j)->Red = genes[0];
                //AnImage(i, j)->Green = genes[1];
                //AnImage(i, j)->Blue = genes[2];
                RGBApixel NewColor;
                NewColor.Red = genes[0];
                NewColor.Green = genes[1];
                NewColor.Blue = genes[2];

                RGBApixel White;
                White.Red = 255;
                White.Green = 255;
                White.Blue = 255;

                for (int l = 0; l < 100; l++) {
                    for (int m = 0; m < 100; m++) {
                        if (m == 0 || l == 0 || m == 99 || l == 99) {
                            AnImage.SetPixel(j * 100, k * 100, White);
                        }
                        else {
                            AnImage.SetPixel(j * 100 + l, k * 100 + m, NewColor);
                        }

                    }
                }

                string fileNameStr = "Imagen" + to_string(i) + ".bmp";
                const char* fileName = fileNameStr.c_str();

                AnImage.WriteToFile(fileName);

            }
        }
    }

    /*
    Board<Cell> * cellBoard = new Board<Cell>(3,3,3);
    cout<< "cell board: " << cellBoard->getBox(1, 1, 1) << endl;

    return 0;
    */
}