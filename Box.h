#ifndef BOX_H
#define BOX_H

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "Lista.h" 

template<class T>
class Box {

private:
    T data;
    int coordX;
    int coordY;
    int coordZ;
    Lista<Box<T>*> * neighbours;

public:
    Box();
    Box(T data);
    Box(int x, int y, int z);
    void setData(T data);
    void setCoordX(int x);
    void setCoordY(int y);
    void setCoordZ(int z);
    int getCoordX();
    int getCoordY();
    int getCoordZ();

    T getData();
    bool isEmpty();

    void addNeighbour(Box<T>* neighbour);

    Lista<Box<T>*>* getAllNeighbours();

};

#include "Box.h"



template<class T> 
Box<T>::Box() {
    this->data = NULL;
}

template<class T> 
Box<T>::Box(T data) {
    setData(data);
}

template<class T>
Box<T>::Box(int x, int y, int z) {
    setCoordX(x);
    setCoordY(y);
    setCoordZ(z);
    this->neighbours = new Lista<Box<T>*>();
}

template<class T>
void Box<T>::setData(T data) {
    this->data = data;
}

template<class T>
void Box<T>::setCoordX(int x) {
    this->coordX = x;
}

template<class T>
void Box<T>::setCoordY(int y) {
    this->coordY = y;
}

template<class T>
void Box<T>::setCoordZ(int z) {
    this->coordZ = z;
}

template<class T>
int Box<T>::getCoordX()
{
    return this->coordX;
}

template<class T>
int Box<T>::getCoordY()
{
    return this->coordY;
}

template<class T>
int Box<T>::getCoordZ()
{
    return this->coordZ;
}

template<class T>
T Box<T>::getData() {
    return this->data;
}

template<class T>
bool Box<T>::isEmpty(){
    return this->data == NULL;
}


template<class T>
void Box<T>::addNeighbour(Box<T>* neighbour) {
    this->neighbours->add(neighbour);
}

template<class T>
Lista<Box<T>*>* Box<T>::getAllNeighbours() {
    return this->neighbours;
}

#endif