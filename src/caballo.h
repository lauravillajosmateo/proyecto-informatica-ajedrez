#pragma once
#define MOV_CORRECTO 1

#include "Pieza.h"

class caballo:public Pieza
{
private:

public:
	caballo():Pieza(){}
	caballo(Vector  pcaballo, int c):Pieza(pcaballo,c,false){}
	void dibuja();
	
	void movimientos(Vector,ListaPiezas&);
	int mov_correcto(Vector,ListaPiezas&);
	

};
