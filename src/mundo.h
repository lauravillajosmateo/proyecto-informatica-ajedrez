#include "cartel.h"
#include "Pieza.h"
#include "alfil.h"
#include "caballo.h"
#include "peon.h"
#include "reina.h"
#include "rey.h"
#include "torre.h"

#include "Vector.h"

class mundo
{
public:
	float x;
	float y;
	float z;
	int mover;
	int carteltb;
	int cartelcome;
	Vector posini, posfin;

	Marco marco1;
	//Cartel cartel;

	ListaPiezas listapiezas;


	mundo();
	~mundo();

	void inicializa();
	void dibuja();
	void mueve();

	//void tecla(unsigned char key);
	/*void hayjaqueB();
	void hayjaqueN();

	int final();*/

	tablero tablero1;

};
