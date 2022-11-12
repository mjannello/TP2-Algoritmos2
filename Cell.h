#ifndef CELL_H
#define CELL_H

enum CellState {
	DEAD,
	ALIVE
};

class Cell
{
private:
	//Cell**** neighbours;
	// Comportamiento c;
	// Coleccion<Cell> vecinos;
	// Coleccion<Genes> genes;
	CellState state;

	


	// clase genes que almacene los genes y sepa como generar nuevos apartir de las celulas madre


	// comportamientos obligatorios portal, radioactiva. 
	// comportamientos a definir, ejemplo: envenenada, contaminada, procxreadora
	// podemos definirlo como una clase comportamiento con subclases por cada comportamiento
	// ver patron strategy




public:
	int debugInt;
	Cell(CellState newState);
	~Cell();
	void setState(CellState newState);
	CellState getState();
	bool isAlive();
	void applyBehaviour(Cell* otherCell);
};

#endif 