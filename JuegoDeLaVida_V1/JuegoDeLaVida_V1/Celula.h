#ifndef CELULA_H
#define CELULA_H

enum ESTADO_CELULA {
	MUERTA=0,
	VIVA=1
};

typedef struct {
	ESTADO_CELULA estado;
} Celula;

void initCelula(Celula* celula, ESTADO_CELULA estadoInicial);
ESTADO_CELULA getEstado(Celula *);
void setEstado(Celula * celula, ESTADO_CELULA nuevoEstado);

#endif 