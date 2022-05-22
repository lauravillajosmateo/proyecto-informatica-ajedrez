#pragma once
#define MOVIMIENTO_CORRECTO 1
#define ERROR 0

#include "Pieza.h"

class reina:public Pieza
{
private:
	unsigned char rojo, verde, azul;
	int turno;
public:
	reina();
	reina(float x, float y, unsigned char r, unsigned char a, unsigned char v);

	void dibuja();

	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);

	int getturno();
	void setturno(int t);
};

