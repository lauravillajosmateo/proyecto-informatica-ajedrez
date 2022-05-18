#pragma once
#define MOV_CORRECTO 1

class caballo
{
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;
	int turno;
public:
	caballo();
	caballo(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();

	void setpos(float x, float y);
	float getx();
	float gety();

	void movimientos(float posxfin, float posyfin);
	int mov_correcto(float posxfin, float posyfin);
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);
	int getturno();

	void setturno(int t);

};