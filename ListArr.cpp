#include <queue>
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

	while (!isLeaf(nd) && nd != nullptr) {
		if (nd->getL()->getCrrt() > ind) {
			nd = nd->getL();
		} else {
			ind -= nd->getL()->getCrrt();
			nd = nd->getR();
		}
	}

	return (NodeLeaf *)nd;
}

void ListArr::rebuildTree() {
	std::queue<Nodo *> q;

	Nodo *nd = getLeaf(0);
	while (nd != nullptr) {
		if (nd->getR() == nullptr) {
			q.push(nd);
			break;
		} else {
			q.push(new Nodo(nd, nd->getR(), sizeArr * 2));
		}

		nd = nd->getR()->getR();
	}

	if (q.size() > 1) for (int i = q.size();i >= 0;i -= 2) {
		if (i == 0) {
			if (q.size() == 1) break;

			i += q.size();
		} else if (i == 1) {
			q.push(q.front());
			q.pop();

			i += q.size() - 1;
		} else {
			Nodo *nd1 = q.front();
			q.pop();
			Nodo *nd2 = q.front();
			q.pop();

			q.push(new Nodo(nd1, nd2, nd1->getMax() + nd2->getMax()));
		}
	}

	raiz = q.front(); // ¡¡¡¡¡¡MEMORY LEAKS!!!!!! _______________________________
}

int ListArr::size() { return raiz->getCrrt(); }
void ListArr::insert_left(int n) { this->insert(n, 0); }
void ListArr::insert_right(int n) { this->insert(n, raiz->getCrrt() - 1); }

void ListArr::insert(int num, int ind) {
	NodeLeaf *nd = getLeaf(ind);

	if (nd->getCrrt() < nd->getMax()) {

	}
}
