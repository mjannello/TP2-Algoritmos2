#include <iostream>
#include "Juego.h"

using namespace std;

int main() {

	Juego j;
	initJuego(&j);
	imprimirMenuInicial(&j);
	imprimirMenuContinuacion(&j);

	return 0;
}