#ifndef BOX_H
#define BOX_H

#ifndef NULL
#define NULL 0
#endif /* NULL */

template<class T>
class Box {

private:
    T data;

public:
    Box();
    Box(T data);
    void setData(T data);
    T getData();
    bool isEmpty();

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
void Box<T>::setData(T data) {
    this->data = data;
}


template<class T>
T Box<T>::getData() {
    return this->data;
}

template<class T>
bool Box<T>::isEmpty(){
    return this->data == NULL;
}

#endif