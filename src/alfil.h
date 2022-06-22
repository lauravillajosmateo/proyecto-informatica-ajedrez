#pragma once



#include "Pieza.h"




class alfil:public Pieza
{

private:

public:
	alfil(): Pieza(){}
	alfil(Vector palfil, int c);
	void dibuja();
	

	int mov_correcto(Vector);
	void movimientos(Vector);
	
	

};
