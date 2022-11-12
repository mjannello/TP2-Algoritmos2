#include "Comportamiento.h"
#include "Celula.h"
#include <iostream>

int main() {

    Celula* celulaRadiactiva = new Celula(250, 150, 200, RADIOACTIVO);
    Celula* celulaScalo = new Celula(250, 100, 175, SCALOCELULA);
    Celula* celulaZombie = new Celula(1, 2, 3, ZOMBIE);
    Celula* celulaPortal = new Celula(120, 155, 28, PORTAL);
    Celula* celulaArio = new Celula(250, 251, 255, ARIA);
    Celula* celulaHija = new Celula(150, 150, 152, ARIA);

    std::cout << "Celula Por Nacer" << std::endl;
    celulaHija->print();

    std::cout << "############# Comportamiento Radioactivo ###############" << std::endl;
    celulaRadiactiva->aplicarComportamiento(celulaRadiactiva, celulaHija);
    std::cout << "Celula Radiactiva" << std::endl;
    celulaRadiactiva->print();
    std::cout << "Celula Hija" << std::endl;
    celulaHija->print();

    std::cout << "############# Comportamiento Scaloni ###############" << std::endl;
    celulaScalo->aplicarComportamiento(celulaScalo, celulaHija);
    std::cout << "Celula Scalocelula" << std::endl;
    celulaScalo->print();
    std::cout << "Celula Hija" << std::endl;
    celulaHija->print();

    std::cout << "############# Comportamiento Ario ###############" << std::endl;
    celulaArio->aplicarComportamiento(celulaArio, celulaHija);
    std::cout << "Celula Aria Heil Hitler" << std::endl;
    celulaArio->print();
    std::cout << "Celula Hija" << std::endl;
    celulaHija->print();

    std::cout << "############# Comportamiento Portal ###############" << std::endl;
    celulaPortal->aplicarComportamiento(celulaPortal, celulaHija);
    std::cout << "Celula Portal" << std::endl;
    celulaPortal->print();
    std::cout << "Celula Hija" << std::endl;
    celulaHija->print();


    std::cout << "############# Comportamiento Zombie ###############" << std::endl;
    celulaZombie->aplicarComportamiento(celulaZombie, celulaHija);
    std::cout << "Celula Zombie" << std::endl;
    celulaZombie->print();
    std::cout << "Celula Hija" << std::endl;
    celulaHija->print();


}