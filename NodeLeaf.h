#ifndef NodeLeaf_H
#define NodeLeaf_H
#include "Nodo.h"

class NodeLeaf : public Nodo
{
private:
    int *array;
public:
    NodeLeaf(Nodo *L, Nodo *R, int maxSize);
    ~NodeLeaf();
    int* getArray();
};
#endif
