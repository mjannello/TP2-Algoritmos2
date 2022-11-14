#ifndef BOX_H
#define BOX_H

#ifndef NULL
#define NULL 0
#endif /* NULL */

#include "List.h" 

#include <iostream>
using namespace std;

template<class T>
class Box {

private:
    T data;
    int coordX;
    int coordY;
    int coordZ;
    List<Box<T>*> * neighbours;

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
    
    void applyNeighboursBehaviour();


    List<Box<T>*>* getAllNeighbours();
    List<T>* getElementsOfNeighbours();
    void nextState();

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
    this->neighbours = new List<Box<T>*>();
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
List<Box<T>*>* Box<T>::getAllNeighbours() {
    return this->neighbours;
}


template<class T>
void Box<T>::applyNeighboursBehaviour()
{
    int cantidadVecinos = getAllNeighbours()->countElements();
    List<Box<T>*>* vecinos = getAllNeighbours();
    for (int i = 1; i <= cantidadVecinos; i++)
    {
        Box* box = vecinos->get(i);
        T vecino = box->getData();
        vecino->applyBehaviour(this->data);
    }

}


template<class T>
List<T>* Box<T>::getElementsOfNeighbours(){
    List<T>* elements = new List<T>();
    List<Box<T>*>* neighbours = getAllNeighbours();
    for (unsigned int i = 1; i <= neighbours->countElements(); i++)
    {
        T element = neighbours->get(i)->getData();
        elements->add(element);
    }
    return elements;

}

template<class T>
void Box<T>::nextState() {
    List<T>* elements = getElementsOfNeighbours();
    this->getData()->applyNextStateStrategy(elements);
}


#endif