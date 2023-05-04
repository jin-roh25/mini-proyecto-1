#include "NodeLeaf.h"

NodeLeaf::NodeLeaf(Nodo *L, Nodo *R, int size) :Nodo(L, R, size)
{
	this->array = new int[size];
}
NodeLeaf::~NodeLeaf() {
	if (array != nullptr) delete (array);
	Nodo::~Nodo();
}
int *NodeLeaf::getArray() {
	return array;
}
