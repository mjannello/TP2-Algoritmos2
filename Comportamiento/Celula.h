#ifndef CELULA_H_
#define CELULA_H_
#include "Comportamiento.h"

enum t_comportamiento { RADIOACTIVO, PORTAL, ZOMBIE, SCALOCELULA, ARIA };
class Comportamiento;
class Celula {
private:
    int genes[3];
    Comportamiento* comp;
public:

    Celula(int x, int y, int z, t_comportamiento comp);

    void setGenes(int gen[]);

    int* getGenes();

    void print();

    void aplicarComportamiento(Celula* c, Celula* c2);
};

#endif /* CELULA_H_ */