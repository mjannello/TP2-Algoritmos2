#ifndef TABLERO_H
#define TABLERO_H

#include "Lista.h"
#include "Casillero.h"

class Tablero
{
public:
	Tablero(int x, int y, int z);
	Lista<Lista<Lista<Casillero*>*>*>* casilleros;
};

#endif 