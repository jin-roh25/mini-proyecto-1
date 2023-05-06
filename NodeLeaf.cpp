#include "NodeLeaf.h"

NodeLeaf::NodeLeaf(Nodo *L, Nodo *R, int size) :Nodo(L, R, size){
	this->array = new int[size];
}
NodeLeaf::~NodeLeaf() {
	delete (array);
}
int *NodeLeaf::getArray() {
	return array;
}