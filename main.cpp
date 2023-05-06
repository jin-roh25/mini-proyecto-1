#include <iostream>
#include <algorithm>
#include "NodeLeaf.h"
#include "ListArr.h"

using namespace std;

int main(int argc, char const *argv[])
{

    NodeLeaf *node2 = new NodeLeaf(nullptr, nullptr, 5);
    NodeLeaf *node = new NodeLeaf(nullptr, nullptr, 5);

    node->setL(node2);

    //ListArr* la =new ListArr(5);

    int a = 69, b = 420;
    cout << a << "  " << b << endl;
    swap(a,b);
    cout << a << "  " << b << endl;


    //cout << ((NodeLeaf *)node->getL())->getArray() << endl;

    return 0;
}
