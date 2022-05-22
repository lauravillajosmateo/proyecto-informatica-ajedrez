#include "alfil.h"
#include <iostream>
#include"freeglut.h"

using namespace std;

alfil::alfil() {
	rojo = verde = azul = 175;
	posxini = posyini = 0;
	turno = 0;
}

alfil::alfil(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
	posxini = x;
	posyini = y;
}

void alfil::dibuja() {
	
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini, posyini, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfilB.png").id);
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

void alfil::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
	if (posxinif == posxini && posyinif == posyini) {

		movimientos(posxfinf, posyfinf);
	}
}


int alfil::mov_correcto(float posxfin, float posyfin)
{
	if ((posxfin > posxini) && (posyfin < posyini) || (posxfin < posxini) && (posyfin > posyini)) {
		if (posxfin + posyfin == posxini + posyini) {
			return MOV_CORRECTO;
		}
		else
			return ERROR;
	}
	else if ((posxfin < posxini) && (posyfin < posyini) || (posxfin > posxini) && (posyfin > posyini)) {
		if (posyfin - posxfin == posyini - posxini) {
			return MOV_CORRECTO;
		}
		else
			return ERROR;
	}
	else
		return ERROR;
}

void alfil::movimientos(float posxfin, float posyfin)
{
	if (mov_correcto(posxfin, posyfin) == 1) {

		if (posxfin > posxini && posyfin > posyini) {
			do { //movimiento arriba-derecha

				posxini = posxini + 1;
				posyini = posyini + 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin < posyini) {
			do { //movimiento abajo-izquierda

				posxini = posxini - 1;
				posyini = posyini - 1;


			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin > posyini) {
			do { //arriba-izquierda

				posxini = posxini - 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini + 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin > posxini && posyfin < posyini) {
			do { //abajo-derecha

				posxini = posxini + 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini - 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		turno = 1;
	}
	else
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}


int alfil::getturno() {
	return turno;
}

void alfil::setturno(int t)
{
	turno = t;
}
