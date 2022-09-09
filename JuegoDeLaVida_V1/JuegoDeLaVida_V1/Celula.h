#ifndef CELULA_H
#define CELULA_H

enum ESTADO_CELULA {
	MUERTA=0,
	VIVA=1
};

typedef struct {
	ESTADO_CELULA estado;
} Celula;

  ///////////////////////
 // metodos iniciales //
///////////////////////

void initCelula(Celula * celula, ESTADO_CELULA estadoInicial);


  /////////////
 // getters //
/////////////

ESTADO_CELULA getEstado(Celula * celula);


  /////////////
 // setters //
/////////////

void setEstado(Celula * celula, ESTADO_CELULA nuevoEstado);

#endif 