#include "caballo.h"
#include"freeglut.h"
#include <math.h>
#include <iostream>
#include"ETSIDI.h"

using namespace std;


caballo::caballo() {
	rojo = verde = azul = 175;
	posxini = posyini = 0;
	turno = 0;
}

caballo::caballo(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
	posxini = x;
	posyini = y;
}

void caballo::dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini, posyini, 0);
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballoB.png").id);
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


void caballo::movimientos(float posxfin, float posyfin)
{
	if (mov_correcto(posxfin, posyfin) == 1) {

		turno = 1;

		if (posxfin > posxini && posyfin > posyini && fabs(posyfin - posyini) == 2) {
			do { //movimiento arriba-derecha

				posxini = posxini + 1;
				posyini = posyini + 2;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin < posyini && fabs(posyfin - posyini) == 2) {
			do { //movimiento abajo-izquierda

				posxini = posxini - 1;
				posyini = posyini - 2;


			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin > posyini && fabs(posyfin - posyini) == 2) {
			do { //arriba-izquierda

				posxini = posxini - 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini + 2;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin > posxini && posyfin < posyini && fabs(posyfin - posyini) == 2) {
			do { //abajo-derecha

				posxini = posxini + 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini - 2;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin > posxini && posyfin < posyini && fabs(posyfin - posyini) == 1) {
			do { //derecha-abajo

				posxini = posxini + 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini - 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin > posxini && posyfin > posyini && fabs(posyfin - posyini) == 1) {
			do { //derecha-arriba

				posxini = posxini + 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini + 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin > posyini && posyfin - posyini == 1 && fabs(posyfin - posyini) == 1) {
			do { //izquierda-arriba

				posxini = posxini - 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini + 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin < posyini && fabs(posyfin - posyini) == 1) {
			do { //izquierda-abajo

				posxini = posxini - 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini - 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

	}
	else
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}

int caballo::mov_correcto(float posxfin, float posyfin)
{
	if ((fabs(posxini - posxfin) == 1) && (fabs(posyini - posyfin) == 2) || ((fabs(posxini - posxfin) == 2) && (fabs(posyini - posyfin) == 1)))
		return MOV_CORRECTO;
	else
		return ERROR;
}

void caballo::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
	if (posxinif == posxini && posyinif == posyini)
		movimientos(posxfinf, posyfinf);


}


int caballo::getturno() {
	return turno;
}

void caballo::setturno(int t)
{
	turno = t;
}
