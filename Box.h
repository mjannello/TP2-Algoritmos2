#ifndef BOX_H
#define BOX_H

template<class T> class Box {
private:
    T data;

public:
    Box();
    Box(T data);
    T getData();

};

#include "Box.h"



template<class T> Box<T>::Box() {
}

template<class T> Box<T>::Box(T data) {
    this->data = data;
}

template<class T> T Box<T>::getData() {
    return this->data;
}

#endif