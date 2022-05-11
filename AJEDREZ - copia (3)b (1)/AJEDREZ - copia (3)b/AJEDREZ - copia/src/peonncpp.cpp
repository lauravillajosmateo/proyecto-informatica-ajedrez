#include "peonn.h"
#include "freeglut.h"
#include <iostream>

using namespace std;

peonn::peonn() {
	rojo = verde = azul = 0;
	posxini = posyini = 0;

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
	glTranslatef(posxini, posyini, 0);
	glutSolidSphere(0.25, 20, 20);
	glTranslatef(-posxini, -posyini, 0);
}

void peonn::setcolor(unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
}

void peonn::setpos(float x, float y) {
	posxini = x;
	posyini = y;
}

void peonn::mueve(float posxfin, float posyfin) {

	movimientos(posxfin, posyfin);
}

int peonn::mov_correcto(float posxfin, float posyfin) {

		if (posyini==1.5) {
			if (posxfin == posxini && posyfin == posyini + 1)
				return AVANZA1;
			else if (posxfin == posxini && posyfin == posyini + 2)
				return AVANZA2;
			else if ((posxfin == posxini + 1 && posyfin == posyini + 1) || (posxfin == posxini - 1 && posyfin == posyini + 1))
				return COME;
			
		}
		else if (posxfin == posxini && posyfin == posyini + 1)
			return AVANZA1;
		else if ((posxfin == posxini + 1 && posyfin == posyini + 1) || (posxfin == posxini - 1 && posyfin == posyini + 1))
			return COME;
		else {
			cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
			return ERROR;
		}
}

void peonn::movimientos(float posxfin, float posyfin) {
	switch (mov_correcto(posxfin, posyfin)) {
	case (AVANZA1):
	{
		posyini = posyini + 1;
		break;
	}

	case (AVANZA2):
	{
		posyini = posyini + 2;
		break;
	}

	case (COME):
	{
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