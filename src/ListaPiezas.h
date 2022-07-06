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
  
      Pieza* comprobar(Vector);
	void inicializarturnos();
	void cambiarturnos(); 
	void dibujatblancas();
	void dibujatnegras();
	void hayjaque();
	void jaquemate();
	
	
	friend class torre;
	friend class Pieza;
	friend class peon;
	friend class alfil;
	friend class caballo;
	friend class rey;
	friend class reina;
  
};
