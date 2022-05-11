#pragma once


#include "tablero.h"

class mundo
{


public:
	float x;
	float y;
	float z;



public:
	mundo();
	void inicializa();
	void dibuja();
	void mueve();
	void tecla(unsigned char key);

	tablero tablero1;




};
