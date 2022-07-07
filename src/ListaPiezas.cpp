#include "ListaPiezas.h"
#include "Pieza.h"

using namespace std;

ListaPiezas::ListaPiezas(){
  for(int i=0; i<MAX_PIEZAS; i++)
  {
    lista[i]=0;
  }
  numero=0;
 
}

bool ListaPiezas::agregar(Pieza* p)
{
  for(int i=0; i<numero; i++)
  {
    if(lista[i]==p)
      return false;
  }
  
  if(numero<MAX_PIEZAS)
    lista[numero++]=p;
  else
    return false;
  return true;
}

void ListaPiezas::dibuja(){
  for(int i=0; i<numero; i++){
    lista[i]->dibuja();
  }
}


Pieza* ListaPiezas::comprobar(Vector pos){ //comprobar posicion inicial
  for(int i=0; i<nummero; i++){
    if (lista[i]->getpos()==pos)
      return lista[i];
  }
	return NULL;
}


void ListaPiezas::inicializarturnos() //para inicializar en el primer movimiento de la partida
{
	for (int i = 0; i < numero; i++)
	{
		if (lista[i]->getcolor() == 0) // empiezan blancas porque estan a 0. Negras esperan
		{
			lista[i]->setturno(0);
		}
		else
			lista[i]->setturno(1);
	}
}

void ListaPiezas::cambiarturnos()
{
	for (int i = 0; i < numero; i++)
	{
		dibujatblancas();
		if (lista[i]->getturno() == 2 && lista[i]->getcolor() == BLANCO)//si una blanca se ha movido
		{
			for (int j = 0; j < numero; j++)
			{
				if (lista[j]->getcolor() == BLANCO)
				{
					lista[j]->setturno(1);//se acaba turno blancas
					
				}
				else
				{
					lista[j]->setturno(0);//y empieza turno negras
				}
			}
		}

		if (lista[i]->getturno() == 2 && lista[i]->getcolor() == NEGRO)
		{
			lista[i]->setturno(1);
			dibujatnegras();
			for (int j = 0; j < 32; j++)
			{
				if (lista[j]->getcolor() == NEGRO)
				{
					lista[j]->setturno(1);//se acaba turno negras

				}
				else
				{
					lista[j]->setturno(0);//y empieza turno blancas
				}
			}

		}
	}
}



void ListaPiezas::dibujatblancas()
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

void ListaPiezas::dibujatnegras()
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


