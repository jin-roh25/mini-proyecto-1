#ifndef ListArr_H
#define ListArr_H
#include "NodeLeaf.h"

class ListArr
{
private:
	Nodo *raiz;
	int sizeArr;

	bool isLeaf(Nodo *);
	NodeLeaf *getLeaf(int indice); // retorna la hoja en la que esta la posicion "indice" (no la hoja numero "indice")
public:
	ListArr(int);
	~ListArr();

	int size(); // Retorna la cantidad de elementos almacenados en el ListArr
	void insert_left(int valor); // Inserta un nuevo valor v a la izquierda del ListArr. Equivalentemente, inserta el valor v en el índice 0
	void insert_right(int valor); // Inserta un nuevo valor v a la derecha del ListArr. Equivalentemente, inserta el valor v en el índice size()-1
	void insert(int valor, int indice); // Inserta un nuevo valor v en el índice i del ListArr.
	void print(); // Imprime por pantalla todos los valores almacenados en el ListArr.
	bool find(int valor); // Busca en el ListArr si el valor v se encuentra almacenado.

};

#endif