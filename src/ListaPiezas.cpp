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


/*void ListaPiezas::hayjaque()
{

	Vector preynegro;
	Vector preyblanco;
	for (int i = 0; i < 32; i++)
	{
		if (lista[i]->getmarca()==REY && lista[i]->getcolor()==BLANCO)
		{
			preyblanco = (lista[i]->getpos());
		}
		else if (lista[i]->getmarca() == REY && lista[i]->getcolor() == NEGRO)
		{
			preynegro = (lista[i]->getpos());
		}

	}
	for (int j = 0; j < 32; j++)
	{
		if (lista[j]->mov_correcto(preynegro) == 1 && switchca(lista[j], preynegro) == 1)
		{
			cout << "HAY JAQUE PARA NEGRAS" << endl;
		}

		else if (lista[j]->mov_correcto(preyblanco) == 1 && switchca(lista[j], preyblanco) == 1)
		{
			cout << "HAY JAQUE PARA BLANCAS" << endl;
		}
	}

}

void ListaPiezas::jaquemate()
{

	Vector derecha(1, 0);
	Vector izquierda(-1, 0), arriba(0,1), abajo(0,-1), diagonald(1,1), diagonald2(1,-1), diagonald3(-1,-1), diagonald4(-1,1);
	
	int contador=0, contadorn=0;
	Vector preynegro, preyblanco;
	for (int i = 0; i < 32; i++) //para encontrar al rey en la lista
	{
		
		if (lista[i]->getmarca() == REY && lista[i]->getcolor() == BLANCO)
		{
			preyblanco = lista[i]->getpos();

		}
		if (lista[i]->getmarca() == REY && lista[i]->getcolor() == NEGRO)
		{
			preynegro = lista[i]->getpos();

		}
	}

	for (int j = 0; j < 32; j++) //comprobar movimientos posibles
	{

		if (lista[j]->mov_correcto(preyblanco + derecha) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + derecha) == 1 || (preyblanco+derecha).x>8)
			contador++;

		if (lista[j]->mov_correcto(preyblanco + diagonald2) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + diagonald2) == 1 || (preyblanco+diagonald2).x>8 || (preyblanco + diagonald2).y <1)
			contador++;
		if (lista[j]->mov_correcto(preyblanco + abajo) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + abajo) == 1 || (preyblanco + abajo).y <1)
			contador++;
		if (lista[j]->mov_correcto(preyblanco + diagonald3) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + diagonald3) == 1 || (preyblanco + diagonald3).x < 1 || (preyblanco + diagonald3).y < 1)
			contador++;
		if (lista[j]->mov_correcto(preyblanco + izquierda) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + izquierda) == 1|| (preyblanco + izquierda).x < 1)
			contador++;
		if (lista[j]->mov_correcto(preyblanco + diagonald4) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + diagonald4) == 1||(preyblanco + diagonald4).x < 1 || (preyblanco + diagonald4).y > 8)
			contador++;
		if (lista[j]->mov_correcto(preyblanco + arriba) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + arriba) == 1|| (preyblanco + arriba).y > 8)
			contador++;
		if (lista[j]->mov_correcto(preyblanco + diagonald) == 1 && lista[j]->getcolor() == NEGRO && switchca(lista[j], preyblanco + diagonald) == 1 || (preyblanco + diagonald).y > 8 || (preyblanco + diagonald).x > 8)
			contador++;
	}

	if (contador == 8)
	{
		cout << "JAQUEMATE PARA BLANCOS" << endl;
	}

	for (int j = 0; j < 32; j++) //comprobar movimientos posibles
	{

		if (lista[j]->mov_correcto(preynegro + derecha) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + derecha) == 1 || (preynegro + derecha).x > 8)
			contadorn++;

		if (lista[j]->mov_correcto(preynegro + diagonald2) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + diagonald2) == 1 || (preynegro + diagonald2).x > 8 || (preynegro + diagonald2).y < 1)
			contadorn++;
		if (lista[j]->mov_correcto(preynegro + abajo) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + abajo) == 1 || (preynegro + abajo).y < 1)
			contadorn++;
		if (lista[j]->mov_correcto(preynegro + diagonald3) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + diagonald3) == 1 || (preynegro + diagonald3).x < 1 || (preynegro + diagonald3).y < 1)
			contadorn++;
		if (lista[j]->mov_correcto(preynegro + izquierda) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + izquierda) == 1 || (preynegro + izquierda).x < 1)
			contadorn++;
		if (lista[j]->mov_correcto(preynegro + diagonald4) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + diagonald4) == 1 || (preynegro + diagonald4).x < 1 || (preynegro + diagonald4).y > 8)
			contadorn++;
		if (lista[j]->mov_correcto(preynegro + arriba) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + arriba) == 1 || (preynegro + arriba).y > 8)
			contadorn++;
		if (lista[j]->mov_correcto(preynegro + diagonald) == 1 && lista[j]->getcolor() == BLANCO && switchca(lista[j], preynegro + diagonald) == 1 || (preynegro + diagonald).y > 8 || (preynegro + diagonald).x > 8)
			contadorn++;
	}

	if (contadorn == 8)
	{
		cout << "JAQUEMATE PARA NEGROS" << endl;
	}



}*/
