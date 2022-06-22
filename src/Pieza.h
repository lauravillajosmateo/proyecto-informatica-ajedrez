#pragma once

#include "ETSIDI.h"
#include "Vector.h"

#define MOV_CORRECTO 1
#define ERROR 0 

using namespace ETSIDI;

typedef enum {BLANCO=0, NEGRO};

class Pieza {
protected:
	
	Vector origen;

	int turno;
	int color;

public:
	Pieza();
	void setpos(Vector posicion);

	Vector getpos();


	virtual void dibuja() = 0;
	void mueve(Vector inicio, Vector final);
	virtual int mov_correcto(Vector ) = 0;
	virtual void movimientos(Vector) = 0;

	int getturno();

	void setturno(int t);
	


};
