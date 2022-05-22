#include "rey.h"
#include "freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;

rey::rey() {
	rojo = verde = azul = 175;
	posxini = posyini = 0;
	turno = 0;
}

rey::rey(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
	posxini = x;
	posyini = y;
}

void rey::dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini-0.1, posyini-0.4, 0.01);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reyB.png").id);
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
	glTranslatef(-posxini, -posyini, 0);
}


int rey::mov_correcto(float posxfin, float posyfin)
{
	if (posyfin + 1 == posyini) // si el destino es hacia arriba
		if (posxfin + 1 == posxini) // y en diagonal izquierda
			return MOV_CORRECTO;
		else if (posxfin == posxini)//misma columna
			return MOV_CORRECTO;
		else if (posxfin - 1 == posxini) // en diagonal derecha
			return MOV_CORRECTO;
		else
			return ERROR;
	else if (posyfin == posyini) //si el destino es en la misma fila
		if (posxfin + 1 == posxini) //hacia la izquierda
			return MOV_CORRECTO;
		else if (posxfin - 1 == posxini)//hacia la derecha
			return MOV_CORRECTO;
		else
			return ERROR;
	else if (posyfin - 1 == posyini) //si el destino es hacia abajo
		if (posxfin + 1 == posxini)//hacia la izquierda
			return MOV_CORRECTO;
		else if (posxfin == posxini)
			return MOV_CORRECTO;
		else if (posxfin - 1 == posxini)
			return MOV_CORRECTO;
		else
			return ERROR;
	else
		return ERROR;

}



void rey::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
	if (posxinif == posxini && posyinif == posyini)
		movimientos(posxfinf, posyfinf);


}

void rey::movimientos(float posxfin, float posyfin)
{
	if (mov_correcto(posxfin, posyfin) == 1) {
		turno = 1;
		if ((posxfin == posxini) && (posyfin > posyini))//mover arriba
			posyini = posyini + 1;
		else if ((posxfin == posxini) && (posyfin < posyini))//mover abajo
			posyini = posyini - 1;

		else if ((posxfin > posxini) && (posyfin == posyini))
			posxini = posxini + 1;//mover derecha

		else if ((posxfin < posxini) && (posyfin == posyini))//mover izquierda
			posxini = posxini - 1;
		else if ((posxfin > posxini) && (posyfin > posyini)) {//arriba-derecha
			posxini = posxini + 1;
			posyini = posyini + 1;
		}
		else if ((posxfin > posxini) && (posyfin < posyini)) {//abajo-derecha
			posxini = posxini + 1;
			posyini = posyini - 1;

		}
		else if ((posxfin > posxini) && (posyfin > posyini)) {//arriba-izquierda
			posxini = posxini - 1;
			posyini = posyini + 1;
		}
		else if ((posxfin < posxini) && (posyfin < posyini)) {//abajo-izquierda

			posxini = posxini - 1;
			posyini = posyini - 1;
		}
	}

	else
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}

int rey::getturno() {
	return turno;
}

void rey::setturno(int t)
{
	turno = t;
}
