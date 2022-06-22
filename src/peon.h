#pragma once
#define ERROR 0
#define AVANZA1 1
#define AVANZA2 2
#define COME 3

#include "Pieza.h"

class peon:public Pieza {
public:
	int come;
	int avanza;

public:
	peon():Pieza(){}
	peon(Vector v, int c);

	void dibuja();

	int mov_correcto(Vector);
	void movimientos(Vector);

};
