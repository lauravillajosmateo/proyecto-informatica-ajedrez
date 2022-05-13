#pragma once

#define MOV_CORRECTO 1

class torre
{
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;
public:
	torre();
	torre(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();
	void setcolor(unsigned char r, unsigned char a, unsigned char v);
	void setpos(float x, float y);
	
	float getx();
	float gety();

	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);
};

