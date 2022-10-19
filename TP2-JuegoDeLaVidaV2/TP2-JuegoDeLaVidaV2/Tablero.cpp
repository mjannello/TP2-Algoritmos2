#include "Tablero.h"

Tablero::Tablero(int x, int y, int z) {
	//Creo todos los casilleros
	this->casilleros = new Lista<Lista<Lista<Casillero*>*>*>();

}
