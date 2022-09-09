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

// metodos iniciales
void initJuego(Juego * juego);
void setCelulaInicial(Juego* juego, int fila, int columna);



// getters
int getTurno(Juego * juego);
bool getJuegoEnMarcha(Juego * juego);
int getTurnosMaximos(Juego* juego);
int getTotalNacimientos(Juego * j);
int getTotalMuertes(Juego * j);
int getMuertesUltimoTurno(Juego * j);
int getNacimientosUltimoTurno(Juego * j);

// setters
void setTurno(Juego* juego, int turno);
void setJuegoEnMarcha(Juego * juego, bool juegoEnMarcha);
void setTurnosMaximos(Juego * juego, int turnosMaximos);
void setInputUsuario(Juego * juego, int inputUsuario);
void setEstadoCongelado(Juego * juego, bool estadoCongelado);
void setMuertesUltimoTurno(Juego * juego, int muertesUltimoTurno);
void setNacimientosUltimoTurno(Juego * juego, int muertesUltimoTurno);
void setCantidadTurnosCongelado(Juego * juego, int cantidadTurnosCongelado);


//metodos de mensajes y estados 
void mostrarEstadoJuego(Juego * juego);
void mostrarTablero(Juego* juego);
void imprimirMenuInicial(Juego* juego);
void imprimirMenuContinuacion(Juego* juego);
void imprimirMensajeTerminacion();
void imprimirMensajeCantidadMaximaTurnosAlcanzada();

// metodos de accion
void maquinaDeEstados(Juego* juego);
void avanzarTurno(Juego * juego);
ESTADO_CELULA definirProximoEstadoCelula(Celula celula, int cantidadVecinosVivos);
void contarTransiciones(Juego * juego, ESTADO_CELULA estadoCelulaActual, ESTADO_CELULA estadoCelulaNueva);
void limpiarUltimasTransiciones(Juego * juego);
bool evaluarTurnosMaximos(Juego* juego);
void terminarJuego(Juego* juego);

// metodos de actualizacion
void actualizarTablero(Juego* juego);
void actualizarTransicionesTotales(Juego * juego);
void actualizarEstadoCongelado(Juego * juego);








#endif 