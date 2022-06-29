#pragma once
#define MAX_PIEZAS 35
#include "Pieza.h"
#include "ListaPeonBlanco.h"
#include "rey.h"
#include "alfil.h"
#inlclude "caballo.h"
#include "reina.h"
#include "torre.h"
#include "Vector.h"
#include <iostream>

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
      void switchca(Pieza* p, Vector v);
  	  void comerpeones(Pieza* p, Vector v);
	    void inicializarturnos();
	    void cambiarturnos();
	    void comer(Pieza* p, Vector v); 
	    int getmover();
  
};
