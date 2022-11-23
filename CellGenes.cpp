#include "CellGenes.h"
#include <iostream>
using namespace std;

CellGenes::CellGenes() {
    int genes[3] = { 100,100,100 };
    setGenesValues(genes);
}

CellGenes::~CellGenes() {}

CellGenes::CellGenes(int genes[]) {
    setGenesValues(genes);
}

CellGenes::CellGenes(int red, int green, int blue) {
    int genes[3] = { red, green, blue };
    setGenesValues(genes);
}

void CellGenes::setGenesValues(int gen[]) {

    for (int i = 0; i < this->GENES_QUANTITY; i++) {
        this->genes[i] = gen[i];
    }
}

int* CellGenes::getGenesValues() {
    return this->genes;
}

int  CellGenes::getGenesCount() {
    return this->GENES_QUANTITY;
}