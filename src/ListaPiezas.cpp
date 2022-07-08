#include "ListaPiezas.h"
#include "Pieza.h"


using namespace std;

ListaPiezas::ListaPiezas() {
	for (int i = 0; i < MAX_PIEZAS; i++) {
		lista[i] = 0;
	}
	numero = 0;
	turno = 0;
}

bool ListaPiezas::agregar(Pieza* p)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == p)
			return false;
	}

	if (numero < MAX_PIEZAS)
		lista[numero++] = p;
	else
		return false; 
	return true;
}

void ListaPiezas::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->dibuja();
	}
}



bool ListaPiezas::getturno()
{
	
	return turno;
}


Pieza* ListaPiezas::comprobar(Vector pos) //comprobar posicion inicial
{
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getpos() == pos)
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
		if (lista[i]->getturno() == 2 && lista[i]->getcolor() == BLANCO)//si una blanca se ha movido
		{
			turno = 1; //turno negras
			lista[i]->setturno(1);
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
			turno = 0; //turno blancas
			lista[i]->setturno(1);
			for (int j = 0; j < numero; j++)
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

