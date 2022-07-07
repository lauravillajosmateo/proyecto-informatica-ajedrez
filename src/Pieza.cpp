#include "Pieza.h"

void Pieza::setpos(Vector posicion) {
	origen = posicion;
}

Vector Pieza::getpos()
{
	return origen;
}


void Pieza::avisoincorrecto(Vector v, ListaPiezas& l)
{
	if (mov_correcto(v, l) == ERROR)
		cout << "Movimiento incorrecto. Prueba otra vez." << endl;
}

void Pieza::hayjaque(ListaPiezas& l)
{
	for (int i = 0; i < l.numero; i++) {
		if (l.lista[i]->getcolor() != color && l.lista[i]->mov_correcto(origen, l)) {
			if (color == BLANCO)
				cout << "Hay jaque para angeles." << endl << endl;
			else
				cout << "Hay jaque para demonios." << endl << endl;
		}

	}
}

void Pieza::jaquemate(ListaPiezas& l) {

	Vector derecha(1, 0),izquierda(-1, 0), arriba(0, 1), abajo(0, -1), diagonald(1, 1), diagonald2(1, -1), diagonald3(-1, -1), diagonald4(-1, 1);
	int contador = 0, contadorn = 0, cn = 0, c = 0;
	bool v[9] = {0,0,0,0,0,0,0,0,0};
	bool vn[9] = { 0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < l.numero; i++) {

		//primero se comprueba que al menos una pieza del equipo contrario pueda comer al rey en su proximo movimiento
		if (l.lista[i]->getcolor() == NEGRO && (l.lista[i]->mov_correcto(origen, l) == 1 || l.lista[i]->mov_correcto(origen + derecha, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald2, l) == 1 || l.lista[i]->mov_correcto(origen + abajo, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald3, l) == 1 || l.lista[i]->mov_correcto(origen + izquierda, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald4, l) == 1 || l.lista[i]->mov_correcto(origen + arriba, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald, l) == 1))
			c = 1;


		//se contempla lo demás (que el rey no pueda mover a NINGUNA posicion en la que no pueda ser comido)
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + derecha, l) == 1) || (origen + derecha).x > 8 || ((origen+derecha)==l.lista[i]->getpos() && l.lista[i]->getcolor()==BLANCO))
			v[0]=true;
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + diagonald2, l) == 1) || (origen + diagonald2).x > 8 || (origen+diagonald2).y < 1 || ((origen + diagonald2) == l.lista[i]->getpos() && l.lista[i]->getcolor() == BLANCO))
			v[1] = true;
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + abajo, l) == 1) || (origen + abajo).y < 1 || ((origen + abajo) == l.lista[i]->getpos() && l.lista[i]->getcolor() == BLANCO))
			v[2] = true;
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + diagonald3, l) == 1) || (origen + diagonald3).x < 1 || (origen + diagonald3).y < 1 || ((origen + diagonald3) == l.lista[i]->getpos() && l.lista[i]->getcolor() == BLANCO))
			v[3] = true;
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + izquierda, l) == 1) || (origen + izquierda).x < 1 || ((origen + izquierda) == l.lista[i]->getpos() && l.lista[i]->getcolor() == BLANCO))
			v[4] = true;
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + diagonald4, l) == 1) || (origen + diagonald4).x < 1 || (origen + diagonald4).y > 8 || ((origen + diagonald4) == l.lista[i]->getpos() && l.lista[i]->getcolor() == BLANCO))
			v[5] = true;
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + arriba, l) == 1) || (origen + arriba).y > 8 || ((origen + arriba) == l.lista[i]->getpos() && l.lista[i]->getcolor() == BLANCO))
			v[6] = true;
		if ((l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen + diagonald, l) == 1) || (origen + diagonald).y > 8 || (origen + diagonald).x > 8 || ((origen + diagonald) == l.lista[i]->getpos() && l.lista[i]->getcolor() == BLANCO))
			v[7] = true;
		if (l.lista[i]->getcolor() == NEGRO && l.lista[i]->mov_correcto(origen, l) == 1)
			v[8] = true;
	}

	for (int i = 0; i < 9; i++) {
		if (v[i] == true)
			contador++;
	}

	if (contador == 9 && c==1){
		cout << "JAQUE MATE para angeles." << endl << endl;
		cout << "FIN DEL JUEGO" << endl;

		exit(0);
	}

	for (int i = 0; i < l.numero; i++) {
		//primero se comprueba que al menos una pieza del equipo contrario pueda comer al rey en su proximo movimiento
		if (l.lista[i]->getcolor() == BLANCO && (l.lista[i]->mov_correcto(origen, l) == 1 || l.lista[i]->mov_correcto(origen + derecha, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald2, l) == 1 || l.lista[i]->mov_correcto(origen + abajo, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald3, l) == 1 || l.lista[i]->mov_correcto(origen + izquierda, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald4, l) == 1 || l.lista[i]->mov_correcto(origen + arriba, l) == 1 || l.lista[i]->mov_correcto(origen + diagonald, l) == 1))
			cn = 1;

		//se contempla lo demás (que el rey no pueda mover a NINGUNA posicion en la que no pueda ser comido)
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + derecha, l) == 1) || (origen + derecha).x > 8 || ((origen + derecha) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[0] = true;
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + diagonald2, l) == 1) || (origen + diagonald2).x > 8 || (origen + diagonald2).y < 1 || ((origen + diagonald2) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[1] = true;
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + abajo, l) == 1) || (origen + abajo).y < 1 || ((origen + abajo) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[2] = true;
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + diagonald3, l) == 1) || (origen + diagonald3).x < 1 || (origen + diagonald3).y < 1 || ((origen + diagonald3) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[3] = true;
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + izquierda, l) == 1) || (origen + izquierda).x < 1 || ((origen + izquierda) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[4] = true;
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + diagonald4, l) == 1) || (origen + diagonald4).x < 1 || (origen + diagonald4).y > 8 || ((origen + diagonald4) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[5] = true;
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + arriba, l) == 1) || (origen + arriba).y > 8 || ((origen + arriba) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[6] = true;
		if ((l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen + diagonald, l) == 1) || (origen + diagonald).y > 8 || (origen + diagonald).x > 8 || ((origen + diagonald) == l.lista[i]->getpos() && l.lista[i]->getcolor() == NEGRO))
			vn[7] = true;
		if (l.lista[i]->getcolor() == BLANCO && l.lista[i]->mov_correcto(origen, l) == 1)
			vn[8] = true;
	}

	for (int i = 0; i < 9; i++) {
		if (vn[i] == true)
			contadorn++;
	}

	if (contadorn == 9 && cn==1){
		cout << "JAQUE MATE para demonios." << endl << endl;
		cout << "FIN DEL JUEGO" << endl;

		exit(0);
	}

}

int Pieza::getturno()
{
	return turno;
}

bool Pieza::getmarca()
{
	return marca_rey;
}

int Pieza::getcolor()
{
	return color;
}



void Pieza::setturno(int t)
{
	turno = t;
}

int Pieza::casillalibre(Vector v, ListaPiezas& l) {
	for (int i = 0; i < l.numero; i++) {
		if (v == l.lista[i]->getpos() && l.lista[i]->getcolor() != color) //distinto equipo, puede comer
			return 1;
		if (v == l.lista[i]->getpos() && l.lista[i]->getcolor() == color) //no se puede mover, casilla ocupada por una de su color
			return 0;
	}
	return 2; 
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
