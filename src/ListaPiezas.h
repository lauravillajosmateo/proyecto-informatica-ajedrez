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


class ListaPiezas{
  
  Pieza* lista[MAX_PIEZAS];
  int numero;
  
public:
      ListaPiezas();
      bool agregar(Pieza* p);
      void dibuja();
      void mueve(Vector ini, Vector fin);
  
      Pieza* comprobar(Vector);
      void switchc(Pieza* p);
  
};
