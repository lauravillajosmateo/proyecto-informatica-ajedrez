#pragma once
#define MOV_CORRECTO 1

class torreN
{
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;
	int turno;
public:
	torreN();
	torreN(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();

	void setpos(float x, float y);

	float getx();
	float gety();

	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);
	int getturno();
	void setturno(int t);

};

