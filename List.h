#ifndef LIST_H
#define LIST_H

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "Node.h"

template<class T> class List {
private:
	Node<T>* first;
	unsigned int size;
	Node<T>* cursor;
public:
	List();
	List(List<T>& anotherList);
	bool empty()const;
	unsigned int countElements()const;
	void add(T element);
	void add(T element, unsigned int position);
	void add(List<T>& anotherList);
	T get(unsigned int position);
	void set(T element, unsigned int position);
	void remove(unsigned int position);
	void resetCursor();
	bool moveCursor();
	T getCursor()const;
	~List();
private:
	Node<T>* getNode(unsigned int posicion)const;
};

#include "List.h"


template<class T> List<T>::List() {
	this->first = NULL;
	this->size = 0;
	this->cursor = NULL;
}

/* POST: List equal to passed list. */
template<class T> List<T>::List(List<T>& otraLista) {
	this->first = NULL;
	this->size = 0;
	this->cursor = NULL;
	this->add(otraLista);
}

/* POST: Tells whether the list has any element. */
template<class T> bool List<T>::empty()const {
	return (this->size == 0);
}

/* POST: Returns the amount of elements in the list. */
template<class T> unsigned int List<T>::countElements()const {
	return (this->size);
}

/* POST: Adds element at the end of the list (position countElements() + 1). */
template<class T> void List<T>::add(T elemento) {
	this->add(elemento, this->size + 1);
}

/* PRE: Position is between [1 , countElements() + 1].
 * POST: Adds the element in passed position. */
template<class T> void List<T>::add(T elemento, unsigned int posicion) {
	if ((posicion > 0) && (posicion <= this->size + 1)) { /* posición válida */
		Node<T>* nuevoNodo = new Node<T>(elemento);
		if (posicion == 1) {
			nuevoNodo->setNext(this->first);
			this->first = nuevoNodo;
		}
		else {
			Node<T>* nodoAnterior = this->getNode(posicion - 1);
			nuevoNodo->setNext(nodoAnterior->getNext());
			nodoAnterior->setNext(nuevoNodo);
		}
		this->size++;
		this->resetCursor();
	}
}

/* POST: Adds all elements from passed list at the end of the list,
 *  that's from position countElements() + 1. */
template<class T> void List<T>::add(List<T>& otraLista) {
	otraLista.resetCursor();
	while (otraLista.moveCursor()) {
		this->add(otraLista.getCursor());
	}
}

/* PRE: Position is between [1 , countElements()].
 * POST: Returns the element in that position. */
template<class T> T List<T>::get(unsigned int posicion) {
	if ((posicion <= 0) || (posicion > this->size)) {
		throw "POSICION INVALIDA";
	}
	return (this->getNode(posicion)->getValue());
}

/* PRE: Position is between [1 , countElements()].
 * POST: Changes element in that position to passed element. */
template<class T> void List<T>::set(T elemento, unsigned int posicion) {
	if ((posicion > 0) && (posicion <= this->size)) {
		this->getNode(posicion)->setValue(elemento);
	}
}

/* PRE: Position is between [1 , countElements()].
 * POST: Removes element in that position from the list. */
template<class T> void List<T>::remove(unsigned int posicion) {
	if ((posicion > 0) && (posicion <= this->size)) {
		Node<T>* nodoRemovido;
		if (posicion == 1) {
			nodoRemovido = this->first;
			this->first = this->first->getNext();
		}
		else {
			Node<T>* nodoAnterior = this->getNode(posicion - 1);
			nodoRemovido = nodoAnterior->getNext();
			nodoAnterior->setNext(nodoRemovido->getNext());
		}
		delete nodoRemovido;
		this->size--;
		this->resetCursor();
	}
}

/* POST: Leaves cursor ready for new iteration. */
template<class T> void List<T>::resetCursor() {
	this->cursor = NULL;
}

/* Allows to move the cursor from a node to the next one.
 * PRE: Iteration has been initiated (by method resetCursor()),
 *  and no elements have been added or removed since then.
 * POST: Moves cursor to the next element in the iteration.
 *  Return value tells whether cursor now stands on and element or not,
 *  (in case the list is empty or there aren't any more elements). */
template<class T> bool List<T>::moveCursor() {
	if (this->cursor == NULL) {
		this->cursor = this->first;
	}
	else {
		this->cursor = this->cursor->getNext();
	}
	return (this->cursor != NULL);
}

/* PRE: Cursor is standing on an element of the list,
 *  (method advanceCursor() was called and returned "true").
 * POST: Returns element in the cursor's position. */
template<class T> T List<T>::getCursor()const {
	if (this->cursor == NULL) {
		throw "CURSOR ESTA NULL";
	}
	return (this->cursor->getValue());
}

/* POST: Liberates resources associated to the list. */
template<class T> List<T>::~List() {
	while (this->first != NULL) {
		Node<T>* nodoRemovido = this->first;
		this->first = this->first->getNext();
		delete nodoRemovido;
	}
}

/* PRIVATE: */

/* PRE: Position is between [1 , countElements()].
 * POST: Returns the node in that position (pointer). */
template<class T> Node<T>* List<T>::getNode(unsigned int posicion)const {
	Node<T>* nodoActual = this->first;
	for (unsigned int i = 1; i < posicion; i++) {
		nodoActual = nodoActual->getNext();
	}
	return nodoActual;
}
#endif /* SRC_ESTRUCTURAS_LISTA_H_ */