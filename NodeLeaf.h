#ifndef NodeLeaf_H
#define NodeLeaf_H
#include "nodo.h"

class NodeLeaf : public nodo
{
private:
    int *array;
public:
    NodeLeaf(nodo *, nodo *, int, int);
    ~NodeLeaf();
    int* getArray();
};

#endif
