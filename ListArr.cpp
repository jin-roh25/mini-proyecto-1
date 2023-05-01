#include "ListArr.h"

ListArr::ListArr(int maxArr){
    raiz = new nodo(nullptr,nullptr,maxArr);
}

ListArr::~ListArr(){
    delete(raiz);
}

int ListArr::size() {return raiz->getCrrt()}
void ListArr::insert_left(int n) this->insert(n,0);
void ListArr::insert_left(int n) {this->insert(n,raiz->getCrrt()-1)}
