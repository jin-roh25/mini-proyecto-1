#include <queue>
#include <algorithm>
#include "ListArr.h"

ListArr::ListArr(int maxArr) {
	this->sizeArr = maxArr;
	root = new NodeLeaf(nullptr, nullptr, maxArr);
}

ListArr::~ListArr() {
	delete(root);
}

bool ListArr::isLeaf(Nodo *nd) {
	return sizeArr == nd->getMax();
}

Nodo *ListArr::decendOne(Nodo *nd, int *ind) {
	if (isLeaf(nd)) return nd;

	if (nd->getL()->getCrrt() > *ind) {
		nd = nd->getL();
	} else {
		*ind -= nd->getL()->getCrrt();
		nd = nd->getR();
	}

	return nd;
}

NodeLeaf *ListArr::getLeaf(int ind) {
	Nodo *nd = root;
	while (!isLeaf(nd)) nd = decendOne(nd, &ind);
	return (NodeLeaf *)nd;
}
NodeLeaf *ListArr::getLeaf(int *ind) {
	Nodo *nd = root;
	while (!isLeaf(nd)) nd = decendOne(nd, ind);
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
	destroyTree(root);

	root = q.front(); // ¡¡¡¡¡¡MEMORY LEAKS!!!!!! _______________________________
}

void ListArr::destroyTree(Nodo *node) {

	if (!isLeaf(node)) {
		destroyTree(node->getR());
		destroyTree(node->getL());
		delete(node);
	}
}

int ListArr::size() { return root->getCrrt(); }
void ListArr::insert_left(int n) { this->insert(n, 0); }
void ListArr::insert_right(int n) { this->insert(n, root->getCrrt() - 1); }

void ListArr::insert(int num, int ind) {
	NodeLeaf *nd = getLeaf(ind);
	for (int i = ind;i < nd->getMax();i++) {
		std::swap(num, nd->getArray()[i]);
	}

	if (nd->getCrrt() < nd->getMax()) {
		nd->crrtPP();
		for (Nodo *i = root; !isLeaf(i);i = decendOne(i, &ind)) {
			i->crrtPP();
		}
	} else {
		NodeLeaf *newLeaf = new NodeLeaf(nd, nd->getR(), sizeArr);
		newLeaf->getArray()[0] = num;

		nd->setR(newLeaf);
		if (nd->getR() != nullptr) nd->getR()->setL(newLeaf);

		rebuildTree();
	}
}
