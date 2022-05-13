#include "reina.h"
#include"freeglut.h"


reina::reina() {
	rojo = verde = azul = 175;
	posxini = posyini = 0;
}

reina::reina(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
	posxini = x;
	posyini = y;
}

void reina::dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini, posyini, 0);
	glutSolidTorus(0.1, 0.25, 20, 20);
	glTranslatef(-posxini, -posyini, 0);
}

void reina::setcolor(unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
}

void reina::setpos(float x, float y) {
	posxini = x;
	posyini = y;
}

float reina::getx()
{
	return posxini;
}

float reina::gety()
{
	return posyini;
}

int reina::mov_correcto(float posxfin, float posyfin)
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

void reina::movimientos(float posxfin, float posyfin)
{
    //parte torre
    if (mov_correcto(posxfin, posyfin) == 1) {
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
}

void reina::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
    if (posxinif == posxini && posyinif == posyini)
        movimientos(posxfinf, posyfinf);
}
