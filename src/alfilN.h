#pragma once
#define MOV_CORRECTO 1
#define ERROR 0
#include "Pieza.h"

class alfilN:public Pieza
{
private:
	unsigned char rojo, verde, azul;
	int turno;
public:
	alfilN();
	alfilN(float x, float y, unsigned char r, unsigned char a, unsigned char v);

	void dibuja();
	void mueve(float posxini, float posyini, float posxfin, float posyfin);

	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);

	int getturno();
	void setturno(int t);

};

