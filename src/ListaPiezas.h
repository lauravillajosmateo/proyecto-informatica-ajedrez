#pragma once
#define MAX_PIEZAS 35

#include "Vector.h"
#include <iostream>

class Pieza;
class ListaPiezas{
  
  Pieza* lista[MAX_PIEZAS];
  int numero;
  int mover;
  
public:
      ListaPiezas();
      bool agregar(Pieza* p);
      void dibuja();
      void mueve(Vector fin, Pieza* p);
  
      Pieza* comprobar(Vector);
      int switchca(Pieza* p, Vector v);
  	void comerpeones(Pieza* p, Vector v);
	void inicializarturnos();
	void cambiarturnos();
	void comer(Pieza* p, Vector v); 
	void dibujatblancas();
	void dibujatnegras();
	void hayjaque();
	void jaquemate();
  
};
