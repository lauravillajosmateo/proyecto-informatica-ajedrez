#pragma once
#define MOV_CORRECTO 1
#define ERROR 0

#include "Pieza.h"

class reyN:public Pieza
{
private:
	unsigned char rojo, verde, azul;
	int turno;
public:
	reyN();
	reyN(float x, float y, unsigned char r, unsigned char a, unsigned char v);

	void dibuja();
	
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);
	void movimientos(float posxfin, float posyfin);
	int mov_correcto(float posxfin, float posyfin);

	int getturno();
	void setturno(int t);

};

