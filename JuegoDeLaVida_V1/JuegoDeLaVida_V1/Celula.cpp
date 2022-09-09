#include "Celula.h"

void initCelula(Celula* celula, ESTADO_CELULA estadoInicial)
{
	setEstado(celula, estadoInicial);
}

  /////////////
 // getters //
/////////////

ESTADO_CELULA getEstado(Celula * c) {
	return c->estado;
}

  /////////////
 // setters //
/////////////

void setEstado(Celula * c, ESTADO_CELULA nuevoEstado) {
	c->estado = nuevoEstado;
}

