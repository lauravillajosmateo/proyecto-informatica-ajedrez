#include "torreN.h"
#include"freeglut.h"
#include <iostream>
#include"ETSIDI.h"

using namespace std;


torreN::torreN() {
    rojo = verde = azul = 0;
    posxini = posyini = 0;
    turno = 1;
}

torreN::torreN(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
    rojo = r;
    azul = a;
    verde = v;
    posxini = x;
    posyini = y;
}

void torreN::dibuja() {
    glColor3ub(rojo, verde, azul);
    glTranslatef(posxini, posyini, 0);
    glEnable(GL_TEXTURE_2D);
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
    glTranslatef(-posxini, -posyini, 0);
}


int torreN::getturno() {
    return turno;
}

void torreN::setturno(int t)
{
    turno = t;
}


int torreN::mov_correcto(float posxfin, float posyfin)
{
    if ((posxfin == posxini) && (posyfin == posyini)) {
        return ERROR;
    }
    else {

        if ((posxfin == posxini) || (posyfin == posyini)) {
            return MOV_CORRECTO;
        }
        else {
            return ERROR;
        }
    }


}

void torreN::movimientos(float posxfin, float posyfin)
{
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
            cout << "mueve abajo" << endl;
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

    }
    else
        cout << "MOVIMIENTO INCORRECTO. Prueba otra vez." << endl;
}

void torreN::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
    if (posxinif == posxini && posyinif == posyini)
        movimientos(posxfinf, posyfinf);


}

