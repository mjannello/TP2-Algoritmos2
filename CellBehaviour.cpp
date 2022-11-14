
#include "CellBehaviour.h"


void CellBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes){}


void RadiactiveBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {
    int* _genes = childGenes->getGenes();
    _genes[0] = _genes[0] / 2;
    childGenes->setGenes(_genes);
}


void AryanBehaviour::apply(CellGenes * fatherGenes, CellGenes* childGenes) {

    int * _fatherGenes = fatherGenes->getGenes();
    int* _childGenes = childGenes->getGenes();
    int indexMaximumGen=0;
    int maxGen = 0;

    for (int i = 0; i < fatherGenes->getGenesCount(); i++) {
        if (_fatherGenes[i] > maxGen) {
            indexMaximumGen = i;
            maxGen = _fatherGenes[i];
        }
    }
    
    _childGenes[indexMaximumGen] = maxGen;
    childGenes->setGenes(_childGenes);
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