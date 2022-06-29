#include "ListaPiezas.h"

ListaPiezas::ListaPiezas(){
  for(int i=0; i<MAX_PIEZAS; i++)
  {
    lista[i]=0;
  }
  numero=0;
}

bool ListaPiezas::agregar(Pieza* p)
{
  for(int i=0; i<numero; i++)
  {
    if(lista[i]==p)
      return false;
  }
  
  if(numero<MAX_PIEZAS)
    lista[numero++]=p;
  else
    return false;
  return true;
}

void ListaPiezas::dibuja(){
  for(int i=0; i<numero; i++){
    lista[i]->dibuja();
  }
}

void ListaPiezas::mueve(Vector ini, Vector fin){
  for (int i=0; i<numero; i++)
    lista[i]->mueve(ini, fin);
}

Pieza* ListaPiezas::comprobar(Vector pos){
  for(int i=0; i<32; i++){
    if (lista[i]->getpos()=pos)
      return lista[i];
  }
}

void ListaPiezas::switchca(Pieza* p){
  
}
