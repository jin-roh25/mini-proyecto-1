#ifndef NodeLeaf_H
#define NodeLeaf_H
#include "Nodo.h"

class NodeLeaf : public Nodo
{
private:
    int *array;
public:
    NodeLeaf(Nodo *, Nodo *, int, int);
    ~NodeLeaf();
    int* getArray();
};

#endif
