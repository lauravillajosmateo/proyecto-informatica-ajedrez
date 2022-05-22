#pragma once
#define MOVIMIENTO_CORRECTO 1
#define ERROR 0

class reinaN
{
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;
	int turno;

public:
	reinaN();
	reinaN(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();

	void setpos(float x, float y);
	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);
	float getx();
	float gety();
	int getturno();
	void setturno(int t);

};

