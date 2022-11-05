#ifndef BOARD_H
#define BOARD_H

#include "Lista.h"
#include "Box.h"


#include <iostream>
using namespace std;

template<class T> class Board
{
public:
	int width;
	int length;
	int height;

	Board(int width, int length, int height);
	~Board();
	void assignNeighbours();
	void assignNeighbour(Box<T>* box);
	int validateEdges(int coord, int edge);
	int getWidth();
	void setWidth(int width);
	int getLength();
	void setLength(int length);
	int getHeight();
	void setHeight(int height);
	Box<T>* getBox(int x, int y, int z);
	void fillBox(int x, int y, int z, T element);
	void append(T element);
	int countAllBoxes();
	void fillWith(Lista<T>* elements);
	Lista<Lista<Lista<Box<T>*>*>*>* boxes;
};

#include "Board.h"

template<class T>
Board<T>::Board(int width, int length, int height) {

	setWidth(width);
	setLength(length);
	setHeight(height);
	
	this->boxes = new Lista<Lista<Lista<Box<T>*>*>*>;

	for (int x = 1; x <= width; x++) {
		Lista<Lista<Box<T>*>*>* row = new Lista<Lista<Box<T>*>*>;
		this->boxes->add(row);
		for (int y = 1; y <= length; y++) {
			Lista<Box<T>*>* column = new Lista<Box<T>*>;
			row->add(column);
			for (int z = 1; z <= height; z++) {
				Box<T>* box = new Box<T>(x,y,z);
				column->add(box);
			}
		}
	}

	assignNeighbours();
}

template <class T>
Board<T>::~Board() {

	int rows = getWidth();
	int columns = getLength();

	for (int row = 1; row <= rows; row++) {
		for (int col = 1; col <= columns; col++) {
			// TODO: delete Box list of neighbours 
			delete this->boxes->get(row)->get(col);
		}
		delete this->boxes->get(row);
	}
	delete this->boxes;
}


template<class T>
void Board<T>::assignNeighbours() {
	for (int x = 1; x <= getWidth(); x++) {
		for (int y = 1; y <= getLength(); y++) {
			for (int z = 1; z <= getHeight(); z++) {
				Box<T>* actualBox = getBox(x, y, z);
				assignNeighbour(actualBox);
			}
		}
	}
}

template<class T>
void Board<T>::assignNeighbour(Box<T> * box){

	int coordX = box->getCoordX();
	int coordY = box->getCoordY();
	int coordZ = box->getCoordZ();

	for (int i = coordX - 1; i < coordX + 2; i++){
		for (int j = coordY - 1; j < coordY + 2; j++) {
			for (int k = coordZ - 1; k < coordZ + 2; k++){
				
				if (i == coordX && j == coordY && k == coordZ) {
					continue;
				}
				int validCoordX = validateEdges(i, getWidth());
				int validCoordY = validateEdges(j, getLength());
				int validCoordZ = validateEdges(k, getHeight());

				Box<T> * neighbour = getBox(validCoordX, validCoordY, validCoordZ);
				box->addNeighbour(neighbour);
			}
		}
	}
}

template<class T>
int Board<T>::validateEdges(int coord, int edge) {
	int validCoord = coord <= edge ? coord : 1;
	validCoord = coord < 1 ? edge : validCoord;
	return validCoord;
}

template<class T>
int Board<T>::getWidth() {
	return this->width;
}

template<class T>
void Board<T>::setWidth(int width) {
	this->width = width;
}


template<class T>
int Board<T>::getLength() {
	return this->length;
}

template<class T>
void Board<T>::setLength(int length) {
	this->length = length;
}

template<class T>
int Board<T>::getHeight() {
	return this->height;
}

template<class T>
void Board<T>::setHeight(int height) {
	this->height = height;
}

template<class T>
Box<T>* Board<T>::getBox(int x, int y, int z) {
	return this->boxes->get(x)->get(y)->get(z);
}

template<class T>
void Board<T>::fillBox(int x, int y, int z, T element) {
	this->boxes->get(x)->get(y)->get(z)->setData(element);
}

template<class T>
void Board<T>::append(T element) {
	for (int x = 1; x <= getWidth(); x++)
	{
		for (int y = 1; y <= getLength(); y++)
		{
			for (int z = 1; z <= getHeight(); z++)
			{
				if (getBox(x, y, z)->isEmpty()) {
					fillBox(x, y, z, element);
					return;
				}
			}
		}
	}
	return;
}

template<class T>
int Board<T>::countAllBoxes() {
	return getWidth() * getLength() * getLength();

}

template<class T>
void Board<T>::fillWith(Lista<T> * elements) {
	if (elements->contarElementos() > this->countAllBoxes()) {
		throw "Too much elements: cannot be added to the Board";
	}
	while (elements->avanzarCursor()) {
		T element = elements->getCursor();
		this->append(element);

	}
}




#endif
