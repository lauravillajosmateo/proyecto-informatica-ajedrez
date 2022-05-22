#include "reinaN.h"
#include"freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;

reinaN::reinaN() {
    rojo = verde = azul = 0;
    posxini = posyini = 0;
    turno = 1;
}

reinaN::reinaN(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
    rojo = r;
    azul = a;
    verde = v;
    posxini = x;
    posyini = y;
}

void reinaN::dibuja() {
    glColor3ub(rojo, verde, azul);
    glTranslatef(posxini+0.1, posyini, 0);
    glEnable(GL_TEXTURE_2D);
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
    glTranslatef(-posxini, -posyini, 0);
}


int reinaN::getturno() {
    return turno;
}

void reinaN::setturno(int t)
{
    turno = t;
}


int reinaN::mov_correcto(float posxfin, float posyfin)
{
    //parte de la torre
    if ((posxfin == posxini) && (posyfin == posyini)) {
        return ERROR;
    }

    else if ((posxfin > posxini) && (posyfin < posyini) || (posxfin < posxini) && (posyfin > posyini)) {
        if (posxfin + posyfin == posxini + posyini) {
            return MOVIMIENTO_CORRECTO;

        }
        else
            return ERROR;
    }
    else if ((posxfin < posxini) && (posyfin < posyini) || (posxfin > posxini) && (posyfin > posyini)) {
        if (posyfin - posxfin == posyini - posxini) {
            return MOVIMIENTO_CORRECTO;

        }
        else
            return ERROR;
    }
    else {
        if ((posxfin == posxini) || (posyfin == posyini)) {
            return MOVIMIENTO_CORRECTO;
        }
        else {
            return ERROR;

        }
    }

}

void reinaN::movimientos(float posxfin, float posyfin)
{
    //parte torre
    if (mov_correcto(posxfin, posyfin) == 1) {
        turno = 1;
        if ((posxfin == posxini) && (posyfin > posyini))//mover arriba
        {
            do {
                posyini = posyini + 1;
            } while (posyini != posyfin);
        }
        else if ((posxfin == posxini) && (posyfin < posyini))//mover abajo
        {
            do {
                posyini = posyini - 1;
            } while (posyini != posyfin);
        }
        else if ((posxfin > posxini) && (posyfin == posyini))//mover derecha
        {
            do {
                posxini = posxini + 1;
            } while (posxini != posxfin);
        }
        else if ((posxfin < posxini) && (posyfin == posyini))//mover izquierda
        {
            do {
                posxini = posxini - 1;
            } while (posxini != posxfin);
        }

        //parte alfil

        if (posxfin > posxini && posyfin > posyini) {
            do { //movimiento arriba-derecha

                posxini = posxini + 1;
                posyini = posyini + 1;

            } while (posxini != posxfin && posyini != posyfin);
        }

        else if (posxfin < posxini && posyfin < posyini) {
            do { //movimiento abajo-izquierda

                posxini = posxini - 1;
                posyini = posyini - 1;


            } while (posxini != posxfin && posyini != posyfin);
        }

        else if (posxfin < posxini && posyfin > posyini) {
            do { //arriba-izquierda

                posxini = posxini - 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
                posyini = posyini + 1;

            } while (posxini != posxfin && posyini != posyfin);
        }

        else if (posxfin > posxini && posyfin < posyini) {
            do { //abajo-derecha

                posxini = posxini + 1; //posxini es la posicion en x donde estamos en ese mometno de comparar
                posyini = posyini - 1;

            } while (posxini != posxfin && posyini != posyfin);
        }
    }
    else
        cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}

void reinaN::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
    if (posxinif == posxini && posyinif == posyini)
        movimientos(posxfinf, posyfinf);


}