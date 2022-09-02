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
void setAnchoMaximo();
void setAltoMaximo();
int getAnchoMaximo(Tablero * t);
int getAltoMaximo(Tablero * t);


Celula getValor(Tablero * t, int fila, int columna);
void setValor(Tablero* t, Celula celula, int fila, int columna);


#endif 