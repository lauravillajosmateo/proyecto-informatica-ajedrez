#pragma once
#define MOV_CORRECTO 1
#define ERROR 0 

#include "ETSIDI.h"
#include "Pieza.h"

using namespace ETSIDI;

class alfil:public Pieza
{

private:
	unsigned char rojo, verde, azul;
	int turno;
public:
	alfil();
	alfil(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();
	void mueve(float posxini, float posyini, float posxfin, float posyfin);

	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	
	int getturno();
	void setturno(int t);

};