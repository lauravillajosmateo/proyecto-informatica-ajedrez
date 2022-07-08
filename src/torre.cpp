#include "torre.h"
#include"freeglut.h"
#include <iostream>
#include"ETSIDI.h"


using namespace std;


void torre::dibuja() {
    glTranslatef(origen.x-0.5, origen.y-0.9, 0);
    glEnable(GL_TEXTURE_2D);
    if (color== BLANCO)
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torreB.png").id);
    else
        glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torreN.png").id);
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



int torre::mov_correcto(Vector v,ListaPiezas& l) //movimiento valido por naturaleza de la pieza
{
    Vector aux = origen;
    int contador = 0;
    int mover = 1;

    if ((v.x == origen.x) && (v.y == origen.y)) {
        return ERROR;
    }
    else {

        if ((v.x == origen.x) || (v.y == origen.y)) {
            contador++;
            
        }
        else {
            return ERROR;
        }
    }
    //hacia arriba
    if (v.x == origen.x && v.y >origen.y)
    {
        do
        {
            for (int i = 0; i < l.numero; i++) {
                if (aux.y + 1 == l.lista[i]->getpos().y && aux.x == l.lista[i]->getpos().x)
                {
                    mover = 0;
                }

            }

            aux.y++;
        } while (aux.y != v.y);//mover 0 es que NO se puede mover
    }

    //hacia izquierda
    if (v.x <origen.x && v.y ==origen.y)
    {
        do
        {
            for (int i = 0; i < l.numero; i++) {
                if (aux.x - 1 == l.lista[i]->getpos().x && aux.y == l.lista[i]->getpos().y)
                {
                    mover = 0;
                }

            }

            aux.x--;
        } while (aux.x != v.x);//mover 0 es que NO se puede mover
    }

    //hacia derecha
    if (v.x > origen.x && v.y == origen.y)
    {
        do
        {
            for (int i = 0; i < l.numero; i++) {
                if (aux.x + 1 == l.lista[i]->getpos().x && aux.y == l.lista[i]->getpos().y)
                {
                    mover = 0;
                }

            }

            aux.x++;
        } while (aux.x != v.x);//mover 0 es que NO se puede mover
    }

    //hacia abajo

    if (v.x == origen.x && v.y < origen.y)
    {
        do
        {
            for (int i = 0; i < l.numero; i++) {
                if (aux.y-1 == l.lista[i]->getpos().y&& aux.x == l.lista[i]->getpos().x)
                {
                    mover = 0;
                }

            }

            aux.y--;
        } while (aux.y != v.y);//mover 0 es que NO se puede mover
    }
    if (mover == 0)
        return ERROR;
    else
        contador++;
    
    if (contador == 2 && Pieza::casillalibre(v, l) == 1) {

        Pieza::piezacomida(v, l);
        return MOV_CORRECTO;
    }

    if (contador == 2 && Pieza::casillalibre(v, l) == 2) {
        return MOV_CORRECTO;
    }

    if (casillalibre(v, l) == 0)
        return ERROR;


}


void torre::movimientos(Vector v, ListaPiezas& l) 
{
     if (mov_correcto(v, l) == 1 && Pieza::casillalibre(v, l) == 1)
        Pieza::piezacomida(v, l);
    
    if (mov_correcto(v,l) == 1 && turno==0) {
        turno = 2;
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

        for (int i = 0; i < l.numero; i++) {
            if (l.lista[i]->getmarca() == true) {
                l.lista[i]->hayjaque(l);
                l.lista[i]->jaquemate(l);
            }
        }
    }

}


