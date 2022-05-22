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

void menu::teclaEspecial(unsigned char key)
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
			//nivel = 1;
			tiempo = 0;
			ETSIDI::stopMusica();
			estado = JUEGO;
		}
		if (key == 's' || key == 'S')
			exit(0);
	}

	else if (estado == FINJUEGO)
	{
		if (key == 'v' || key == 'V')
		{
			mundo1.~mundo();
			audio = true;
			ETSIDI::stopMusica();
			estado = INICIO;
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
		if (tiempo > 1.5f && tiempo < 1.525f)
			ETSIDI::playMusica("sonidos/menu.mp3", true);
	}

	else if (estado == JUEGO)
		mundo1.dibuja();
	else if (estado == FINJUEGO)
	{
		gluLookAt(0, 7.5, 30,
			0.0, 7.5, 0.0,
			0.0, 1.0, 0.0);

		ETSIDI::setTextColor(255, 255, 255);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 25);
		ETSIDI::printxy("JAQUEMATE", -3, 9);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -V- PARA VOLVER", -5, 6);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 5);
		if (audio) {
			ETSIDI::play("sonidos/derrota.mp3");
			audio = false;
		}
	}
}

void menu::mueve()
{
	if (estado == JUEGO) {
		mundo1.mueve();
		mundo1.dibuja();
		mundo1.hayjaqueB();
		mundo1.hayjaqueN();
		if (mundo1.final() == 1)
		{
			estado = FINJUEGO;
			cout << "FIN DEL JUEGO, HAS COMIDO AL REY" << endl;
			exit(0);
		}
	}
	
}

