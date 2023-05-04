# include <iostream>
#include "NodeLeaf.h"

int main(int argc, char const *argv[])
{
    
    NodeLeaf* node= new NodeLeaf(nullptr,nullptr,55,5);
    NodeLeaf *node2 = new NodeLeaf(nullptr, nullptr, 55, 5);

    node->setL(node2);

    std::cout << node->getL()->getArray() << std::endl;

    std::cout << ((NodeLeaf*)node->getL())->getArray() << std::endl;

    return 0;
}
