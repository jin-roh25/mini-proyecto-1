#ifndef Nodo_H
#define Nodo_H

class Nodo
{
private:
	int crrt, max;
	Nodo *L, *R;
public:
	Nodo(Nodo *, Nodo *, int);
	~Nodo();

	Nodo *getL();
	Nodo *getR();
	int getMax();int getCrrt();

	void setL(Nodo*);
	void setR(Nodo*);
	void setCrrt(int n);
	void crrtPP();
};

#endif