#ifndef NODE_H
#define NODE_H

#ifndef NULL
#define NULL 0
#endif /* NULL */

template<class T> class Node {
private:
	T data;
	Node<T>* next;
public:
	Node(T valor);
	bool hasNext();
	Node<T>* getNext();
	void setNext(Node<T>* nuevoSig);
	T getValue();
	void setValue(T nuevoValor);
	~Node();
};


template<class T> Node<T>::Node(T valor) {
	this->data = valor;
	this->next = NULL;
}

template<class T> bool Node<T>::hasNext() {
	return (this->next != NULL);
}

template<class T> Node<T>* Node<T>::getNext() {
	return (this->next);
}

template<class T> void Node<T>::setNext(Node<T>* nuevoSig) {
	this->next = nuevoSig;
}

template<class T> T Node<T>::getValue() {
	return (this->data);
}

template<class T> void Node<T>::setValue(T nuevoValor) {
	this->data = nuevoValor;
}

template<class T> Node<T>::~Node() {

}

#endif /* SRC_ESTRUCTURAS_NODO_H_ */