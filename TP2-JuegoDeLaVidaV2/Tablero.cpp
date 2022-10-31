#include "Tablero.h"


Tablero::Tablero(int x, int y, int z) {
	//Creo todos los casilleros

	this->casilleros = new Lista<Lista<Lista<Casillero*>*>*>;
    
    for (int fila = 0; fila < x; fila++) {

        Lista<Lista<Casillero*>*>* listaFila = new Lista<Lista<Casillero*>*>();
        
        this->casilleros->add(listaFila);

        for (int columna = 0; columna < y; columna++) {

            Lista<Casillero*>* listaColumna = new Lista<Casillero*>();
            listaFila->add(listaColumna);

            for (int profundidad = 0; profundidad < z; profundidad++) {

                Casillero* nuevoCasillero = new Casillero();
                listaColumna->add(nuevoCasillero);
            }
        }
    }


}
