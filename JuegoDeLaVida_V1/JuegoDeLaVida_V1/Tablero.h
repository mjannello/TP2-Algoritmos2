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

// metodos iniciales
void initTablero(Tablero * t);

// getters
int getAnchoMaximo(Tablero * t);
int getAltoMaximo(Tablero * t);

// setters
void setAnchoMaximo(Tablero * t, int anchoMaximo);
void setAltoMaximo(Tablero * t, int altoMaximo);

// metodos de accion
Celula getValor(Tablero * t, int fila, int columna);
void setValor(Tablero * t, Celula celula, int fila, int columna);
void llenarTableroCelulasMuertas(Tablero* t);
bool evaluarPosicionValida(Tablero* t, int x, int y);
int contarCantidadVecinosVivos(Tablero * tablero, int x, int y);
int contarTotalCelulasVivas(Tablero * t);

#endif 