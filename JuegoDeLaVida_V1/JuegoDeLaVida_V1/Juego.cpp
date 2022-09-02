#include "Juego.h"

void initJuego(Juego * juego)
{
	setTurno(juego, 1);
	setEstadoCongelado(juego, false);
}

int getTurno(Juego * j) {
	return j -> turno;
}

void setTurno(Juego * j, int turno) {
	j -> turno = turno;
}

void setEstadoCongelado(Juego * j, bool estadoCongelado) {
	j->estadoCongelado = estadoCongelado;
}

void avanzarTurno(Juego * juego) {
	
	int anchoMaximo = getAnchoMaximo(juego->tableroActual);
	int altoMaximo = getAltoMaximo(juego->tableroActual);
	Tablero * tableroAuxiliar;
	for (int i = 1; i < altoMaximo; i++)
	{
		for (int j = 1; j < anchoMaximo; j++)
		{
			Celula celulaActual = getValor(juego->tableroActual, i, j);
			int cantidadVecinosVivos = contarCantidadVecinosVivos(juego->tableroActual, i, j);
			ESTADO_CELULA estadoCelulaNueva = definirProximoEstadoCelula(celulaActual, cantidadVecinosVivos);
			Celula celulaNueva;
			setEstado(&celulaNueva, estadoCelulaNueva);
			setValor(juego->tableroProximoTurno, celulaNueva, i, j);
		}
	}
	juego->turno++;
	tableroAuxiliar = juego->tableroActual;
	juego->tableroActual = juego->tableroProximoTurno;
	juego->tableroProximoTurno = tableroAuxiliar;
}



ESTADO_CELULA definirProximoEstadoCelula(Celula celula, int cantidadVecinosVivos) {
	if (getEstado(&celula) == MUERTA && cantidadVecinosVivos == 3) { 
		return VIVA; 
	}
	if (getEstado(&celula) == VIVA && cantidadVecinosVivos != 2 && cantidadVecinosVivos != 3) {
		return MUERTA;
	}
	return getEstado(&celula);
}
