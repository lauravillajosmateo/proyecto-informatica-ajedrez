#include "alfil.h"
#include <iostream>
#include"freeglut.h"

using namespace std;



void alfil::dibuja() {

	glTranslatef(origen.x - 0.5, origen.y - 0.9, 0);
	glEnable(GL_TEXTURE_2D);
	if (color == BLANCO)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfilB.png").id);
	else
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/alfilN.png").id);
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




int alfil::mov_correcto(Vector v,ListaPiezas& l)
{
	Vector aux = origen;
	int contador = 0;
	int mover = 1;
	//primero se verifica que la posicion es valida por la naturaleza de la pieza
	if ((v.x > origen.x) && (v.y < origen.y) || (v.x < origen.x) && (v.y > origen.y)) {
		if (v.x + v.y == origen.x + origen.y) {
			contador++;
		}
		else
			return ERROR;
	}
	else if ((v.x < origen.x) && (v.y < origen.y) || (v.x > origen.x) && (v.y > origen.y)) {
		if (v.y - v.x == origen.y - origen.x) {
			contador++;
		}
		else
			return ERROR;
	}
	else
		return ERROR;

	//arriba derecha

	if (v.x > origen.x && v.y > origen.y)
	{
		do
		{
			for (int i = 0; i < l.numero; i++)
			{
				if (aux.x+1 == l.lista[i]->getpos().x && aux.y + 1 == l.lista[i]->getpos().y)
				{
					mover = 0;
				}
			}

			aux.y++;
			aux.x++;
		} while (aux.x != v.x || aux.y != v.y);
	}


	//arriba izquierda
	if (v.x < origen.x && v.y > origen.y)
	{
		do
		{
			for (int i = 0; i < l.numero; i++)
			{
				if (aux.x - 1 == l.lista[i]->getpos().x && aux.y + 1 == l.lista[i]->getpos().y)
				{
					mover = 0;
				}
			}

			aux.y++;
			aux.x--;
		} while (aux.x != v.x || aux.y != v.y);
	}

	//abajo derecha

	if (v.x > origen.x && v.y < origen.y)
	{
		do
		{
			for (int i = 0; i < l.numero; i++)
			{
				if (aux.x + 1 == l.lista[i]->getpos().x && aux.y - 1 == l.lista[i]->getpos().y)
				{
					mover = 0;
				}
			}

			aux.y--;
			aux.x++;
		} while (aux.x != v.x || aux.y != v.y);
	}

	//abajo izquierda
	if (v.x < origen.x && v.y < origen.y)
	{
		do
		{
			for (int i = 0; i < l.numero; i++)
			{
				if (aux.x - 1 == l.lista[i]->getpos().x && aux.y - 1 == l.lista[i]->getpos().y)
				{
					mover = 0;
				}
			}

			aux.y--;
			aux.x--;
		} while (aux.x != v.x || aux.y != v.y);
	}

	if (mover == 0)
		return ERROR;
	else
		contador++;

	if (Pieza::casillalibre(v, l) == 0)
		return ERROR;
	else 
		contador++;
	if (contador==3){
		reyturn MOV_CORRECTO;
	}

}

void alfil::movimientos(Vector v,ListaPiezas& l)
{
	if (mov_correcto(v, l) == 1 && Pieza::casillalibre(v, l) == 1)
		Pieza::piezacomida(v, l);
	
	if (mov_correcto(v,l) == 1 && turno==0) {

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

		turno = 2;

		for (int i = 0; i < l.numero; i++) {
			if (l.lista[i]->getmarca() == true){
				l.lista[i]->hayjaque(l);
				l.lista[i]->jaquemate(l);
			}
		}

	}
	else
		cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}



