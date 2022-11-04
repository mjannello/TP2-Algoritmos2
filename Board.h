#ifndef BOARD_H
#define BOARD_H

#include "Lista.h"
#include "Box.h"

template<class T> class Board
{
public:
	int width;
	int length;
	int height;

	Board(int width, int length, int height);
	Lista<Lista<Lista<Box<T>*>*>*>* boxes;
};

#include "Board.h"

template<class T>
Board<T>::Board(int width, int length, int height) {

	// TODO: setear this->width, this->length, this->height

	this->boxes = new Lista<Lista<Lista<Box<T>*>*>*>;

	for (int x = 0; x < width; x++) {
		Lista<Lista<Box<T>*>*>* row = new Lista<Lista<Box<T>*>*>;
		this->boxes->add(row);
		for (int y = 0; y < length; y++) {
			Lista<Box<T>*>* column = new Lista<Box<T>*>;
			row->add(column);
			for (int z = 0; z < height; z++) {
				Box<T>* box = new Box<T>;
				column->add(box);
			}
		}
	}
}


#endif #pragma once
