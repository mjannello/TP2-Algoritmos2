#include "Tablero.h"

  ///////////////////////
 // metodos iniciales //
///////////////////////

void initTablero(Tablero * t) {
	setAnchoMaximo(t, ANCHO_MAXIMO);
	setAltoMaximo(t, ALTO_MAXIMO);
	llenarTableroCelulasMuertas(t);

}


  /////////////
 // getters //
/////////////

int getAnchoMaximo(Tablero * t) {
	return t->anchoMaximo;
}

int getAltoMaximo(Tablero * t) {
	return t->altoMaximo;
}


  /////////////
 // setters //
/////////////

void setAnchoMaximo(Tablero * t, int anchoMaximo) {
	t->anchoMaximo = anchoMaximo;
}

void setAltoMaximo(Tablero * t, int altoMaximo) {
	t->altoMaximo = altoMaximo;
}


  ///////////////////////
 // metodos de accion //
///////////////////////

Celula getValor(Tablero * t, int fila, int columna) {
	/* metodo para obtener un valor de una celda. Se comienza desde la posicion (1,1) */
	int _fila = fila - 1;
	int _columna = columna - 1;
	return t->matrizCelulas[_fila][_columna];
}

void setValor(Tablero * t, Celula celula, int fila, int columna) {
	/* metodo para definir el valor de una celda. Se comienza desde la posicion (1,1) */
	int _fila = fila - 1;
	int _columna = columna - 1;
	t->matrizCelulas[_fila][_columna] = celula;
}


void llenarTableroCelulasMuertas(Tablero * t) {
	/* metodo para llenar un tablero con celulas muertas */
	for (int i = 1; i < getAltoMaximo(t)+1; i++)
	{
		for (int j = 1; j < getAnchoMaximo(t)+1; j++)
		{
			Celula c;
			setEstado(&c, MUERTA);
			setValor(t, c, i, j);
		}

	}
}


bool evaluarPosicionValida(Tablero * t, int x, int y) {
	/* metodo para definir si una celda tiene una posicion valida */
	if (x < 1 || y < 1 || x == getAltoMaximo(t) || y == getAnchoMaximo(t)) {
		return false;
	}
	return true;
}

int contarCantidadVecinosVivos(Tablero * tablero, int x, int y) {
	/* metodo para contar el total de elementos vecinos vivos */
	int neighborsAlive = 0;

	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {

			if (i == x && j == y) { // si se trata de la misma celula, no es contabilizada 
				continue;
			}

			if (evaluarPosicionValida(tablero, i, j) == false) { 
				//evaluacion si la celda esta dentro de los margenes validos.
				//caso contrario, no se contabiliza
				continue;
			}

			Celula c = getValor(tablero, i, j);
			neighborsAlive += getEstado(&c) == VIVA ? 1 : 0;
				
		}
	}
	return neighborsAlive;
}

int contarTotalCelulasVivas(Tablero * t) {
	/* metodo para contar el total de celulas vivas */

	int totalCelulasVivas = 0;
	for (int i = 1; i < t->altoMaximo; i++){
		for (int j = 1; j < t->anchoMaximo; j++){
			Celula c = getValor(t, i, j);
			if (getEstado(&c) == VIVA) {
				totalCelulasVivas++;
			}
		}
	}

	return totalCelulasVivas;
}

