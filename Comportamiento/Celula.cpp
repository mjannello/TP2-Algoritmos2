#include <iostream>
#include "Celula.h"
#include "Comportamiento.h"



Celula::Celula(int x, int y, int z, t_comportamiento comp) {
    this->genes[0] = x;
    this->genes[1] = y;
    this->genes[2] = z;

    switch (comp) {
    case RADIOACTIVO:
        this->comp = new ComportamientoRadiactivo();
        break;
    case SCALOCELULA:
        this->comp = new ComportamientoScaloCelula();
        break;
    case ARIA:
        this->comp = new ComportamientoArio();
        break;
    case ZOMBIE:
        this->comp = new ComportamientoZombie();
        break;
    case PORTAL:
        this->comp = new ComportamientoPortal();
        break;
    }
}

void Celula::setGenes(int gen[]) {

    for (int i = 0; i < 3; i++) {
        this->genes[i] = gen[i];
        //std::cout<< "Genes seteados" << i << " es : ---->" << this->genes[i]<<std::endl;
    }
}

int* Celula::getGenes() {
    return this->genes;
}

void Celula::print() {
    for (int i = 0; i < 3; i++) {
        std::cout << "Gen" << i << " es : ---->" << this->genes[i] << std::endl;
    }
}

void Celula::aplicarComportamiento(Celula* c, Celula* c2) {
    this->comp->aplicarComportamiento(this, c2);
}