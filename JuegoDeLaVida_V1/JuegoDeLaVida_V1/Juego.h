#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "Celula.h"
#include "Tablero.h"

using namespace std;


typedef struct {
	Tablero tableroActual;
	Tablero tableroProximoTurno;
	Tablero * punteroTableroActual;
	Tablero * punteroTableroProximoTurno;
	int turno;
	bool estadoCongelado;
	int cantidadTurnosCongelado;
	int nacimientosUltimoTurno, muertesUltimoTurno;
	int totalNacimientos, totalMuertes;

} Juego;

void initJuego(Juego * juego);
int getTurno(Juego * juegoj);
void setTurno(Juego * juego, int turno);
void setEstadoCongelado(Juego * juego, bool estadoCongelado);
void avanzarTurno(Juego * juego);
int contarCantidadVecinosVivos(Tablero * juego, int x, int y);
ESTADO_CELULA definirProximoEstadoCelula(Celula celula, int cantidadVecinosVivos);
void actualizarTablero(Juego* juego);
void contarTransiciones(Juego* juego, ESTADO_CELULA estadoCelulaActual, ESTADO_CELULA estadoCelulaNueva);
void actualizarTransicionesTotales(Juego* juego);
void imprimirMenuInicial(Juego* juego);
void setCelulaInicial(Juego* juego, int fila, int columna);
void mostrarTablero(Juego* juego);
void imprimirMenuContinuacion(Juego* juego);


#endif 