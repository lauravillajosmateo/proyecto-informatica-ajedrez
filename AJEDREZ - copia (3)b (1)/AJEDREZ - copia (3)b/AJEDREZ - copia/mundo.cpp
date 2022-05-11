
#include "mundo.h"
#include "freeglut.h"






mundo::mundo()
{
	x = 10.0;
	y = -25.0;
	z = 25.0;
}

void mundo::inicializa()
{


}

void mundo::dibuja() {
	gluLookAt(x, y, z,  // posicion del ojo
		10.0, 10.0, 5.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	tablero1.Dibuja(16.0, 16.0, 1.0);




}

void mundo::tecla(unsigned char key) {
}


void mundo::mueve() {


}