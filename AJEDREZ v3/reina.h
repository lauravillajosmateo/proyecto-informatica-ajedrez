#pragma once
class reina
{
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;
public:
	reina();
	reina(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();
	void mueve(float posxfin, float posyfin);
	void setcolor(unsigned char r, unsigned char a, unsigned char v);
	void setpos(float x, float y);
	//int mov_correcto(float posxfin, float posyfin);
	//void movimientos(float posxfin, float posyfin);
};

