#ifndef BOARD_H
#define BOARD_H

#include "List.h"
#include "Box.h"


#include <iostream>
using namespace std;

template<class T> class Board
{
public:
	int width;
	int length;
	int height;
	List<List<List<Box<T>*>*>*>* boxes;

	Board(int width, int length, int height);
	~Board();
	void assignNeighbours();
	void assignNeighbour(Box<T>* box);
	int getValidEdge(int coord, int edge);
	bool isValidEdge(int coord, int edge);
	bool isValidSize(int size);
	int getWidth();
	void setWidth(int width);
	int getLength();
	void setLength(int length);
	int getHeight();
	void setHeight(int height);
	Box<T>* getBox(int x, int y, int z);
	void fillBox(int x, int y, int z, T element);
	void append(T element);
	unsigned int countAllBoxes();
	void fillWith(List<T>* elements);
	void fillCompletelyWith(T element);
	void defineNewStates();
};

#include "Board.h"

template<class T>
Board<T>::Board(int width, int length, int height) {

	setWidth(width);
	setLength(length);
	setHeight(height);

	this->boxes = new List<List<List<Box<T>*>*>*>;

	for (int x = 1; x <= width; x++) {
		List<List<Box<T>*>*>* row = new List<List<Box<T>*>*>;
		this->boxes->add(row);
		for (int y = 1; y <= length; y++) {
			List<Box<T>*>* column = new List<Box<T>*>;
			row->add(column);
			for (int z = 1; z <= height; z++) {
				Box<T>* box = new Box<T>(x, y, z);
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
				Box<T>* currentBox = getBox(x, y, z);
				assignNeighbour(currentBox);
			}
		}
	}
}

template<class T>
void Board<T>::assignNeighbour(Box<T>* box) {

	int coordX = box->getCoordX();
	int coordY = box->getCoordY();
	int coordZ = box->getCoordZ();

	for (int i = coordX - 1; i < coordX + 2; i++) {
		for (int j = coordY - 1; j < coordY + 2; j++) {
			for (int k = coordZ - 1; k < coordZ + 2; k++) {

				if (i == coordX && j == coordY && k == coordZ) {
					continue;
				}
				int validCoordX = getValidEdge(i, getWidth());
				int validCoordY = getValidEdge(j, getLength());
				int validCoordZ = getValidEdge(k, getHeight());

				Box<T>* neighbour = getBox(validCoordX, validCoordY, validCoordZ);
				box->addNeighbour(neighbour);
			}
		}
	}
}

template<class T>
int Board<T>::getValidEdge(int coord, int edge) {
	int validCoord = coord <= edge ? coord : 1;
	validCoord = coord < 1 ? edge : validCoord;
	return validCoord;
}


template<class T>
bool Board<T>::isValidEdge(int coord, int edge) {
	return coord > 0 && coord <= edge;
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
unsigned int Board<T>::countAllBoxes() {
	return getWidth() * getLength() * getHeight();

}

template<class T>
bool Board<T>::isValidSize(int size) {
	int allBoxes = this->countAllBoxes();
	bool response = size > 0 && size <= this->countAllBoxes();
	return response;
}

template<class T>
void Board<T>::fillWith(List<T>* elements) {
	if (elements->countElements() > this->countAllBoxes()) {
		throw "Too much elements: cannot be added to the Board";
	}
	elements->resetCursor();
	while (elements->moveCursor()) {
		T element = elements->getCursor();
		this->append(element);

	}
}

template<class T>
void Board<T>::fillCompletelyWith(T element) {
	for (int i = 1; i <= this->countAllBoxes(); i++)
	{
		this->append(element);
	}

}


template<class T>
void Board<T>::defineNewStates() {
	for (int x = 1; x <= getWidth(); x++) {
		for (int y = 1; y <= getLength(); y++) {
			for (int z = 1; z <= getHeight(); z++) {
				getBox(x, y, z)->nextState();
			}
		}
	}
}




#endif
