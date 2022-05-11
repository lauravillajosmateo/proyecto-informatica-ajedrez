#include "torreN.h"
#include"freeglut.h"
#include <iostream>

using namespace std;


torreN::torreN() {
	rojo = verde = azul = 0;
	posxini = posyini = 0;
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
	glutWireCube(0.25);
	glTranslatef(-posxini, -posyini, 0);
}

void torreN::setcolor(unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
}

void torreN::setpos(float x, float y) {
	posxini = x;
	posyini = y;
}

float torreN::getx()
{
	return posxini;
}

float torreN::gety()
{
	return posyini;
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
}

void torreN::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
    if (posxinif == posxini && posyinif == posyini)
        movimientos(posxfinf, posyfinf);
}