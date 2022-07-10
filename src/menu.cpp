#include "menu.h"
#include <iostream>

using namespace std;

menu::menu()
{
	estado = INICIO;
	tiempo = 0.000f;
	audio = true;
}

menu::~menu()
{
}

void menu::tecla(unsigned char key)
{
	if (estado == INICIO)
	{
		if (key == 'e' || key == 'E')
		{
			mundo1.inicializa();
			audio = true;
			tiempo = 0;
			ETSIDI::stopMusica();
			estado = JUEGO;
		}
		if (key == 's' || key == 'S')
			exit(0);
	}

}

void menu::dibuja()
{
	if (estado == INICIO)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 32);
		ETSIDI::printxy("AJEDREZ", -4, 11);
		ETSIDI::printxy("ANGELES Y DEMONIOS", -9, 9);
		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -6, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -6, 6);
		ETSIDI::printxy("Asier Mino", 2, 3);
		ETSIDI::printxy("Eva Gomez", 2, 2);
		ETSIDI::printxy("Sergio Cabo", 2, 1);
		ETSIDI::printxy("Marta Seisdedos", 2, 4);
		ETSIDI::printxy("Laura Villajos", 2, 5);
		if (audio) {
			ETSIDI::play("sonidos/inicio.mp3");
			audio = false;
			tiempo = 0;
		}
		
	}

	else if (estado == JUEGO)
			mundo1.dibuja();
}

void menu::mueve()
{
	if (estado == JUEGO) {
		ETSIDI::playMusica("sonidos/ambiente.mp3", true);
		mundo1.mueve();
		mundo1.dibuja();	
	}
}
