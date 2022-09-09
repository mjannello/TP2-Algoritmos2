#include "Juego.h"

using namespace std;
 
  ///////////////////////
 // metodos iniciales //
///////////////////////

void initJuego(Juego * juego){
	juego->estadoCongelado = false;
	juego->cantidadTurnosCongelado=0;
	juego->nacimientosUltimoTurno=0, juego->muertesUltimoTurno=0;
	juego->totalNacimientos=0, juego->totalMuertes=0;
	juego->punteroTableroActual = &(juego->tableroActual);
	juego->punteroTableroProximoTurno = &(juego->tableroProximoTurno);
	setJuegoEnMarcha(juego, true);
	initTablero(juego->punteroTableroActual);
	initTablero(juego->punteroTableroProximoTurno);
	setTurno(juego, 1);
	setEstadoCongelado(juego, false);
}

void setCelulaInicial(Juego* juego, int fila, int columna) {
	Celula c;
	setEstado(&c, VIVA);
	setValor(juego->punteroTableroActual, c, fila, columna);
}

  /////////////
 // getters //
/////////////

int getTurno(Juego * j) {
	return j -> turno;
}

int getTurnosMaximos(Juego * j) {
	return j->turnosMaximos;
}

int getTotalMuertes(Juego * j) {
	return j->totalMuertes;
}


int getTotalNacimientos(Juego* j) {
	return j->totalNacimientos;
}

bool getJuegoEnMarcha(Juego * j) {
	return j->juegoEnMarcha;
}

int getMuertesUltimoTurno(Juego* j) {
	return j->muertesUltimoTurno;
}

int getNacimientosUltimoTurno(Juego* j) {
	return j->nacimientosUltimoTurno;
}

  /////////////
 // setters //
/////////////

void setTurno(Juego* j, int turno) {
	j->turno = turno;
}

void setTurnosMaximos(Juego * j, int turnosMaximos) {
	j->turnosMaximos = turnosMaximos;
}

void setJuegoEnMarcha(Juego * j, bool juegoEnMarcha) {
	j->juegoEnMarcha = juegoEnMarcha;
}

void setEstadoCongelado(Juego * j, bool estadoCongelado) {
	j->estadoCongelado = estadoCongelado;
}

void setInputUsuario(Juego * j, int inputUsuario) {
	j->inputUsuario = inputUsuario;
}


void setMuertesUltimoTurno(Juego * j, int muertesUltimoTurno) {
	j->muertesUltimoTurno = muertesUltimoTurno;
}

void setNacimientosUltimoTurno(Juego * j, int nacimientosUltimoTurno) {
	j->nacimientosUltimoTurno = nacimientosUltimoTurno;
}

void setCantidadTurnosCongelado(Juego * j, int cantidadTurnosCongelado) {
	j->cantidadTurnosCongelado = cantidadTurnosCongelado;
}

  ///////////////////////
 // metodos de accion //
///////////////////////

void maquinaDeEstados(Juego* juego) {
	if (evaluarTurnosMaximos(juego)) {
		mostrarEstadoJuego(juego);
		imprimirMensajeCantidadMaximaTurnosAlcanzada();
		terminarJuego(juego);
		return;
	}

	switch (juego->inputUsuario)
	{
	case 1:

		avanzarTurno(juego);
		mostrarEstadoJuego(juego);
		imprimirMenuContinuacion(juego);
		break;
	case 2:
		initJuego(juego);
		imprimirMenuInicial(juego);
		imprimirMenuContinuacion(juego);
		break;
	case 3:
		terminarJuego(juego);
		break;
	default:
		break;

	}
}

