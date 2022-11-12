
#ifndef COMPORTAMIENTO_H_
#define COMPORTAMIENTO_H_
#include "Celula.h"
class Celula;
class Comportamiento {
public:
    virtual void aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija) = 0;
};


class ComportamientoRadiactivo : public Comportamiento {
public:

    virtual void aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija);
};

class ComportamientoArio : public Comportamiento {
public:
    virtual void aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija);
};

class ComportamientoScaloCelula : public Comportamiento {
public:
    virtual void aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija);
};

class ComportamientoZombie : public Comportamiento {
public:
    virtual void aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija);
};

class ComportamientoPortal : public Comportamiento {
public:
    virtual void aplicarComportamiento(Celula* celulaPadre, Celula* celulaHija);
};


#endif /* COMPORTAMIENTO_H_ */