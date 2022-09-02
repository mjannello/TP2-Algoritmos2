#include "Tablero.h"

void initTablero(Tablero * t) {
	t->anchoMaximo = ANCHO_MAXIMO;
	t->altoMaximo = ALTO_MAXIMO;
}

int getAnchoMaximo(Tablero * t) {
	return t->anchoMaximo;
}

int getAltoMaximo(Tablero * t) {
	return t->altoMaximo;
}


void setAnchoMaximo(Tablero * t, int anchoMaximo) {
	t->anchoMaximo = anchoMaximo;
}

void setAltoMaximo(Tablero * t, int altoMaximo) {
	t->altoMaximo = altoMaximo;
}



Celula getValor(Tablero * t, int fila, int columna) {
	int _fila = fila - 1;
	int _columna = columna - 1;
	return t->matrizCelulas[_fila][_columna];
}

void setValor(Tablero * t, Celula celula, int fila, int columna) {
	int _fila = fila - 1;
	int _columna = columna - 1;
	t->matrizCelulas[_fila][_columna] = celula;
}

int contarCantidadVecinosVivos(Tablero * tablero, int x, int y) {

	int neighborsAlive = 0;

	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (i == x && j == y) {
				continue;
			}

			if (i < 0 || j < 0 || i == tablero->altoMaximo || j == tablero->anchoMaximo) {
				continue;
			}

			Celula c = getValor(tablero, x, y);
			neighborsAlive += getEstado(&c) == VIVA ? 1 : 0;
				
		}
	}
	return neighborsAlive;
}