#include "Pieza.h"

Pieza::Pieza() {
	origen.x = 0;
	origen.y = 0;
	turno = 0;
	color = 0;
}

void Pieza::setpos(Vector posicion) {
	origen = posicion;
}

Vector Pieza::getpos()
{
	return origen;
}




void Pieza::mueve(Vector inicio, Vector fin)
{
	if (inicio = origen)
		movimientos(fin);
}

int Pieza::getturno()
{
	return turno;
}

void Pieza::setturno(int t)
{
	turno = t;
}
