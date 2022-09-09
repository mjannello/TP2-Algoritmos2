#include "Tablero.h"


void initTablero(Tablero * t) {
	setAnchoMaximo(t, ANCHO_MAXIMO);
	setAltoMaximo(t, ALTO_MAXIMO);
	llenarTableroCelulasMuertas(t);

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


void llenarTableroCelulasMuertas(Tablero * t) {
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
	if (x < 1 || y < 1 || x == getAltoMaximo(t) || y == getAnchoMaximo(t)) {
		return false;
	}
	return true;
}

int contarCantidadVecinosVivos(Tablero * tablero, int x, int y) {

	int neighborsAlive = 0;

	for (int i = x - 1; i < x + 2; i++) {
		for (int j = y - 1; j < y + 2; j++) {
			if (i == x && j == y) {
				continue;
			}

			if (evaluarPosicionValida(tablero, i, j) == false) {
				continue;
			}

			Celula c = getValor(tablero, i, j);
			neighborsAlive += getEstado(&c) == VIVA ? 1 : 0;
				
		}
	}
	return neighborsAlive;
}

int contarTotalCelulasVivas(Tablero * t) {
	
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

