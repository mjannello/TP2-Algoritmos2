#include "Juego.h"


int main() {

	Juego j;
	initJuego(&j);
	
	imprimirMenuInicial(&j);
	imprimirMenuContinuacion(&j);
	
	while(getJuegoEnMarcha(&j)) {
		maquinaDeEstados(&j);
	}
	
	return 0;
}