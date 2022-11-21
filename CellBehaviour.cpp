
#include "CellBehaviour.h"


void CellBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {}


void RadiactiveBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {
    int* _genes = childGenes->getGenesValues();
    _genes[0] = _genes[0] / 2;
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

void PortalBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {

}

void NormalBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {
}

void ScaloCellBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {
}



void ZombieBehaviour::apply(CellGenes* fatherGenes, CellGenes* childGenes) {
    int genes[3] = { 0,0,0 };
    childGenes->setGenesValues(genes);
}

