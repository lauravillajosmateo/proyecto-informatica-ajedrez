#pragma once

#define MOV_CORRECTO 1
#define ERROR 0 
class alfil
{
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;
public:
	alfil();
	alfil(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();
	void mueve(float posxini, float posyini, float posxfin, float posyfin);
	void setcolor(unsigned char r, unsigned char a, unsigned char v);
	void setpos(float x, float y);

	float getx();
	float gety();

	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
};

