#pragma once

#include "Pieza.h"

class reina:public Pieza
{
private:
	
public:
	reina():Pieza(){}
	reina(Vector preina, int c):Pieza(preina, c, false) {}

	void dibuja();

	int mov_correcto(Vector, ListaPiezas&);
	void movimientos(Vector, ListaPiezas&);

};

