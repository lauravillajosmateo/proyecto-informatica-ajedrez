#include "reina.h"
#include"freeglut.h"
#include <iostream>

using namespace std;

reina::reina(Vector preina, int c) {
    origen=preina;
    color=c;
}

void reina::dibuja() {

    glTranslatef(origen.x, origen.y, 0);
    glEnable(GL_TEXTURE_2D);
    if (color==BLANCO)
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaB.png").id);
    else
         glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/reinaN.png").id);
        
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



int reina::mov_correcto(Vector v, ListaPiezas l)
{
    Vector aux = origen;
    int contador=0;
    //parte de la torre
    if ((v.x == origen.x) && (v.y == origen.y)) {
        return ERROR;
    }

    else if ((v.x > origen.x) && (v.y < origen.y) || (v.x < origen.x) && (v.y > origen.y)) {
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
    else {
        if ((v.x == origen.x) || (v.y == origen.y)) {
            contador++
        }
        else {
            return ERROR;

        }
    }
        
        //hacia arriba

		if (v.x == p->getpos().x && v.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++) {
					if (aux == l.lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.y++;
			} while (aux.y != v.y);//mover 0 es que NO se puede mover
		}

		//hacia izquierda
		if (v.x < p->getpos().x && v.y == p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++) {
					if (aux == l.lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.x--;
			} while (aux.x != v.x);//mover 0 es que NO se puede mover
		}

		//hacia derecha
		if (v.x > p->getpos().x && v.y == p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++) {
					if (aux == l.lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.x++;
			} while (aux.x != v.x);//mover 0 es que NO se puede mover
		}

		//hacia abajo

		if (v.x == p->getpos().x && v.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++) {
					if (aux == l.lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.y--;
			} while (aux.y != v.y);//mover 0 es que NO se puede mover
		}
		//arriba derecha

		if (v.x > p->getpos().x && v.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux == l.lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x++;
			} while (aux.x != v.x || aux.y != v.y);
		}


		//arriba izquierda
		if (v.x < p->getpos().x && v.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux == l.lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x--;
			} while (aux.x != v.x || aux.y != v.y);
		}

		//abajo derecha

		if (v.x > p->getpos().x && v.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux == l.lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y--;
				aux.x++;
			} while (aux.x != v.x || aux.y != v.y);
		}

		//abajo izquierda
		if (v.x < p->getpos().x && v.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < l.numero; i++)
				{
					if (aux == l.lista[i]->getpos())
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
    
    if (Pieza::casillalibre(v, l) == 1)
        contador++;

    if (contador == 3)
        return MOV_CORRECTO;    
	
	else
		return ERROR;
}

void reina::movimientos(Vector v)
{
    //parte torre
    if (mov_correcto(v) == 1 && turno==0) {

        turno = 1;
        if ((v.x == origen.x) && (v.y > origen.y))//mover arriba
        {
            do {
                origen.y = origen.y + 1;
            } while (origen.y != v.y);
        }
        else if ((v.x == origen.x) && (v.y < origen.y))//mover abajo
        {
            do {
                origen.y = origen.y - 1;
            } while (origen.y != v.y);
        }
        else if ((v.x > origen.x) && (v.y == origen.y))//mover derecha
        {
            do {
                origen.x = origen.x + 1;
            } while (origen.x != v.x);
        }
        else if ((v.x < origen.x) && (v.y == origen.y))//mover izquierda
        {
            do {
                origen.x = origen.x - 1;
            } while (origen.x != v.x);
        }

        //parte alfil

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

                origen.x = origen.x + 1; 
                origen.y = origen.y - 1;

            } while (origen.x != v.x && origen.y != v.y);
        }
    }
}
    else
        cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}

