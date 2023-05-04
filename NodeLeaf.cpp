#include "NodeLeaf.h"

NodeLeaf::NodeLeaf(Nodo *L, Nodo *R, int max, int size):Nodo(L,R,max)
{
    this->array = new int[size];
}
NodeLeaf::~NodeLeaf(){
    if (array != nullptr) delete (array);
    this->~Nodo();
}
int* NodeLeaf::getArray(){
    return array;
}
