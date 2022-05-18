#pragma once

#define ERROR 0
#define AVANZA1 1
#define AVANZA2 2
#define COME 3



class peonn {
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;

public:
	int come;
	int avanza;
	int turno;

public:
	peonn();
	peonn(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();
	void mueve(float posxfin, float posyfin);
	void setpos(float x, float y);
	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	float getposx();
	float getposy();

};