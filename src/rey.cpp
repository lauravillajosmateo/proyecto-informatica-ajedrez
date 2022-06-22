#include "rey.h"
#include "freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;

rey::rey(Vector prey, int c) {
	origen=prey;
	color=c;
}


void rey::dibuja() {
	glTranslatef(origen.x, origen.y, 0);
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
	glTranslatef(-origen.x, -origen.y, 0);
}


int rey::mov_correcto(Vector v)
{
	if (v.y + 1 == origen.y) // si el destino es hacia arriba
		if (v.x + 1 == origen.x) // y en diagonal izquierda
			return MOV_CORRECTO;
		else if (v.x == origen.x)//misma columna
			return MOV_CORRECTO;
		else if (v.x - 1 == origen.x) // en diagonal derecha
			return MOV_CORRECTO;
		else
			return ERROR;
	else if (v.y == origen.y) //si el destino es en la misma fila
		if (v.x + 1 == origen.x) //hacia la izquierda
			return MOV_CORRECTO;
		else if (v.x - 1 == origen.x)//hacia la derecha
			return MOV_CORRECTO;
		else
			return ERROR;
	else if (v.y - 1 == origen.y) //si el destino es hacia abajo
		if (v.x + 1 == origen.x)//hacia la izquierda
			return MOV_CORRECTO;
		else if (v.x == origen.x)
			return MOV_CORRECTO;
		else if (v.x - 1 == origen.x)
			return MOV_CORRECTO;
		else
			return ERROR;
	else
		return ERROR;

}


void rey::movimientos(Vector v)
{
	if (mov_correcto(v) == 1) {
		turno = 1;
		if ((v.x == origen.x) && (v.y > origen.y))//mover arriba
			origen.y = origen.y + 1;
		else if ((v.x == origen.x) && (v.y < origen.y))//mover abajo
			origen.y = origen.y - 1;

		else if ((v.x > origen.x) && (v.y == origen.y))
			origen.x = origen.x + 1;//mover derecha

		else if ((v.x < origen.x) && (v.y == origen.y))//mover izquierda
			origen.x = origen.x - 1;
		else if ((v.x > origen.x) && (v.y > origen.y)) {//arriba-derecha
			origen.x = origen.x + 1;
			origen.y = origen.y + 1;
		}
		else if ((v.x > origen.x) && (v.y< origen.y)) {//abajo-derecha
			origen.x = origen.x + 1;
			origen.y = origen.y - 1;

		}
		else if ((v.x > origen.x) && (v.y > origen.y)) {//arriba-izquierda
			origen.x = origen.x - 1;
			origen.y = origen.y + 1;
		}
		else if ((v.x < origen.x) && (v.y < origen.y)) {//abajo-izquierda

			origen.x = origen.x - 1;
			origen.y = origen.y - 1;
		}
	}

	else
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}


