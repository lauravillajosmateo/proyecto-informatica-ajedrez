#pragma once

class Pieza {
protected:
	float posxini, posyini;

public:
	Pieza();
	void setpos(float x, float y);
	float getx();
	float gety();
};