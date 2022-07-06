#include "peon.h"
#include "freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;



void peon::dibuja() {

	glTranslatef(origen.x - 0.5, origen.y - 0.9, 0.01);
	glEnable(GL_TEXTURE_2D);
	if (color == BLANCO)
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
	glTranslatef(-origen.x + 0.5, -origen.y + 0.9, 0);

}


int peon::mov_correcto(Vector v,ListaPiezas& l) {
	int come = 0;
	
	for (int i = 0; i < l.numero; i++) {
		if (color != l.lista[i]->getcolor() && (l.lista[i]->getpos() == v))
			come = 1;
		if (color == l.lista[i]->getcolor() && (l.lista[i]->getpos() == v))
			return ERROR;
		
	}

	if (color == BLANCO)
	{
		if (origen.y == 7) {
			if (v.x == origen.x && v.y == origen.y - 1 && come == 0) {
				return AVANZA1;

			}
			else if (v.x == origen.x && v.y == origen.y - 2 && come == 0) {
				for (int i = 0; i < l.numero; i++) {
					if (origen.x == l.lista[i]->getpos().x && origen.y - 1 == l.lista[i]->getpos().y)
						return ERROR;
				}
				return AVANZA2;

			}


			else if (((v.x == origen.x - 1 && v.y == origen.y - 1) || (v.x == origen.x + 1 && v.y == origen.y - 1)) && come == 1)
			{

				return COME;
			}

			else
				return ERROR;
		}

		else if (v.x == origen.x && v.y == origen.y - 1 && come==0)
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
			if (v.x == origen.x && v.y == origen.y + 1 && come == 0)
				return AVANZA1;
			else if (v.x == origen.x && v.y == origen.y + 2 && come == 0)
				return AVANZA2;
			else if (((v.x == origen.x + 1 && v.y == origen.y + 1) || (v.x == origen.x - 1 && v.y == origen.y + 1)) && come == 1)
				return COME;
			else
				return ERROR;
		

		}
		else if (v.x == origen.x && v.y == origen.y + 1 && come ==0)
			return AVANZA1;
		else if (((v.x == origen.x + 1 && v.y == origen.y + 1) || (v.x == origen.x - 1 && v.y == origen.y + 1)) && come == 1) {

			return COME;
		}
		else {
			cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
			return ERROR;
		}
	}
}







void peon::movimientos(Vector v, ListaPiezas& l) {


	if (turno == 0)
	{
		if (color == BLANCO)
		{


			switch (mov_correcto(v,l)) {
			case (AVANZA1):
			{
				turno = 2;

				origen.y = origen.y - 1;

				for (int i = 0; i < l.numero; i++) {
					if (l.lista[i]->getmarca() == true)
						l.lista[i]->hayjaque(l);
				}

				break;

			}

			case (AVANZA2):
			{
				turno = 2;
				origen.y = origen.y - 2;
				for (int i = 0; i < l.numero; i++) {
					if (l.lista[i]->getmarca() == true)
						l.lista[i]->hayjaque(l);
				}
				break;
			}

			case (COME):
			{
				turno = 2;

				origen.x = v.x;
				origen.y = v.y;

				for (int i = 0; i < l.numero; i++) {
					if (l.lista[i]->getmarca() == true)
						l.lista[i]->hayjaque(l);
				}
				Pieza::piezacomida(v, l);

				break;
			}

			}
		}
		else
		{
			switch (mov_correcto(v,l)) {
			case (AVANZA1):
			{
				turno = 2;
				origen.y = origen.y + 1;
				for (int i = 0; i < l.numero; i++) {
					if (l.lista[i]->getmarca() == true)
						l.lista[i]->hayjaque(l);
				}
				break;
			}

			case (AVANZA2):
			{
				turno = 2;
				origen.y = origen.y + 2;
				for (int i = 0; i < l.numero; i++) {
					if (l.lista[i]->getmarca() == true)
						l.lista[i]->hayjaque(l);
				}
				break;
			}

			case (COME):
			{
				turno = 2;
				origen.x = v.x;
				origen.y = v.y;
				Pieza::piezacomida(v, l);
				for (int i = 0; i < l.numero; i++) {
					if (l.lista[i]->getmarca() == true)
						l.lista[i]->hayjaque(l);
				}
				break;
			}

			}

		}

	}
}

