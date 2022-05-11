#include "caballo.h"
#include"freeglut.h"
#include <math.h>


caballo::caballo() {
	rojo = verde = azul = 175;
	posxini = posyini = 0;
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
	glutSolidTeapot(0.25);
	glTranslatef(-posxini, -posyini, 0);
}

void caballo::setcolor(unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
}

void caballo::setpos(float x, float y) {
	posxini = x;
	posyini = y;
}

float caballo::getx() {
	return posxini;
}
float caballo::gety() {
	return posyini;
}

void caballo::movimientos(float posxfin, float posyfin)
{
	if (mov_correcto(posxfin, posyfin) == 1) {

		if (posxfin > posxini && posyfin > posyini) {
			do { //movimiento arriba-derecha

				posxini = posxini + 1;
				posyini = posyini + 2;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin < posyini) {
			do { //movimiento abajo-izquierda

				posxini = posxini - 1;
				posyini = posyini - 2;


			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin > posyini) {
			do { //arriba-izquierda

				posxini = posxini - 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini + 2;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin > posxini && posyfin < posyini) {
			do { //abajo-derecha

				posxini = posxini + 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini - 2;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin > posxini && posyfin < posyini) {
			do { //derecha-abajo

				posxini = posxini + 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini - 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin > posxini && posyfin < posyini) {
			do { //derecha-arriba

				posxini = posxini + 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini + 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin > posyini) {
			do { //izquierda-arriba

				posxini = posxini - 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini + 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

		else if (posxfin < posxini && posyfin > posyini) {
			do { //izquierda-abajo

				posxini = posxini - 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				posyini = posyini - 1;

			} while (posxini != posxfin && posyini != posyfin);
		}

	}
}

int caballo::mov_correcto(float posxfin, float posyfin)
{
	if ((fabs(posxini - posxfin) == 1) && (fabs(posyini - posyfin == 2)) || ((fabs(posxini - posxfin) == 2) && (fabs(posyini - posyfin == 1))))
		return MOV_CORRECTO;
	else
		return ERROR;
}

void caballo::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
	if (posxinif == posxini && posyinif == posyini)
		movimientos(posxfinf, posyfinf);
}