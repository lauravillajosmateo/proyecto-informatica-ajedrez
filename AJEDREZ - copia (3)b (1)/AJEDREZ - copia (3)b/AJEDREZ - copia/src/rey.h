#pragma once
#define MOV_CORRECTO 1
#define ERROR 0
#define MOV_ENROQUE 2


class rey {
private:
	unsigned char rojo, verde, azul;
	float posxini, posyini;
public:
	rey();
	rey(float x, float y, unsigned char r, unsigned char a, unsigned char v);
	void dibuja();
	//void mueve(float t);
	void setcolor(unsigned char r, unsigned char a, unsigned char v);
	void setpos(float x, float y);
	int mov_correcto(float posxfin, float posyfin);
	void movimientos(float posxfin, float posyfin);
	void mueve(float posxinif, float posyinif, float posxfinf, float posyfinf);

};