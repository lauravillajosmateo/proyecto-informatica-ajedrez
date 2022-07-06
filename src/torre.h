#pragma once


#include "Pieza.h"

class torre:public Pieza
{
private:

public:
	torre():Pieza(){}
	torre(Vector ptorre,int c):Pieza(ptorre, c, false) {}

	void dibuja();

	int mov_correcto(Vector,ListaPiezas&);
	void movimientos(Vector,ListaPiezas&);
	
};

