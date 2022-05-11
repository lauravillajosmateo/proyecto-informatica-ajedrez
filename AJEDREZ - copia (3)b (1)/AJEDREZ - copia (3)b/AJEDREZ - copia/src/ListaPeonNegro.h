
#pragma once
#include "peonn.h"
#define MAX_PEON 10

class ListaPeonNegro {

private:
	peonn* lista[MAX_PEON];
	int numero;

public:
	ListaPeonNegro();

	void mueve(float posx, float posy, float posxfin, float posyfin);
	bool agregar(peonn* p);
	void dibuja();


	float getx(int indice);
	float gety(int indice);

};