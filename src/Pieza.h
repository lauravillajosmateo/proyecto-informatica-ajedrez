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
	int mover;

public:
	Pieza();
	Pieza(Vector v, int c, int m);
	void setpos(Vector posicion);

	Vector getpos();

	virtual void dibuja() = 0;
	virtual int mov_correcto(Vector, ListaPiezas) = 0;
	virtual void movimientos(Vector,ListaPiezas) = 0;
	int getturno();
	void setturno(int t);
	int casillalibre(Vector v, ListaPiezas l);


};
