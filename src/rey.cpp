#include "rey.h"
#include "freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;


void rey::dibuja() {
	glTranslatef(origen.x - 0.5, origen.y - 0.9, 0.1);
	glEnable(GL_TEXTURE_2D);
	if (color == BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reyB.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reyN.png").id);
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


int rey::mov_correcto(Vector v,ListaPiezas& l)
{
	Vector aux = origen;
	int contador = 0;

	if (v.y + 1 == origen.y) // si el destino es hacia arriba
		if (v.x + 1 == origen.x) // y en diagonal izquierda
			contador++;
		else if (v.x == origen.x)//misma columna
			contador++;
		else if (v.x - 1 == origen.x) // en diagonal derecha
			contador++;
		else
			return ERROR;
	else if (v.y == origen.y) //si el destino es en la misma fila
		if (v.x + 1 == origen.x) //hacia la izquierda
			contador++;
		else if (v.x - 1 == origen.x)//hacia la derecha
			contador++;
		else
			return ERROR;
	else if (v.y - 1 == origen.y) //si el destino es hacia abajo
			if (v.x + 1 == origen.x)//hacia la izquierda
			contador++;
			else if (v.x == origen.x)
				contador++;
				else if (v.x - 1 == origen.x)
						contador++;
						else
							return ERROR;
	else
		return ERROR;


	if (Pieza::casillalibre(v, l) == 0)
		return ERROR;
	else
		contador++;


	if (contador == 2) {
		return MOV_CORRECTO;
	}

}


void rey::movimientos(Vector v,ListaPiezas& l)
{
	if (mov_correcto(v, l) == 1 && Pieza::casillalibre(v, l) == 1)
		Pieza::piezacomida(v, l);

	if (mov_correcto(v,l) == 1 && turno == 0) {
			turno = 2;
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
			else if ((v.x > origen.x) && (v.y < origen.y)) {//abajo-derecha
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
	for (int i = 0; i < l.numero; i++) {
		if (l.lista[i]->getmarca() == true) {
			l.lista[i]->hayjaque(l);
			l.lista[i]->jaquemate(l);
		}
	}
}
