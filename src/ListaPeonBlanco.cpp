#include "ListaPeonBlanco.h"
#include <iostream>

using namespace std;

ListaPeonBlanco::ListaPeonBlanco() {
	for (int i = 0; i < MAX_PEON; i++) {
		lista[i] = 0;
	}
	numero = 0;
}

void ListaPeonBlanco::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->dibuja();
	}
}


void ListaPeonBlanco::cambiacome(int indice)
{
	lista[indice]->come = 1;
}

void ListaPeonBlanco::cambiavanza(int indice)
{
	lista[indice]->avanza = 1;
}

int ListaPeonBlanco::compara(float px, float py)
{
	int j = 10;

	for (int i = 0; i < numero; i++) {
		if (lista[i]->getx() == px && lista[i]->gety() == py) { //si es igual, devuelve la posicion del peon que lo cumple cambiando el valor de j, (entre 0 y 7)
			j = i;
		}
	}

	return j;
}

bool ListaPeonBlanco::agregar(peon* p)
{
	for (int i = 0; i < numero; i++) {//para evitar que no se crea una esfera si ya existe una igual
		if (lista[i] == p)
			return false;//si es igual que otra ya creada, devuelve false y por lo tanto no se crea una nueva
	}

	if (numero < MAX_PEON)
		lista[numero++] = p; // último puesto sin rellenar
	else
		return false; // capacidad máxima alcanzada
	return true;
}

void ListaPeonBlanco::mueve(float posxf, float posyf, float posxfinf, float posyfinf)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getx() == posxf && lista[i]->gety() == posyf) {
			lista[i]->mueve(posxfinf, posyfinf);

		}
		lista[i]->avanza = 0;
		lista[i]->come = 0; //una vez se ha movido la pieza se vuelve a inicializar a 0 para volver a comprobar
	}

}

float ListaPeonBlanco::getx(int indice)
{
	for (int i = 0; i < numero; i++) {
		if (indice == i)
			return lista[i]->getx();
	}
}

float ListaPeonBlanco::gety(int indice)
{
	for (int i = 0; i < numero; i++) {
		if (indice == i)
			return lista[i]->gety();
	}
}

bool ListaPeonBlanco::comprobacioncome(int indice, float posxfinf, float posyfinf) {
	if (lista[indice]->come == 1 && lista[indice]->mov_correcto(posxfinf, posyfinf) == 3)
		return true;
	else
		return false;

}

void ListaPeonBlanco::setpos(int indice, float posx, float posy) {
	lista[indice]->setpos(posx, posy);
}

void ListaPeonBlanco::setturno(int t)
{
	if (t == 0) {
		for (int i = 0; i < numero; i++)
			lista[i]->turno = 0;
	}
	else if (t == 1) {
		for (int i = 0; i < numero; i++)
			lista[i]->turno = 1;
	}
}



int ListaPeonBlanco::getturno() {
	int x = 0;
	for (int i = 0; i < numero; i++) {
		if (lista[i]->turno == 1)
			x = 1;
	}
	return x;
}