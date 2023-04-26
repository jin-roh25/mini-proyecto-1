#include "nodo.h"

nodo::nodo(nodo *L, nodo *R, int max) {
	this->L = R;
	this->R = R;
	this->max = max;
	this->crrt = 0;
}

nodo::~nodo(){
	if (L != nullptr) delete(L);
	if (R != nullptr) delete(R);
	delete(this);
}

