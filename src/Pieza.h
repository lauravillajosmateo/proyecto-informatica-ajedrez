#pragma once
#include "ListaPiezas.h"
#include "Vector.h"
#define MOV_CORRECTO 1
#define ERROR 0
#include "ETSIDI.h"

using namespace ETSIDI;

typedef enum {BLANCO=0, NEGRO};


class Pieza {
protected:

	Vector origen;

	int turno;
	const int color;
	bool marca_rey;

public:
	Pieza():origen(0,0),turno(0),marca_rey(false), color (BLANCO) {}
	Pieza(Vector v, int c, bool m):origen(v),color(c),marca_rey(m){}

	void setpos(Vector posicion);
	Vector getpos();

	virtual void dibuja() = 0;
	virtual int mov_correcto(Vector, ListaPiezas&) = 0; //realiza todas las comprobaciones
	virtual void movimientos(Vector, ListaPiezas&) = 0; //esta función realiza el movimiento una vez se han realizado todas las comprobaciones y es el
														//turno correspondiente.

	void avisoincorrecto(Vector, ListaPiezas&);
	void hayjaque(ListaPiezas&);
	void jaquemate(ListaPiezas&);

	int getturno();
	bool getmarca();
	int getcolor();
	void setturno(int t);

	int casillalibre(Vector v, ListaPiezas& l);
	void piezacomida(Vector v, ListaPiezas& l);

};
