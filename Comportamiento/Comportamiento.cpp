#ifndef COMPORTAMIENTO_H
#define COMPORTAMIENTO_H

#include <stdio.h>
#include <iostream>
#include "Celula.h"

//enum t_comportamiento { RADIOACTIVO, PORTAL, ZOMBIE, SCALOCELULA, ARIA };


/*class Celula {
    private:
    int genes[3];
    Comportamiento * comp;
    public:

        Celula(int x,int y, int z, t_comportamiento comp){
           this->genes[0]=x;
           this->genes[1]=y;
           this->genes[2]=z;

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

        void setGenes (int gen []){

            for(int i=0 ;i< 3; i++){
                this -> genes[i]=gen[i];
                //std::cout<< "Genes seteados" << i << " es : ---->" << this->genes[i]<<std::endl;
            }
        }

        int* getGenes(){
            return this->genes;
        }

        void print(){
            for(int i=0 ;i< 3; i++){
                std::cout<< "Gen" << i << " es : ---->" << this->genes[i]<<std::endl;
            }
        }

        void aplicarComportamiento(Celula* c)
        {
            this->comp->aplicarComportamiento(this, c);
        }
};*/

void ComportamientoRadiactivo::aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija) {
    int* genes;
    genes = celulaHija->getGenes();
    genes[0] = genes[0] / 2;
    celulaHija->setGenes(genes);
}


void ComportamientoArio::aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija) {
    int* genesPadre;
    int* genesHija;
    genesPadre = celulaPadre->getGenes();
    genesHija = celulaHija->getGenes();
    int indice = 0;

    for (int i = 0; i < 3; i++) {
        if (genesPadre[i] > genesPadre[indice]) {
            indice = i;
        }
    }
    genesHija[indice] = genesPadre[indice];
    celulaHija->setGenes(genesHija);
}

void ComportamientoScaloCelula::aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija) {
}

void ComportamientoZombie::aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija) {
    int genes[3] = { 0,0,0 };
    celulaHija->setGenes(genes);
}


void ComportamientoPortal::aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija) {
    int* genes;
    genes = celulaPadre->getGenes();
    celulaHija->setGenes(genes);
}

/*
int main() {
    Celula *celulaRadiactiva = new Celula(250,15,2,RADIOACTIVO);

    Celula *celulaScalo = new Celula(250,15,2,SCALOCELULA);

    Celula *celulaZombie = new Celula(250,15,2,ZOMBIE);

    Celula *celulaPortal= new Celula(250,15,2,PORTAL);

    Celula *celulaArio= new Celula(250,15,2,ARIA);

    Celula *celulaHija= new Celula(250,15,2,ARIA);

    std::cout<< "############# Comportamiento Radioactivo ###############"<<std::endl;
    celulaRadiactiva->aplicarComportamiento(celulaHija);
    std::cout<< "Celula Padre"<<std::endl;
    celulaRadiactiva->print();
    std::cout<< "Celula Hija"<<std::endl;
    celulaHija->print();

    std::cout<< "############# Comportamiento Scaloni ###############"<<std::endl;
    celulaScalo->aplicarComportamiento(celulaHija);
    std::cout<< "Celula Padre"<<std::endl;
    celulaScalo->print();
    std::cout<< "Celula Hija"<<std::endl;
    celulaHija->print();

    std::cout<< "############# Comportamiento Ario ###############"<<std::endl;
    celulaArio->aplicarComportamiento(celulaHija);
    std::cout<< "Celula Padre"<<std::endl;
    celulaArio->print();
    std::cout<< "Celula Hija"<<std::endl;
    celulaHija->print();

    std::cout<< "############# Comportamiento Portal ###############"<<std::endl;
    celulaPortal->aplicarComportamiento(celulaHija);
    std::cout<< "Celula Padre"<<std::endl;
    celulaPortal->print();
    std::cout<< "Celula Hija"<<std::endl;
    celulaHija->print();


    std::cout<< "############# Comportamiento Zombie ###############"<<std::endl;
    celulaZombie->aplicarComportamiento(celulaHija);
    std::cout<< "Celula Padre"<<std::endl;
    celulaZombie->print();
    std::cout<< "Celula Hija"<<std::endl;
    celulaHija->print();


}
*/
#endif
