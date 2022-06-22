#pragma once
#define MOV_CORRECTO 1

#include "Pieza.h"

class torre:public Pieza
{
private:

public:
	torre();
	torre(float x, float y, unsigned char r, unsigned char a, unsigned char v);

	void dibuja();

	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);

	int getturno();
	void setturno(int t);
};

