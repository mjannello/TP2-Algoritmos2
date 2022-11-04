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
	int getWidth();
	void setWidth(int width);
	int getLength();
	void setLength(int length);
	int getHeight();
	void setHeight(int height);
	Box<T>* getBox(int x, int y, int z);
	void fillBox(int x, int y, int z, T element);
	void append(T element);
	Lista<Lista<Lista<Box<T>*>*>*>* boxes;
};

#include "Board.h"

template<class T>
Board<T>::Board(int width, int length, int height) {

	setWidth(width);
	setLength(length);
	setHeight(height);
	
	this->boxes = new Lista<Lista<Lista<Box<T>*>*>*>;

	for (int x = 1; x < width; x++) {
		Lista<Lista<Box<T>*>*>* row = new Lista<Lista<Box<T>*>*>;
		this->boxes->add(row);
		for (int y = 1; y < length; y++) {
			Lista<Box<T>*>* column = new Lista<Box<T>*>;
			row->add(column);
			for (int z = 1; z < height; z++) {
				Box<T>* box = new Box<T>();
				column->add(box);
			}
		}
	}
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
	for (int x = 1; x < getWidth(); x++)
	{
		for (int y = 1; y < getLength(); y++)
		{
			for (int z = 1; z < getHeight(); z++)
			{
				Box<T> * a = getBox(x, y, z);
				if (getBox(x, y, z)->isEmpty()) {
					fillBox(x, y, z, element);
					return;
				}
			}
		}
	}
	return;
}



#endif
