#include <queue>
#include <algorithm>
#include <iostream>
#include "ListArr.h"

using namespace std;

ListArr::ListArr(int maxArr) {
	this->sizeArr = maxArr;
	root = new NodeLeaf(nullptr, nullptr, maxArr);
}

ListArr::ListArr(int maxArr, int size) {
	this->sizeArr = maxArr;
	NodeLeaf *aux = new NodeLeaf(nullptr, nullptr, maxArr);
	root = aux;
	for (int i = 0; i < size; i++)
	{
		aux->getArray()[i%maxArr];
		if(i!=0 && i%maxArr==0){
			aux->setR(new NodeLeaf(aux, nullptr, maxArr));
			aux = (NodeLeaf*)aux->getR();
		}
	}
	
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
			q.push(new Nodo(nd, nd->getR(), nd->getCrrt() + nd->getR()->getCrrt(), sizeArr * 2));
		}

		nd = nd->getR()->getR();
	}

	if (q.size() > 1) for (int i = q.size();i >= 0;i -= 2) {
		if (i == 0) {
			i = q.size();
		} else if (i == 1) {
			q.push(q.front());
			q.pop();

			i = q.size() + 2;
			continue;
		}
		Nodo *nd1 = q.front();
		q.pop();
		Nodo *nd2 = q.front();
		q.pop();

		q.push(new Nodo(nd1, nd2, nd1->getCrrt() + nd2->getCrrt(), nd1->getMax() + nd2->getMax()));


		if (q.size() == 1) break;
	}
	destroyTree(root);

	root = q.front();
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
	int aux = ind;
	NodeLeaf *nd = getLeaf(&ind);
	for (int i = ind % (sizeArr + 1);i < nd->getMax();i++) {
		std::swap(num, nd->getArray()[i]);
	}
	ind = aux;

	if (nd->getCrrt() < nd->getMax()) {
		nd->crrtPP();
		for (Nodo *i = root; !isLeaf(i);i = decendOne(i, &ind)) {
			i->crrtPP();
		}
	} else {
		NodeLeaf *newLeaf = new NodeLeaf(nd, nd->getR(), sizeArr);
		newLeaf->getArray()[0] = num;
		newLeaf->crrtPP();

		nd->setR(newLeaf);
		if (nd->getR() != nullptr) nd->getR()->setL(newLeaf);

		rebuildTree();
	}
}

void ListArr::print() {

	NodeLeaf *leaf = getLeaf(0);
	for (int i = 0; i < leaf->getCrrt(); i++)
	{
		cout << leaf->getArray()[i] << " ";
		if (leaf->getR() != nullptr && i == leaf->getCrrt() - 1)
		{
			leaf = (NodeLeaf *)leaf->getR();
			i = -1;
		}
	}
	cout << endl;
}

bool ListArr::find(int num) {

	NodeLeaf *leaf = getLeaf(0);
	for (int i = 0; i < leaf->getCrrt(); i++)
	{
		if (num == leaf->getArray()[i]) {
			return true;
		}
		if (i == leaf->getCrrt() - 1 && leaf->getR() != nullptr)
		{
			leaf = (NodeLeaf *)leaf->getR();
			i = -1;
		}

	}
	return false;
}
