#include"peon.h"
#include "freeglut.h"

peon::peon()
{
	rojo = azul = verde = 0;
	posxini =posyini = 0;

}

void peon::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posxini, posyini, 0);
	glutSolidSphere(0.5, 20, 20);
	glTranslatef(-posxini, -posyini, 0);
}