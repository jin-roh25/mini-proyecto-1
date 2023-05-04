#include <iostream>
#include <typeinfo> 
#include "NodeLeaf.h"

using namespace std;

int main(int argc, char const *argv[])
{

	NodeLeaf *node = new NodeLeaf(nullptr, nullptr, 5);
	NodeLeaf *node2 = new NodeLeaf(nullptr, nullptr, 5);
	Nodo *nd = new NodeLeaf(nullptr, nullptr, 5);

	node->setL(node2);

	cout << ((NodeLeaf *)node->getL())->getArray() << endl;

	cout << is_same<decltype(node), decltype(node->getL())>() << endl;

	cout << typeid(*nd).name() << "  " << typeid(*node->getL()).name() << endl;

	return 0;
}
