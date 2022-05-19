#include "peonn.h"
#include "freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;

peonn::peonn() {
	rojo = verde = azul = 0;
	posxini = posyini = 0;

	avanza = 0;
	come = 0;
	turno = 1;
}

peonn::peonn(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
	posxini = x;
	posyini = y;


}

void peonn::dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini, posyini-0.37, 0.01);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peonN.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(-0.4, 0);
	glTexCoord2d(1, 1); glVertex2f(0.4, 0);
	glTexCoord2d(1, 0); glVertex2f(0.4, 0.8);
	glTexCoord2d(0, 0); glVertex2f(-0.4, 0.8);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glTranslatef(-posxini, -posyini+0.37, 0);
}


void peonn::setpos(float x, float y) {
	posxini = x;
	posyini = y;
}

void peonn::mueve(float posxfin, float posyfin) {

	movimientos(posxfin, posyfin);
}

int peonn::mov_correcto(float posxfin, float posyfin) {

	if (posyini == 1.5) {
		if (posxfin == posxini && posyfin == posyini + 1 && avanza == 1)
			return AVANZA1;
		else if (posxfin == posxini && posyfin == posyini + 2 && avanza == 1)
			return AVANZA2;
		else if (((posxfin == posxini + 1 && posyfin == posyini + 1) || (posxfin == posxini - 1 && posyfin == posyini + 1)) && come == 1) {
			cout << "COMIDO" << endl;
			return COME;
		}

	}
	else if (posxfin == posxini && posyfin == posyini + 1 && avanza == 1)
		return AVANZA1;
	else if (((posxfin == posxini + 1 && posyfin == posyini + 1) || (posxfin == posxini - 1 && posyfin == posyini + 1)) && come == 1) {
		cout << "COMIDO" << endl;
		return COME;
	}
	else {
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
		return ERROR;
	}
}

void peonn::movimientos(float posxfin, float posyfin) {
	switch (mov_correcto(posxfin, posyfin)) {
	case (AVANZA1):
	{
		turno = 1;
		posyini = posyini + 1;
		break;
	}

	case (AVANZA2):
	{
		turno = 1;
		posyini = posyini + 2;
		break;
	}

	case (COME):
	{
		turno = 1;
		posxini += 1;
		posyini += 1;
		break;
	}

	}
}

float peonn::getposx() {
	return posxini;
}

float peonn::getposy() {
	return posyini;
}