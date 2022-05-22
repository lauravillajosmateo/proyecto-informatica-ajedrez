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
	void teclaRaton(int button, int state, int x, int y);
	void teclaRaton2(int x, int y);

protected:
	mundo mundo1;
	enum Estado{INICIO,JUEGO,FINJUEGO,PAUSA};
	Estado estado;
	float tiempo;
	bool audio;
	int nivel;

};

