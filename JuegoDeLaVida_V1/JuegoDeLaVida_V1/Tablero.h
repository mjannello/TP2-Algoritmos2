#ifndef TABLERO_H
#define TABLERO_H
#include "Celula.h"

static const int ALTO_MAXIMO = 20;
static const int ANCHO_MAXIMO = 80;

typedef struct {
	int anchoMaximo;
	int altoMaximo;
	Celula matrizCelulas[ALTO_MAXIMO][ANCHO_MAXIMO];
} Tablero;

void initTablero(Tablero* t);
int getAnchoMaximo(Tablero * t);
int getAltoMaximo(Tablero * t);
void setAnchoMaximo(Tablero* t, int anchoMaximo);
void setAltoMaximo(Tablero* t, int altoMaximo);

Celula getValor(Tablero * t, int fila, int columna);
void setValor(Tablero* t, Celula celula, int fila, int columna);
int contarCantidadVecinosVivos(Tablero* tablero, int x, int y);
int contarTotalCelulasVivas(Tablero* t);
void llenarTableroCelulasMuertas(Tablero* t);


#endif 