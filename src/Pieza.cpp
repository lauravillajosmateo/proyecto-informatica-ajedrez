#include "Pieza.h"

Pieza::Pieza() {
	origen.x = 0;
	origen.y = 0;
	turno = 0;
	color = 0;
}


Pieza::Pieza(Vector v, int c, int m) {
	origen = v;
	color = c;
	marca = m;
}

void Pieza::setpos(Vector posicion) {
	origen = posicion;
}

Vector Pieza::getpos()
{
	return origen;
}



int Pieza::getturno()
{
	return turno;
}

void Pieza::setturno(int t)
{
	turno = t;
}

int Pieza::casillalibre(Vector v, ListaPiezas l) {
	for (int i = 0; i < l.numero; i++) {
		if (v == l.lista[i]->getpos() && l.lista[i]->getcolor() == color) //mismo equipo, no puede comer
			return 0;
	}
	return 1; //aqui puede comer (movimiento correcto)
}
