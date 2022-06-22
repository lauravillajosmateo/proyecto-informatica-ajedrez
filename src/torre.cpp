#include "torre.h"
#include"freeglut.h"
#include <iostream>
#include"ETSIDI.h"


using namespace std;


torre::torre(Vector ptorre, int c) {
    origen =ptorre;
    color=c;
}



void torre::dibuja() {
    glTranslatef(origen.x, origen.y, 0);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/torreB.png").id);
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


int torre::mov_correcto(Vector v)
{
    if ((v.x == origen.x) && (v.y == origen.y)) {
        return ERROR;
    }
    else {

        if ((v.x == origen.x) || (v.y == origen.y)) {
            return MOV_CORRECTO;
        }
        else {
            return ERROR;
        }
    }


}

void torre::movimientos(Vector v)
{
    if (mov_correcto(v.x, v.y) == 1) {
        turno = 1;
        if ((v.x == origen.x) && (v.y > origen.y))//mover arriba
        {
            do {
                origen.y = origen.y + 1;
            } while (origen.y != v.y);
        }
        else if ((v.x == origen.x) && (v.y < origen.y))//mover abajo
        {
            cout << "mueve abajo" << endl;
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
                origrn.x = origen.x - 1;
            } while (origen.x != v.x);
        }

    }
    else
        cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}




