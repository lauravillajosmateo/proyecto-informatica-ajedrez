#include "alfil.h"
#include <iostream>
#include"freeglut.h"

using namespace std;


alfil::alfil (Vector palfil, int c) {

	origen = palfil;
	color = c;

}

void alfil::dibuja() {
	
	glTranslatef(origen.x, origen.y, 0);
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
	glTranslatef(-origen.x, -origen.y, 0);
	
}




int alfil::mov_correcto(Vector v)
{
	if ((v.x > origen.x) && (v.y < origen.y) || (v.x < origen.x) && (v.y > origen.y)) {
		if (v.x + v.y == origen.x + origen.y) {
			return MOV_CORRECTO;
		}
		else
			return ERROR;
	}
	else if ((v.x < origen.x) && (v.y < origen.y) || (v.x > origen.x) && (v.y > origen.y)) {
		if (v.y - v.x == origen.y - origen.x) {
			return MOV_CORRECTO;
		}
		else
			return ERROR;
	}
	else
		return ERROR;
}

void alfil::movimientos(Vector v)
{
	if (mov_correcto(v) == 1) {

		if (v.x > origen.x && v.y > origen.y) {
			do { //movimiento arriba-derecha

				origen.x = origen.x + 1;
				origen.y = origen.y + 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x < origen.x && v.y < origen.y) {
			do { //movimiento abajo-izquierda

				origen.x = origen.x - 1;
				origen.y = origen.y - 1;


			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x < origen.x && v.y > origen.y) {
			do { //arriba-izquierda

				origen.x = origen.x - 1; 
				origen.y = origen.y + 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		else if (v.x > origen.x && v.y < origen.y) {
			do { //abajo-derecha

				origen.x = origen.x + 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
				origen.y = origen.y - 1;

			} while (origen.x != v.x && origen.y != v.y);
		}

		turno = 1;
	}
	else
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}



