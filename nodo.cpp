#include "nodo.h"
#include <exception>
#include <iostream>

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

nodo* nodo::getL()
{
	if (this->L == nullptr)
	{
		std::cout << "null pointer"<<std::endl;
	}
	std::cout << this->L << std::endl;
	return this->L;
}
nodo* nodo::getR()
{
	if (this->R == nullptr)
	{
		std::cout << "null pointer" << std::endl;
	}
	return this->R;
}
int nodo::getMax()
{
	return this->max;
}
int nodo::getCrrt(){
	return this->crrt;
}
void nodo::setL(nodo* L){
	this->L= L;
}
void nodo::setR(nodo *R){
	this->R = R;
}
void nodo::setCrrt(int n){
	this->crrt = n;
}
void nodo::crrtPP(){
	this->crrt++;
}
