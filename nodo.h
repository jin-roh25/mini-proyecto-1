#ifndef Nodo_H
#define Nodo_H

class nodo
{
private:
	int crrt, max;
	nodo *L, *R;
public:
	nodo(nodo *, nodo *, int);
	~nodo();

	nodo *getL();
	nodo *getR();
	int getMax();

	int getCrrt();
	void setCrrt(int n);
	void crrtPP();
};

#endif