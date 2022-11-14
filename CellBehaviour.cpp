
#include "CellBehaviour.h"
#include <iostream>
using namespace std;


void CellBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {}


void RadiactiveBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {
    int* _genes = childGenes->getGenesValues();
    _genes[0] = _genes[0] / 2;
    cout << _genes[0];
    childGenes->setGenesValues(_genes);

}


void AryanBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {

    int* _fatherGenes = fatherGenes->getGenesValues();
    int* _childGenes = childGenes->getGenesValues();
    int indexMaximumGen = 0;
    int maxGen = 0;

    for (int i = 0; i < fatherGenes->getGenesCount(); i++) {
        if (_fatherGenes[i] > maxGen) {
            indexMaximumGen = i;
            maxGen = _fatherGenes[i];
        }
    }

    _childGenes[indexMaximumGen] = maxGen;
    childGenes->setGenesValues(_childGenes);
}

void NormalBehaviour::apply() {
}
/*
void ScaloCellBehaviour::apply(Cell* celulaPadre, Cell* celulaHija) {
}

void ZombieBehaviour::apply(Cell* celulaPadre, Cell* celulaHija) {
    int genes[3] = { 0,0,0 };
    celulaHija->setGenes(genes);
}


void PortalBehaviour::apply(Cell* celulaPadre, Cell* celulaHija) {
    int* genes;
    genes = celulaPadre->getGenes();
    celulaHija->setGenes(genes);
}

*/