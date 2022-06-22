#pragma once
#include "peon.h"
#define MAX_PEON 10

class ListaPeonBlanco {
private:
	peon* lista[MAX_PEON];
	int numero;

public:
	ListaPeonBlanco();

	void mueve(Vector, Vector);
	bool agregar(peon* p);
	void dibuja();

	void cambiacome(int indice);
	void cambiavanza(int indice);


	float getx(int indice);
	float gety(int indice);



	int compara(Vector);
	bool comprobacioncome(int indice, float posxfinf, float posyfinf);
	void setpos(int indice, float posx, float posy);

	void setturno(int t);
	int getturno();


};
