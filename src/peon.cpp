#include "peon.h"
#include "freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;

peon::peon(Vector v, int c) {
	
	origen = v;
	color = c;

}

void peon::dibuja() {
	
	glTranslatef(origen.x-0.5, origen.y-0.9, 0.01);
	glEnable(GL_TEXTURE_2D);
	if(color==BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peonB.png").id);
	else
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
	glTranslatef(-origen.x+0.5, -origen.y+0.9, 0);

}



int peon::mov_correcto(Vector v) {
	if (mov_correcto(v) == 1 && turno == 0) {

	if (color == BLANCO)
	{
		if (origen.y == 7) {
			if (v.x == origen.x && v.y == origen.y - 1 && avanza == 1) {
				return AVANZA1;
			}
			else if (v.x == origen.x && v.y == origen.y - 2 && avanza == 1)
				return AVANZA2;
			else if (((v.x == origen.x - 1 && v.y == origen.y - 1) || (v.x == origen.x + 1 && v.y == origen.y - 1)) && come == 1)
			{

				return COME;
			}
		}

		else if (v.x == origen.x && v.y == origen.y - 1 && avanza == 1)
			return AVANZA1;

		else if (((v.x == origen.x - 1 && v.y == origen.y - 1) || (v.x == origen.x + 1 && v.y == origen.y - 1)) && come == 1) {

			return COME;
		}
		else {
			cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
			return ERROR;

		}
	}

	else
	{
		if (origen.y == 2) {
			if (v.x == origen.x && v.y == origen.y + 1 && avanza == 1)
				return AVANZA1;
			else if (v.x == origen.x && v.y == origen.y + 2 && avanza == 1)
				return AVANZA2;
			else if (((v.x == origen.x + 1 && v.y == origen.y + 1) || (v.x == origen.x - 1 && v.y == origen.y + 1)) && come == 1) {

				return COME;
			}

		}
		else if (v.x == origen.x && v.y == origen.y + 1 && avanza == 1)
			return AVANZA1;
		else if (((v.x == origen.x + 1 && v.y == origen.y + 1) || (v.x == origen.x - 1 && v.y == origen.y + 1)) && come == 1) {

			return COME;
		}
	}
		else {
			cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
			return ERROR;
		}
	}
}



void peon::movimientos(Vector v) {

	if (color == BLANCO)
	{
		switch (mov_correcto(v)) {
		case (AVANZA1):
		{
			turno = 1;

			origen.y = origen.y - 1;
			break;

		}

		case (AVANZA2):
		{
			turno = 1;
			origen.y = origen.y - 2;
			break;
		}

		case (COME):
		{
			turno = 1;

			origen.x = v.x;
			origen.y = v.y;
			break;
		}

		}
	}
	else
	{
		switch (mov_correcto(v)) {
		case (AVANZA1):
		{
			turno = 1;
			origen.y = origen.y + 1;
			break;
		}

		case (AVANZA2):
		{
			turno = 1;
			origen.y = origen.y + 2;
			break;
		}

		case (COME):
		{
			turno = 1;
			origen.x = v.x;
			origen.y = v.y;
			break;
		}

		}
	}
}

