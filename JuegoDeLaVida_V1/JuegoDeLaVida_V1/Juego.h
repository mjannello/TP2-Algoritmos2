#ifndef JUEGO_H
#define JUEGO_H
#include <iostream>
#include "Celula.h"
#include "Tablero.h"


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


  ///////////////////////
 // metodos iniciales //
///////////////////////


/* metodo que inicia un juego */
void initJuego(Juego * juego);

/* metodo que inicia una celula en la posicion del tablero indicada */
void setCelulaInicial(Juego* juego, int fila, int columna);



  /////////////
 // getters //
/////////////

int getTurno(Juego * juego);
bool getJuegoEnMarcha(Juego * juego);
int getTurnosMaximos(Juego* juego);
int getTotalNacimientos(Juego * j);
int getTotalMuertes(Juego * j);
int getMuertesUltimoTurno(Juego * j);
int getNacimientosUltimoTurno(Juego * j);


  /////////////
 // setters //
/////////////

void setTurno(Juego* juego, int turno);
void setJuegoEnMarcha(Juego * juego, bool juegoEnMarcha);
void setTurnosMaximos(Juego * juego, int turnosMaximos);
void setInputUsuario(Juego * juego, int inputUsuario);
void setEstadoCongelado(Juego * juego, bool estadoCongelado);
void setMuertesUltimoTurno(Juego * juego, int muertesUltimoTurno);
void setNacimientosUltimoTurno(Juego * juego, int muertesUltimoTurno);
void setCantidadTurnosCongelado(Juego * juego, int cantidadTurnosCongelado);


  ///////////////////////////////////
 // metodos de mensajes y estados //
///////////////////////////////////

/* metodo que muestra el estado general del juego */
void mostrarEstadoJuego(Juego * juego);


/* metodo que muestra el estado del tablero del juego */
void mostrarTablero(Juego* juego);


/* metodo que imprime el menu inicial y captura parametros de entrada */
void imprimirMenuInicial(Juego* juego);


/* metodo que imprime el menu de continuacion del juego
y captura los parametros */
void imprimirMenuContinuacion(Juego* juego);


/* metodo que imprime mensaje de terminacion del juego */
void imprimirMensajeTerminacion();


/* metodo que imprime mensaje de cantidad maxima de turnos alcanzada */
void imprimirMensajeCantidadMaximaTurnosAlcanzada();


  ///////////////////////
 // metodos de accion //
///////////////////////

/* metodo que marca la transicion de estados en el juego */
void maquinaDeEstados(Juego* juego);


/* metodo para avanzar hacia el siguiente turno */
void avanzarTurno(Juego * juego);


/* metodo para conocer cual sera el proximo estado de una celula segun su estado actual
y la cantidad de vecinos vivos que tiene */
ESTADO_CELULA definirProximoEstadoCelula(Celula celula, int cantidadVecinosVivos);


/* metodo para contar transiciones de celulas entre los estados VIVA y MUERTA */
void contarTransiciones(Juego * juego, ESTADO_CELULA estadoCelulaActual, ESTADO_CELULA estadoCelulaNueva);


/* metodo para borrar (hacer cero) los nacimientos y muertes
del turno anterior */
void limpiarUltimasTransiciones(Juego * juego);


/* metodo para evaluar si se alcanzo la cantidad
maxima de turnos definida por el usuario */
bool evaluarTurnosMaximos(Juego* juego);


/* metodo para terminar el juego */
void terminarJuego(Juego* juego);



  //////////////////////////////
 // metodos de actualizacion //
//////////////////////////////

/* metodo para modificar el tablero entre un turno y el siguiente */
void actualizarTablero(Juego* juego);


/* metodo para sumar a las transiciones totales,
las ocurridas en el turno anterior */
void actualizarTransicionesTotales(Juego * juego);


/* metodo que actualiza el estado congelado del juego
en caso de que el tablero permanezca igual durante 2 turnos */
void actualizarEstadoCongelado(Juego * juego);








#endif 