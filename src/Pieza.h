#pragma once

#include "ETSIDI.h"
#include "Vector.h"

#define MOV_CORRECTO 1
#define ERROR 0 

using namespace ETSIDI;

typedef enum {BLANCO=0, NEGRO};
typedef enum { PEON = 1, TORRE, CABALLO, ALFIL, REINA, REY };


class Pieza {
protected:
	
	Vector origen;

	int turno;
	int color;
	int mover;
	int marca;

public:
	Pieza():origen(0,0),turno(0), marca(0), color(0), mover(1){}
	Pieza(Vector v, int c, int m):origen(v), color(c), marca(m){}
	
	
	void setpos(Vector posicion);

	Vector getpos();

	virtual void dibuja() = 0;
/*void mueve(Vector inicio, Vector final);*/
virtual int mov_correcto(Vector, ListaPiezas ) = 0; //realiza todas las comprobaciones
virtual void movimientos(Vector,ListaPiezas) = 0; //esta función realiza el movimiento una vez se han realizado todas las comprobaciones y es el
//turno correspondiente.

int getturno();
int getmarca();
int getcolor();
void setturno(int t);

int casillalibre(Vector v, ListaPiezas l);


};
