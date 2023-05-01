#include "nodo.h"

nodo::nodo(nodo *L, nodo *R, int max) {
	this->L = R;
	this->R = R;
	this->max = max;
	this->crrt = 0;
	this->array= nullptr;
}

nodo::nodo(nodo *L, nodo *R, int max, int size) {
	this->L = R;
	this->R = R;
	this->max = max;
	this->crrt = 0;
	this->array= new int[size];
}

nodo::~nodo(){
	if (L != nullptr) delete(L);
	if (R != nullptr) delete(R);
	if (array != nullptr) delete(array);
	delete(this);
}

nodo::nodo *getL(){
	return this->L;
}
nodo::nodo *getR(){
	return this->R;
}
nodo::int getMax(){
	return this->max;
}
nodo::int getCrrt(){
	return this->crrt;
}
nodo::void setCrrt(int n){
	this->crrt = n;
}
nodo::void crrtPP(){
	this->crrt++;
}
