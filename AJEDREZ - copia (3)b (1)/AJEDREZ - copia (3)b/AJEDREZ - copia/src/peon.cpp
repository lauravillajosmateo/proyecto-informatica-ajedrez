#include "peon.h"
#include "freeglut.h"
#include <iostream>

using namespace std;

peon::peon() {
	rojo = verde = azul = 175;
	posxini = posyini = 0;

	avanza = 0;
	come = 0;

}

peon::peon(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
	posxini = x;
	posyini = y;

}

void peon::dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini, posyini, 0);
	glutSolidSphere(0.25, 20, 20);
	glTranslatef(-posxini, -posyini, 0);
}

void peon::setcolor(unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
}

void peon::setpos(float x, float y) {
	posxini = x;
	posyini = y;
}

int peon::mov_correcto(float posxfin, float posyfin) {

	if (posyini == 6.5) {
		if (posxfin == posxini && posyfin == posyini - 1 && avanza == 1) {
			return AVANZA1;
		}
		else if (posxfin == posxini && posyfin == posyini - 2 && avanza == 1)
			return AVANZA2;
		else if (((posxfin == posxini - 1 && posyfin == posyini - 1) || (posxfin == posxini + 1 && posyfin == posyini - 1)) && come == 1)
		{
			cout << "COMIDO" << endl;
			return COME;
		}
	}

	else if (posxfin == posxini && posyfin == posyini - 1 && avanza==1)
			return AVANZA1;

	else if (((posxfin == posxini - 1 && posyfin == posyini - 1) || (posxfin == posxini + 1 && posyfin == posyini - 1)) && come==1) {
			cout << "COMIDO" << endl;
			return COME;
		}
	else {
			cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
			return ERROR;

		}
	}


void peon::mueve(float posxfin, float posyfin) {

	movimientos(posxfin, posyfin);
}





	void peon::movimientos(float posxfin, float posyfin) {
		switch (mov_correcto(posxfin, posyfin)) {
		case (AVANZA1):
		{

			posyini = posyini - 1;
			break;

		}

		case (AVANZA2):
		{
			posyini = posyini - 2;
			break;
		}

		case (COME):
		{
			posxini =posxfin;
			posyini =posyfin;
			break;
		}

		}
	}


float peon::getposx() {
	return posxini;
}

float peon::getposy() {
	return posyini;
}