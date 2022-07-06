#include "Pieza.h"

void Pieza::setpos(Vector posicion) {
	origen = posicion;
}

Vector Pieza::getpos()
{
	return origen;
}


void Pieza::hayjaque(ListaPiezas& l)
{
	for (int i = 0; i < l.numero; i++) {
		if (l.lista[i]->getcolor() != color && l.lista[i]->mov_correcto(origen, l)) {
			if (color == BLANCO)
				cout << "Hay jaque para blancas" << endl << endl;
			else
				cout << "Hay jaque para negras" << endl << endl;
		}

	}
}
int Pieza::getturno()
{
	return turno;
}

void Pieza::setturno(int t)
{
	turno = t;
}
bool Pieza::getmarca()
{
	return marca_rey;
}

int Pieza::getcolor()
{
	return color;
}

int Pieza::casillalibre(Vector v, ListaPiezas& l) {
	for (int i = 0; i < l.numero; i++) {
		if (v == l.lista[i]->getpos() && l.lista[i]->getcolor() != color) //distinto equipo, puede comer
			return 1;
		if (v != l.lista[i]->getpos()) //casilla libre
			return 2;
	}
	return 0; //no se puede mover, casilla ocupada por una de su color
}

void Pieza::piezacomida(Vector v, ListaPiezas& l) {
	for (int i = 0; i < l.numero; i++) {
		if (v == l.lista[i]->getpos() && l.lista[i]->getcolor() != color)
		{
			Vector pos(20, 20);
			l.lista[i]->setpos(pos);
		}
	}

}