void avanzarTurno(Juego * juego) {
	limpiarUltimasTransiciones(juego);
	actualizarTablero(juego);
	actualizarTransicionesTotales(juego);
	actualizarEstadoCongelado(juego);
	juego->turno++;

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

void contarTransiciones(Juego* juego, ESTADO_CELULA estadoCelulaActual, ESTADO_CELULA estadoCelulaNueva) {
	if (estadoCelulaActual == VIVA && estadoCelulaNueva == MUERTA) {
		juego->muertesUltimoTurno++;
	}
	if (estadoCelulaActual == MUERTA && estadoCelulaNueva == VIVA) {
		juego->nacimientosUltimoTurno++;
	}
}

void limpiarUltimasTransiciones(Juego * juego) {
	setMuertesUltimoTurno(juego, 0);
	setNacimientosUltimoTurno(juego, 0);	
}

bool evaluarTurnosMaximos(Juego * juego) {
	if (getTurno(juego) == getTurnosMaximos(juego)) {
		return true;
	}
	return false;
}

void terminarJuego(Juego* juego) {
	imprimirMensajeTerminacion();
	setJuegoEnMarcha(juego, false);
}



 ///////////////////////////////////
// metodos de mensajes y estados //
//////////////////////////////////


void mostrarEstadoJuego(Juego * juego) {
	mostrarTablero(juego);
	cout << endl;
	cout << "****************" << endl;
	cout << "Estado del Juego " << endl;
	cout << "****************" << endl << endl;
	float promedioMuertes = getTurno(juego) == 0 ? (float)getTotalMuertes(juego) : getTotalMuertes(juego) / getTurno(juego);
	float promedioNacimientos = getTurno(juego) == 0 ? (float)getTotalNacimientos(juego) : getTotalNacimientos(juego) / getTurno(juego);

	cout << "Células vivas: " << contarTotalCelulasVivas(juego->punteroTableroActual) << endl;
	cout << "Nacimientos: " << juego->nacimientosUltimoTurno << endl;
	cout << "Muertes: " << juego->muertesUltimoTurno << endl;
	cout << "Promedio de Nacimientos: " << promedioNacimientos << endl;
	cout << "Promedio de Muertes: " << promedioMuertes << endl;

	string mensajeJuegoCongelado = juego->estadoCongelado ? "si" : "no";
	cout << "Juego congelado: " << mensajeJuegoCongelado << endl;
	cout << endl;
}

void mostrarTablero(Juego * juego) {
	int anchoMaximo = getAnchoMaximo(juego->punteroTableroActual);
	int altoMaximo = getAltoMaximo(juego->punteroTableroActual);

	cout << endl;
	cout << "********" << endl;
	cout << "Tablero " << endl;
	cout << "********" << endl << endl;
	for (int i = 1; i < altoMaximo + 1; i++)
	{
		for (int j = 1; j < anchoMaximo + 1; j++)
		{
			Celula c = getValor(juego->punteroTableroActual, i, j);
			cout << getEstado(&c);
		}
		cout << '\n';
	}
	cout << '\n';
}

void imprimirMenuInicial(Juego * juego) {
	int turnosMaximos;
	int numeroCelulas, fila, columna;

	cout << "=================" << endl;
	cout << "Juego de la Vida! " << endl;
	cout << "=================" << endl << endl;
	cout << "Ingrese la cantidad de turnos máximos a jugar:" << endl;
	cin >> turnosMaximos;
	cout << endl;
	cout << "Ingrese la cantidad de celulas que desea ingresar:" << endl;
	cin >> numeroCelulas;
	cout << endl;
	for (int i = 0; i < numeroCelulas; i++) {
		cout << "********" << endl;
		cout << "Celula " << i + 1 << endl;
		cout << "********" << endl;
		cout << endl;
		cout << "Fila: " << endl;
		cin >> fila;
		cout << endl;
		cout << "Columna: " << endl;
		cin >> columna;
		cout << endl;
		setCelulaInicial(juego, fila, columna);
	}

	setTurnosMaximos(juego, turnosMaximos);
	mostrarTablero(juego);
}

void imprimirMenuContinuacion(Juego* juego) {
	int inputUsuario;

	cout << endl;
	cout << "************************************" << endl;
	cout << "Acciones (ingrese valores 1, 2 o 3): " << endl;
	cout << "************************************" << endl << endl;
	cout << "1.Ejecutar un turno" << endl;
	cout << "2.Reiniciar juego" << endl;
	cout << "3.Terminar juego" << endl;
	cin >> inputUsuario;
	setInputUsuario(juego, inputUsuario);
}

void imprimirMensajeTerminacion() {
	cout << "Juego terminado!" << endl;
}

void imprimirMensajeCantidadMaximaTurnosAlcanzada() {
	cout << "Cantidad maxima de turnos alcanzada!" << endl;
}


  //////////////////////////////
 // metodos de actualizacion //
//////////////////////////////



void actualizarTablero(Juego* juego) {
	int anchoMaximo = getAnchoMaximo(juego->punteroTableroActual);
	int altoMaximo = getAltoMaximo(juego->punteroTableroActual);
	Tablero* punteroTableroAuxiliar;

	for (int i = 1; i < altoMaximo; i++)
	{
		for (int j = 1; j < anchoMaximo; j++)
		{
			Celula celulaActual = getValor(juego->punteroTableroActual, i, j);
			int cantidadVecinosVivos = contarCantidadVecinosVivos(juego->punteroTableroActual, i, j);
			ESTADO_CELULA estadoCelulaNueva = definirProximoEstadoCelula(celulaActual, cantidadVecinosVivos);
			Celula celulaNueva;
			setEstado(&celulaNueva, estadoCelulaNueva);
			setValor(juego->punteroTableroProximoTurno, celulaNueva, i, j);
			contarTransiciones(juego, getEstado(&celulaActual), estadoCelulaNueva);
		}
	}

	//intercambio de punteros entre tablero actual y tablero del turno siguiente
	punteroTableroAuxiliar = juego->punteroTableroActual;
	juego->punteroTableroActual = juego->punteroTableroProximoTurno;
	juego->punteroTableroProximoTurno = punteroTableroAuxiliar;
}

void actualizarTransicionesTotales(Juego* juego) {
	juego->totalMuertes += juego->muertesUltimoTurno;
	juego->totalNacimientos += juego->nacimientosUltimoTurno;
}

void actualizarEstadoCongelado(Juego* juego) {
	if (getNacimientosUltimoTurno(juego) == 0 && getMuertesUltimoTurno(juego) == 0) {
		juego->cantidadTurnosCongelado += 1;
		if (juego->cantidadTurnosCongelado >= 2) {
			setEstadoCongelado(juego, true);
		}
	}
	else {
		setCantidadTurnosCongelado(juego, 0);
		setEstadoCongelado(juego, false);
	}

}


	







	
