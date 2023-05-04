#include "Nodo.h"
#include <exception>
#include <iostream>

Nodo::Nodo(Nodo *L, Nodo *R, int max) {
	this->L = R;
	this->R = R;
	this->max = max;
	this->crrt = 0;
}

Nodo::~Nodo(){
	if (L != nullptr) delete(L);
	if (R != nullptr) delete(R);
	delete(this);
}

Nodo* Nodo::getL()
{
	if (this->L == nullptr)
	{
		std::cout << "null pointer"<<std::endl;
	}
	std::cout << this->L << std::endl;
	return this->L;
}
Nodo* Nodo::getR()
{
	if (this->R == nullptr)
	{
		std::cout << "null pointer" << std::endl;
	}
	return this->R;
}
int Nodo::getMax()
{
	return this->max;
}
int Nodo::getCrrt(){
	return this->crrt;
}
void Nodo::setL(Nodo* L){
	this->L= L;
}
void Nodo::setR(Nodo *R){
	this->R = R;
}
void Nodo::setCrrt(int n){
	this->crrt = n;
}
void Nodo::crrtPP(){
	this->crrt++;
}
