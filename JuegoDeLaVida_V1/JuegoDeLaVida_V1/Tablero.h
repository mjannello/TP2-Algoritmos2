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


  ///////////////////////
 // metodos iniciales //
///////////////////////

/* metodo que inicia un tablero */
void initTablero(Tablero * t);


  /////////////
 // getters //
/////////////

int getAnchoMaximo(Tablero * t);
int getAltoMaximo(Tablero * t);


  /////////////
 // setters //
/////////////

void setAnchoMaximo(Tablero * t, int anchoMaximo);
void setAltoMaximo(Tablero * t, int altoMaximo);


  ///////////////////////
 // metodos de accion //
///////////////////////

/* metodo para obtener un valor de una celda. Se comienza desde la posicion (1,1) */
Celula getValor(Tablero * t, int fila, int columna);


/* metodo para definir el valor de una celda. Se comienza desde la posicion (1,1) */
void setValor(Tablero * t, Celula celula, int fila, int columna);


/* metodo para llenar un tablero con celulas muertas */
void llenarTableroCelulasMuertas(Tablero* t);


/* metodo para definir si una celda tiene una posicion valida */
bool evaluarPosicionValida(Tablero* t, int x, int y);


/* metodo para contar el total de elementos vecinos vivos */
int contarCantidadVecinosVivos(Tablero * tablero, int x, int y);


/* metodo para contar el total de celulas vivas */
int contarTotalCelulasVivas(Tablero * t);

#endif 