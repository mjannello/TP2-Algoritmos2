#include "CellGenes.h"
CellGenes::CellGenes() {
    int genes[3]{100,100,100};
    setGenes(genes);
}
CellGenes::CellGenes(int genes[]) {
    setGenes(genes);
}

void CellGenes::setGenes(int gen[]) {

    for (int i = 0; i < this->GENES_QUANTITY; i++) {
        this->genes[i] = gen[i];
        //std::cout<< "Genes seteados" << i << " es : ---->" << this->genes[i]<<std::endl;
    }
}

int* CellGenes::getGenes() {
    return this->genes;
}

int  CellGenes::getGenesCount() {
    return this->GENES_QUANTITY;
}