#include "mundo.h"
#include "freeglut.h"
#include <iostream>

using namespace std;



mundo::mundo()
{
	x = 4.0;
	y = 4.0;
	z = 15.0;
	mover = 0;
	carteltb = 1; //empiezan blancas
	cartelcome = 0;
	posini.x, posini.y, posfin.x, posfin.y = 0;
}

mundo::~mundo()
{
}


void mundo::inicializa()
{
	
	for (int i = 0; i < 8; i++) //peones negros
	{
		Vector vaux(1 + i, 2);
		Pieza* aux = new peon(vaux, NEGRO);
		listapiezas.agregar(aux);
	}

	for (int i = 0; i < 8; i++) //peones blancos
	{
		Vector vaux(1 + i, 7);
		Pieza* aux = new peon(vaux, BLANCO);
		listapiezas.agregar(aux);
	}
	
	Vector pos(5,1);
	
	Pieza* aux1 = new rey(pos, NEGRO);
	listapiezas.agregar(aux1);

	pos.y = 8;
	Pieza* aux2 = new rey(pos, BLANCO);
	listapiezas.agregar(aux2);

	pos.y = 1;
	pos.x = 4;
	Pieza* aux3 = new reina(pos, NEGRO);
	listapiezas.agregar(aux3);

	pos.y = 8;
	Pieza* aux4 = new reina(pos, BLANCO);
	listapiezas.agregar(aux4);

	pos.y = 1;
	pos.x = 2;
	Pieza* aux5 = new caballo(pos, NEGRO);
	listapiezas.agregar(aux5);

	pos.x = 7;
	Pieza* aux16 = new caballo(pos, NEGRO);
	listapiezas.agregar(aux16);

	pos.y = 8;
	Pieza* aux6 = new caballo(pos, BLANCO);
	listapiezas.agregar(aux6);

	pos.x = 2;
	Pieza* aux7 = new caballo(pos, BLANCO);
	listapiezas.agregar(aux7);

	pos.x = 3;
	pos.y = 1;
	Pieza* aux8 = new alfil(pos, NEGRO);
	listapiezas.agregar(aux8);

	pos.x = 6;
	Pieza* aux9 = new alfil(pos, NEGRO);
	listapiezas.agregar(aux9);

	pos.y = 8;
	Pieza* aux10 = new alfil(pos, BLANCO);
	listapiezas.agregar(aux10);

	pos.x = 3;
	Pieza* aux11 = new alfil(pos, BLANCO);
	listapiezas.agregar(aux11);


	pos.x = 1;
	pos.y = 1;
	Pieza* aux12 = new torre(pos, NEGRO);
	listapiezas.agregar(aux12);

	pos.x = 8;
	Pieza* aux13 = new torre(pos, NEGRO);
	listapiezas.agregar(aux13);

	pos.x = 1;
	pos.y = 8;
	Pieza* aux14 = new torre(pos, BLANCO);
	listapiezas.agregar(aux14);

	pos.x = 8;
	Pieza* aux15 = new torre(pos, BLANCO);
	listapiezas.agregar(aux15);


	listapiezas.inicializarturnos();

}

void mundo::dibuja() {
	gluLookAt(x, y, z,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	tablero1.Dibuja();
	marco1.dibuja();

	listapiezas.dibuja();

}
	
	

//	//DIBUJA CARTEL DE TURNOS
//	if (carteltb == 1) {
//		cartel.dibujatblancas();
//		
//	}
//	if (carteltb == 2) {
//		cartel.dibujatnegras();
//		
//	}
//	//DIBUJA CARTEL SISE HA COMIDO UNA PIEZA
//
//	if (cartelcome == 1) {
//		
//
//		cout << "PIEZA COMIDA" << endl << endl;
//		cartelcome = 0;
//	}
//
//
//}
//





void mundo::mueve()
{
	Pieza* p;
	
	cout << "Dime la columna y fila de la pieza que quieres mover" << endl;
	cin >> posini.x >>posini.y;
	fflush;


	cout << "Dime la columna y fila del lugar donde quieres mover la pieza" << endl;
	cin >> posfin.x>>posfin.y;
	fflush;
	

	if (listapiezas.comprobar(posini) != NULL) {
		p = listapiezas.comprobar(posini);
		p->movimientos(posfin, listapiezas);

		listapiezas.cambiarturnos();

	}
}



//int mundo::final()
//{
//	if ((reyn.getx() == 10 && reyn.gety() == 8) || (reyb.getx() == 10 && reyb.gety() == 8))
//		return 1;
//	else return 0;
//
//}
//
//
//void mundo::hayjaqueB() //ok
//{
//	if (caballob1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
//		cout << "Hay jaque" << endl; //Cambiar por imagen que salte en pantalla
//	if (caballob2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (torreb1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (torreb2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (alfilb1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (alfilb2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (reinab.mov_correcto(reyn.getx(), reyn.gety()) == 1)
//		cout << "Hay jaque" << endl;
//
//}
//
//void mundo::hayjaqueN() //ok
//{
//	if (caballon1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (caballon2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (torren1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (torren2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (alfiln1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (alfiln2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
//		cout << "Hay jaque" << endl;
//	if (reinan.mov_correcto(reyb.getx(), reyb.gety()) == 1)
//		cout << "Hay jaque" << endl;
//


