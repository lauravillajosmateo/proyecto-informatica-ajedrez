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

//bool ListaPeonBlanco::comparax(float posx)
//{
//	for (int i = 0; i < numero; i++) {
//
//		if (lista[i]->getposx() == posx)
//			return true;
//		else
//			return false;
//
//	}
//}

void ListaPeonBlanco::cambiacome(int indice)
{
	lista[indice]->come = 1;
}

void ListaPeonBlanco::cambiavanza(int indice)
{
	lista[indice]->avanza = 1;
}

//void ListaPeonBlanco::resetcomeavanza()
//{
//	for (int i = 0; i < numero; i++) {
//		lista[i]->avanza = 0;
//		lista[i]->come = 0;
//	}
//}

int ListaPeonBlanco::compara(float px, float py)
{
	int j = 10;

	for (int i = 0; i < numero; i++) {
		if (lista[i]->getposx() == px && lista[i]->getposy() == py) { //si es igual, devuelve la posicion del peon que lo cumple cambiando el valor de j, (entre 0 y 7)
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

void ListaPeonBlanco::mueve( float posxf, float posyf, float posxfinf, float posyfinf)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getposx() == posxf && lista[i]->getposy() == posyf) {
			lista[i]->mueve(posxfinf, posyfinf);
			cout << "entra en mueve" << endl;
	
		}
		lista[i]->avanza = 0;
		lista[i]->come = 0; //una vez se ha movido la pieza se vuelve a inicializar a 0 para volver a comprobar
	}

}