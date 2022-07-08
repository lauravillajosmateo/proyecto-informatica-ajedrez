#include "mundo.h"
#include <freeglut.h>
#include <iostream>
#include "ETSIDI.h"

using namespace std;


mundo::mundo()
{
	x = 4.0;
	y = 4.0;
	z = 15.0;
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
	gluLookAt(x, y, z,  
		4.0, 4.0, 0.0,      
		0.0, 1.0, 0.0);    

	tablero1.Dibuja();
	marco1.dibuja();

	listapiezas.dibuja();
	if (listapiezas.getturno() == 0)
		dibujatblancas();
	if(listapiezas.getturno() == 1)
		dibujatnegras();


	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/log1.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); 
	glVertex3f(14, 25, 0.1); //arriba izquierda
	glTexCoord2d(1, 1); 
	glVertex3f(24, 25, 0.1); //arriba derecha
	glTexCoord2d(1, 0); 
	glVertex3f(24, 27, 0.1); //abajo izquierda
	glTexCoord2d(0, 0); 
	glVertex3f(14, 27, 0.1); //abajo derecha
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);


}
	


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
		p->avisoincorrecto(posfin, listapiezas);
		p->movimientos(posfin, listapiezas);

		listapiezas.cambiarturnos();

	}
}


void mundo::dibujatblancas()
{
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("TURNO DE ANGELES", -8.5, 25);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1 ", -10, 1);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 2 ", -10, 4.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("   1   2   3   4   5   6    7   8", -8, -2);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 3 ", -10, 7.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 4  ", -10, 10.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 5 ", -10, 13.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 6  ", -10, 16.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 7 ", -10, 19.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 8", -10, 22.5);
}

void mundo::dibujatnegras()
{
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	ETSIDI::setTextColor(255, 0, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("TURNO DE DEMONIOS", -8.5, 25);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1 ", -10, 1);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 2 ", -10, 4.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("   1   2   3   4   5   6    7   8", -8, -2);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 3 ", -10, 7.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 4  ", -10, 10.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 5 ", -10, 13.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 6  ", -10, 16.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 7 ", -10, 19.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 8", -10, 22.5);
}
