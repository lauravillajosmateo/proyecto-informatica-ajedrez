#pragma once
#include "mundo.h"
#include "ETSIDI.h"

class menu
{
public:
	menu();
	~menu();
	void teclaEspecial(unsigned char key);
	void tecla(unsigned char key);
	void dibuja();
	void mueve();
	

protected:
	mundo mundo1;
	enum Estado{INICIO,JUEGO,FINJUEGO};
	Estado estado;
	float tiempo;
	bool audio;

};

