#include "rey.h"
#include "freeglut.h"

rey::rey() {
	rojo = verde = azul = 175;
	posxini = posyini = 0;
}

rey::rey(float x, float y, unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
	posxini = x;
	posyini = y;
}

void rey::dibuja() {
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini, posyini, 0);
	glutSolidCube(0.25);
	glTranslatef(-posxini, -posyini, 0);
}

void rey::setcolor(unsigned char r, unsigned char a, unsigned char v) {
	rojo = r;
	azul = a;
	verde = v;
}

void rey::setpos(float x, float y) {
	posxini = x;
	posyini = y;
}

float rey::getx()
{
	return posxini;
}

float rey::gety()
{
	return posyini;
}

int rey::mov_correcto(float posxfin, float posyfin)
{
	//bool mov_enroque = false;
	//if (posyini = 7.5)
	//{
	// //if (abs(posxfin - posxini == 2 && (posyfin == posyini))) { //y es movimiento tipo enroque
	// // return MOV_ENROQUE;
	// // mov_enroque = true;
	// }
	//}

	//if (!mov_enroque) {
	if (posyfin + 1 == posyini) // si el destino es hacia arriba
		if (posxfin + 1 == posxini) // y en diagonal izquierda
			return MOV_CORRECTO;
		else if (posxfin == posxini)//misma columna
			return MOV_CORRECTO;
		else if (posxfin - 1 == posxini) // en diagonal derecha
			return MOV_CORRECTO;
		else
			return ERROR;
	else if (posyfin == posyini) //si el destino es en la misma fila
		if (posxfin + 1 == posxini) //hacia la izquierda
			return MOV_CORRECTO;
		else if (posxfin - 1 == posxini)//hacia la derecha
			return MOV_CORRECTO;
		else
			return ERROR;
	else if (posyfin - 1 == posyini) //si el destino es hacia abajo
		if (posxfin + 1 == posxini)//hacia la izquierda
			return MOV_CORRECTO;
		else if (posxfin == posxini)
			return MOV_CORRECTO;
		else if (posxfin - 1 == posxini)
			return MOV_CORRECTO;
		else
			return ERROR;
	else
		return ERROR;
	//}

}

void rey::mueve(float posxinif, float posyinif, float posxfinf, float posyfinf)
{
	if (posxinif == posxini && posyinif == posyini)
		movimientos(posxfinf, posyfinf);
}

void rey::movimientos(float posxfin, float posyfin)
{
	if (mov_correcto(posxfin, posyfin) == 1) {
		if ((posxfin == posxini) && (posyfin > posyini))//mover arriba
			posyini = posyini + 1;
		else if ((posxfin == posxini) && (posyfin < posyini))//mover abajo
			posyini = posyini - 1;

		else if ((posxfin > posxini) && (posyfin == posyini))
			posxini = posxini + 1;//mover derecha

		else if ((posxfin < posxini) && (posyfin == posyini))//mover izquierda
			posxini = posxini - 1;
		else if ((posxfin > posxini) && (posyfin > posyini)) {//arriba-derecha
			posxini = posxini + 1;
			posyini = posyini + 1;
		}
		else if ((posxfin > posxini) && (posyfin < posyini)) {//abajo-derecha
			posxini = posxini + 1;
			posyini = posyini - 1;

		}
		else if ((posxfin > posxini) && (posyfin > posyini)) {//arriba-izquierda
			posxini = posxini - 1;
			posyini = posyini + 1;
		}
		else if ((posxfin < posxini) && (posyfin < posyini)) {//abajo-izquierda

			posxini = posxini - 1;
			posyini = posyini - 1;
		}
	}
}