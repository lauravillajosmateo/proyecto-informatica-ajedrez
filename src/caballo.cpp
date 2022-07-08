#include "caballo.h"
#include"freeglut.h"
#include <math.h>
#include <iostream>
#include"ETSIDI.h"

using namespace std;


void caballo::dibuja() {
	
	glTranslatef(origen.x-0.5, origen.y-0.9, 0);
	glEnable(GL_TEXTURE_2D);
	if(color==BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballoB.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballoN.png").id);
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
	glTranslatef(-origen.x+0.5, -origen.y+0.9, 0);
}

void caballo::movimientos(Vector v, ListaPiezas& l)
{
	if (mov_correcto(v, l) == 1 && Pieza::casillalibre(v, l) == 1)
		Pieza::piezacomida(v, l);
	
	if (mov_correcto(v, l) == 1 && turno == 0) {

		turno = 2;

		if (v.x > origen.x && v.y > origen.y && fabs(v.y - origen.y) == 2 && fabs(v.x - origen.x) == 1) {
			do { //movimiento arriba-derecha

				origen.x = origen.x + 1;
				origen.y = origen.y + 2;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x < origen.x && v.y < origen.y && fabs(v.y - origen.y) == 2 && fabs(v.x - origen.x) == 1) {
			do { //movimiento abajo-izquierda

				origen.x = origen.x - 1;
				origen.y = origen.y - 2;


			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x < origen.x && v.y > origen.y && fabs(v.y - origen.y) == 2 && fabs(v.x - origen.x) == 1) {
			do { //arriba-izquierda

				origen.x = origen.x - 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				origen.y = origen.y + 2;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x > origen.x && v.y < origen.y && fabs(v.y - origen.y) == 2 && fabs(v.x - origen.x) == 1) {
			do { //abajo-derecha

				origen.x = origen.x + 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				origen.y = origen.y - 2;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x > origen.x && v.y < origen.y && fabs(v.y - origen.y) == 1 && fabs(v.x - origen.x) == 2) {
			do { //derecha-abajo

				origen.x = origen.x + 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				origen.y = origen.y - 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x > origen.x && v.y > origen.y && fabs(v.y - origen.y) == 1 && fabs(v.x - origen.x) == 2) {
			do { //derecha-arriba

				origen.x = origen.x + 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				origen.y = origen.y + 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x < origen.x && v.y > origen.y && fabs(v.y - origen.y) == 1 && fabs(v.x - origen.x) == 2) {
			do { //izquierda-arriba

				origen.x = origen.x - 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				origen.y = origen.y + 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x < origen.x && v.y < origen.y && fabs(v.y - origen.y) == 1 && fabs(v.x - origen.x) == 2) {
			do { //izquierda-abajo

				origen.x = origen.x - 2; //posxini es la posicion en x donde estamos en ese mometno de comparar
				origen.y = origen.y - 1;

			} while (origen.x != v.x && origen.y != v.y);
		}


		for (int i = 0; i < l.numero; i++) {
			if (l.lista[i]->getmarca() == true)
				l.lista[i]->hayjaque(l);
		}
	}

	else
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}


int caballo::mov_correcto(Vector v, ListaPiezas l)
{
	int contador=0;
	if ((fabs(origen.x - v.x) == 1) && (fabs(origen.y - v.y) == 2) || ((fabs(origen.x - v.x) == 2) && (fabs(origen.y - v.y) == 1)))
		contador++;
	else
		return ERROR;

	if (contador == 1 && Pieza::casillalibre(v, l) == 1){
		Pieza::piezacomida(v,l);
		return MOV_CORRECTO;
	}

	if (contador == 2) {
		return MOV_CORRECTO;
	}

	if (Pieza::casillalibre(v, l) == 0)
		return ERROR;
}


