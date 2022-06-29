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
}

mundo::~mundo()
{
}


void mundo::inicializa()
{
	//for (int i = 0; i < 8; i++) //peones negros
	//{
	// Vector vaux(1 + i, 2);
	// Pieza* aux = new peon(vaux, 1);
	// listapiezas.agregar(aux);
	//}

	//for (int i = 0; i < 8; i++) //peones blancos
	//{
	// Vector vaux(1 + i, 7);
	// Pieza* aux = new peon(vaux, 0);
	// listapiezas.agregar(aux);
	//}

	Vector pos(5,1);
	Pieza* aux1 = new rey(pos, 1);
	aux1->setpos(pos);
	listapiezas.agregar(aux1);
	cout << aux1->getpos().x<<aux1->getpos().y;

	/*pos.y = 8;
	Pieza* aux2 = new rey(pos, 0);
	listapiezas.agregar(aux2);

	pos.y = 1;
	pos.x = 4;
	Pieza* aux3 = new reina(pos, 1);
	listapiezas.agregar(aux3);

	pos.y = 8;
	Pieza* aux4 = new reina(pos, 0);
	listapiezas.agregar(aux4);

	pos.y = 1;
	pos.x = 2;
	Pieza* aux5 = new caballo(pos, 1);
	listapiezas.agregar(aux5);

	pos.x = 7;
	Pieza* aux16 = new caballo(pos, 1);
	listapiezas.agregar(aux16);

	pos.y = 8;
	Pieza* aux6 = new caballo(pos, 0);
	listapiezas.agregar(aux6);

	pos.x = 2;
	Pieza* aux7 = new caballo(pos, 0);
	listapiezas.agregar(aux7);

	pos.x = 3;
	pos.y = 1;
	Pieza* aux8 = new alfil(pos, 1);
	listapiezas.agregar(aux8);

	pos.x = 6;
	Pieza* aux9 = new alfil(pos, 1);
	listapiezas.agregar(aux9);

	pos.y = 8;
	Pieza* aux10 = new alfil(pos, 0);
	listapiezas.agregar(aux10);

	pos.x = 3;
	Pieza* aux11 = new alfil(pos, 0);
	listapiezas.agregar(aux11);

	pos.x = 1;
	pos.y = 1;
	Pieza* aux12 = new torre(pos, 1);
	listapiezas.agregar(aux12);

	pos.x = 8;
	Pieza* aux13 = new torre(pos, 1);
	listapiezas.agregar(aux13);

	pos.x = 1;
	pos.y = 8;
	Pieza* aux14 = new torre(pos, 0);
	listapiezas.agregar(aux14);

	pos.x = 8;
	Pieza* aux15 = new torre(pos, 0);
	listapiezas.agregar(aux15);
	*/


	listapiezas.inicializarturnos();
}

void mundo::dibuja() {
	gluLookAt(x, y, z,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	tablero1.Dibuja();
	marco1.dibuja();

	//dibuja todas las piezas de la lista
	listapiezas.dibuja();

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/log1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);    glVertex3f(6, 8.75, -0.1);
	glTexCoord2d(1, 1);    glVertex3f(10, 8.75, -0.1);
	glTexCoord2d(1, 0);    glVertex3f(10, 9.5, -0.1);
	glTexCoord2d(0, 0);    glVertex3f(6,9.5, -0.1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	//glTranslatef(10, 10, 0);
}


void mundo::mueve()
{
	Vector posini, posfin;

	cout << "Dime la columna y fila de la pieza que quieres mover" << endl;
	cin >> posini.x>>posini.y;
	fflush;

	cout << "Dime la columna y fila del lugar donde quieres mover la pieza" << endl;
	cin >> posfin.x >> posfin.y;
	fflush;

	if(listapiezas.switchca(listapiezas.comprobar(posini), posfin) ==0)
	cout << "NO SE PUEDE REALIZAR EL MOVIMIENTO, HAY UNA PIEZA EN SU TRAYECTORIA" << endl;
	else {
	listapiezas.comerpeones(listapiezas.comprobar(posini), posfin);
	listapiezas.mueve(posfin, listapiezas.comprobar(posini));
	listapiezas.comer(listapiezas.comprobar(posini), posfin);
	listapiezas.cambiarturnos();
	
	
}



int mundo::final()
{
	if ((reyn.getx() == 10 && reyn.gety() == 8) || (reyb.getx() == 10 && reyb.gety() == 8))
		return 1;
	else return 0;

}


void mundo::hayjaqueB() //ok
{
	if (caballob1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl; //Cambiar por imagen que salte en pantalla
	if (caballob2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torreb1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torreb2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfilb1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfilb2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (reinab.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;

}

void mundo::hayjaqueN() //ok
{
	if (caballon1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (caballon2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torren1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torren2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfiln1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfiln2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (reinan.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;

}
