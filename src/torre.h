#pragma once


#include "Pieza.h"

class torre:public Pieza
{
private:

public:
	torre():Pieza(){}
	torre(Vector ptorre,int c);

	void dibuja();

	int mov_correcto(Vector);
	void movimientos(Vector);
	
};

