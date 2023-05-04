#include "ListArr.h"

ListArr::ListArr(int maxArr) {
	this->sizeArr = maxArr;
	raiz = new NodeLeaf(nullptr, nullptr, maxArr);
}

ListArr::~ListArr() {
	delete(raiz);
}

bool ListArr::isLeaf(Nodo *nd) {
	return sizeArr == nd->getMax();
}

NodeLeaf *ListArr::getLeaf(int ind) {
	Nodo *nd = raiz;

	while (!isLeaf(nd)) {
		if (nd->getL()->getCrrt() > ind) {
			nd = nd->getL();
		} else {
			ind -= nd->getL()->getCrrt();
			nd = nd->getR();
		}
	}

	return (NodeLeaf *)nd;
}


int ListArr::size() { return raiz->getCrrt(); }
void ListArr::insert_left(int n) { this->insert(n, 0); }
void ListArr::insert_right(int n) { this->insert(n, raiz->getCrrt() - 1); }

void ListArr::insert(int n, int ind) {
	

}
