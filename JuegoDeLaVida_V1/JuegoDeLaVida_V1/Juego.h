#ifndef JUEGO_H
#define JUEGO_H
#include "Celula.h"
#include "Tablero.h"

typedef struct {
	Tablero * tableroActual;
	Tablero * tableroProximoTurno;
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
#endif 