#include <iostream>
#include <algorithm>
#include "NodeLeaf.h"
#include "ListArr.h"

using namespace std;

int main(int argc, char const *argv[])
{


    //ListArr* la =new ListArr(5);

    ListArr* tree = new ListArr(4);
    int c;

    cin >> c;

    for (int i = 0; i < c; i++)
    {
        tree->insert(i+1,i);
        cout << "size: " << tree->size() << endl;
    }
    
    tree->print();

    //cout << ((NodeLeaf *)node->getL())->getArray() << endl;

    return 0;
}
