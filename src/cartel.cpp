#include "cartel.h"




void Cartel::dibujatblancas()
{
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("TURNO DE ANGELES", -8.5, 25);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1 ", -10.5, 0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 2 ", -10.5, 3.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1   2   3   4   5   6    7   8", -8, -2);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 3 ", -10.5, 6.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 4  ", -10.5, 9.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 5 ", -10.5, 12.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 6  ", -10.5, 15.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 7 ", -10.5, 18.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 8", -10.5, 21.5);
}


void Cartel::dibujatnegras()
{
	gluLookAt(0, 7.5, 30,
		0.0, 7.5, 0.0,
		0.0, 1.0, 0.0);
	ETSIDI::setTextColor(255, 0, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("TURNO DE DEMONIOS", -8.5, 25);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1 ", -10.5, 0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 2 ", -10.5, 3.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1   2   3   4   5   6    7   8", -8, -2);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 3 ", -10.5, 6.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 4  ", -10.5, 9.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 5 ", -10.5, 12.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 6  ", -10.5, 15.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 7 ", -10.5, 18.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 8", -10.5, 21.5);
}

//void Cartel::dibujanumeros()
//{
	
		
	
//}

//void Cartel::dibujacomido()
//{
//	gluLookAt(0, 7.5, 30,
//		0.0, 7.5, 0.0,
//		0.0, 1.0, 0.0);
//	ETSIDI::setTextColor(255, 0, 0);
//	ETSIDI::setFont("fuentes/Bitwise.ttf", 30);
//	ETSIDI::printxy("PIEZA COMIDA", -7.5, 11);
//
//
//
//}