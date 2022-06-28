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
    
