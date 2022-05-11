#include "ListaPeonNegro.h"

ListaPeonNegro::ListaPeonNegro() {
	for (int i = 0; i < MAX_PEON; i++) {
		lista[i] = 0;
	}
	numero = 0;
}

void ListaPeonNegro::dibuja() {
	for (int i = 0; i < numero; i++) {
		lista[i]->dibuja();
	}
}


void ListaPeonNegro::mueve(float posx, float posy, float posxfin, float posyfin)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getposx() == posx && lista[i]->getposy() == posy)
			lista[i]->mueve(posxfin, posyfin);
	}
}

bool ListaPeonNegro::agregar(peonn* p)
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



float ListaPeonNegro::getx(int indice)
{
	for (int i = 0; i < numero; i++) {
		if (indice == i)
			return lista[i]->getposx();
	}
}

float ListaPeonNegro::gety(int indice)
{
	for (int i = 0; i < numero; i++) {
		if (indice == i)
			return lista[i]->getposy();
	}
}

