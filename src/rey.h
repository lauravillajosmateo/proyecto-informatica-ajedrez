#pragma once
#include "ETSIDI.h"
#include "Pieza.h"

class rey:public Pieza {
private:
	
public:
	rey():Pieza(){}
	rey(Vector prey,int c);
	void dibuja();
	int mov_correcto(Vector,ListaPiezas);
	void movimientos(Vector,ListaPiezas);
};
