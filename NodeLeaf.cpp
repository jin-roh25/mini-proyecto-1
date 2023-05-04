#include "NodeLeaf.h"

NodeLeaf::NodeLeaf(nodo *L, nodo *R, int max, int size):nodo(L,R,max)
{
    this->array = new int[size];
}
NodeLeaf::~NodeLeaf(){
    if (array != nullptr) delete (array);
    this->~nodo();
}
int* NodeLeaf::getArray(){
    return array;
}
