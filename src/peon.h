#pragma once
#define ERROR 0
#define AVANZA1 3
#define AVANZA2 2
#define COME 1

#include "Pieza.h"

class peon:public Pieza {

public:
	peon():Pieza(){}
	peon(Vector v, int c);

	void dibuja();

	int mov_correcto(Vector, ListaPiezas&);
	void movimientos(Vector, ListaPiezas&);

};
