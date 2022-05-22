#include "Pieza.h"

Pieza::Pieza() {
	posxini = 0;
	posyini = 0;
}

void Pieza::setpos(float x, float y) {
	posxini=x;
	posyini = y;
}

float Pieza::getx() {
	return posxini;
}

float Pieza::gety() {
	return posyini;
}

