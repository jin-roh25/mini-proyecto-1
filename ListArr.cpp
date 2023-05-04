#include "ListArr.h"

ListArr::ListArr(int maxArr) {
	this->sizeArr = maxArr;
	raiz = new Nodo(nullptr, nullptr, maxArr);
}

ListArr::~ListArr() {
	delete(raiz);
}

NodeLeaf *ListArr::getLeaf(int ind) {
return nullptr;
}


int ListArr::size() { return raiz->getCrrt(); }
void ListArr::insert_left(int n) { this->insert(n, 0); }
void ListArr::insert_right(int n) { this->insert(n, raiz->getCrrt() - 1); }

void ListArr::insert(int v, int i) {

}
