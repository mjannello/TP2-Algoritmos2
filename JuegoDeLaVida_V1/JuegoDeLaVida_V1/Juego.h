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
	int juegoEnMarcha;
	int turno;
	int turnosMaximos;
	bool estadoCongelado;
	int cantidadTurnosCongelado;
	int nacimientosUltimoTurno, muertesUltimoTurno;
	int totalNacimientos, totalMuertes;
	int inputUsuario;

} Juego;

void initJuego(Juego * juego);
void setCelulaInicial(Juego* juego, int fila, int columna);

void maquinaDeEstados(Juego* juego);

int getTurno(Juego * juego);
bool getJuegoEnMarcha(Juego * juego);
int getTotalNacimientos(Juego * j);
int getTotalMuertes(Juego * j);
int getTurnosMaximos(Juego * juego);

void setJuegoEnMarcha(Juego * juego, bool juegoEnMarcha);
void setTurnosMaximos(Juego * juego, int turnosMaximos);
void setTurno(Juego * juego, int turno);
void setInputUsuario(Juego * juego, int inputUsuario);
void setEstadoCongelado(Juego * juego, bool estadoCongelado);

void avanzarTurno(Juego * juego);
ESTADO_CELULA definirProximoEstadoCelula(Celula celula, int cantidadVecinosVivos);
void actualizarTablero(Juego * juego);
void contarTransiciones(Juego * juego, ESTADO_CELULA estadoCelulaActual, ESTADO_CELULA estadoCelulaNueva);
void limpiarUltimasTransiciones(Juego * juego);
void actualizarTransicionesTotales(Juego * juego);
void actualizarEstadoCongelado(Juego * juego);

void mostrarTablero(Juego * juego);
void imprimirMenuInicial(Juego * juego);
void imprimirMenuContinuacion(Juego * juego);
void imprimirMensajeTerminacion();
void imprimirMensajeCantidadMaximaTurnosAlcanzada();



void terminarJuego(Juego* juego);



#endif 