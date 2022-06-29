#include "ListaPiezas.h"

using namespace std;

ListaPiezas::ListaPiezas(){
  for(int i=0; i<MAX_PIEZAS; i++)
  {
    lista[i]=0;
  }
  numero=0;
  mover=1;
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

void ListaPiezas::mueve(Vector fin, Pieza* p){
  p->movimientos(fin);
  p->setavanza(0);
  p->setcome(0);
}

Pieza* ListaPiezas::comprobar(Vector pos){ //comprobar posicion inicial
  for(int i=0; i<32; i++){
    if (lista[i]->getpos()=pos)
      return lista[i];
  }
}

void ListaPiezas::comerpeones(Pieza* p, Vector v) //comprobar come y avanza. Le pasamos la pieza del peon que se va a mover y el vector de la posicion final a la que se mueve
{
	for (int i = 0; i < 32; i++)
	{
		if (p->getmarca() == 1 && p->getcolor()==0  && lista[i]->getcolor() == 1 && (lista[i]->getpos() = v))
		{
			p->setcome(1);
		}
		else if (p->getmarca() == 1 && p->getcolor() == 1 && lista[i]->getcolor() == 0 && (lista[i]->getpos() = v))
		{
			p->setcome(1);
		}

		else
		{
			p->setavanza(1);
		}
	}
}

void ListaPiezas::inicializarturnos() //para inicializar en el primer movimiento de la partida
{
	for (int i = 0; i < 32; i++)
	{
		if (lista[i]->getcolor() == 0) // empiezan blancas porque estan a 0. Negras esperan
		{
			lista[i]->setturno(0);
		}
		else
			lista[i]->setturno(1);
	}
}

void ListaPiezas::cambiarturnos()
{
	for (int i = 0; i < 32; i++)
	{
		dibujatblancas();
		if (lista[i]->getturno() == 1 && lista[i]->getcolor() == 0)//si una blanca se ha movido
		{
			for (int j = 0; j < 32; j++)
			{
				if (lista[j]->getcolor() == 0)
				{
					lista[j]->setturno(1);//se acaba turno blancas
					
				}
				else
				{
					lista[j]->setturno(0);//y empieza turno negras
				}
			}
		}

		else if (lista[i]->getturno() == 1 && lista[i]->getcolor() == 1)
		{
			dibujatnegras();
			for (int j = 0; j < 32; j++)
			{
				if (lista[j]->getcolor() == 1)
				{
					lista[j]->setturno(1);//se acaba turno negras

				}
				else
				{
					lista[j]->setturno(0);//y empieza turno blancas
				}
			}

		}
	}
}

void ListaPiezas::comer(Pieza* p, Vector v) //vector de posicion final
{											//comprueba que una pieza se puede comer y la manda al cementerio de piezas
	for (int i = 0; i < 32; i++)
	{
		if (p->getcolor() == 1 && (lista[i]->getpos() = v) && lista[i]->getcolor()==0 && lista[i]->getturno()==1)
		{
			Vector x(11, 3);
			lista[i]->setpos(x);
			cout << "Tu pieza ha sido comida" << endl << endl;
		}

		else if (p->getcolor() == 0 && (lista[i]->getpos() = v) && lista[i]->getcolor() == 1 && lista[i]->getturno() == 1)
		{
			Vector y(-3, 3);
			lista[i]->setpos(y);
			cout << "Tu pieza ha sido comida" << endl << endl;
		}
	}

}

void ListaPiezas::dibujatblancas()
{
	gluLookAt(0, 7.5, 30,
	0.0, 7.5, 0.0,
	0.0, 1.0, 0.0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("TURNO DE ANGELES", -8.5, 25);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1 ", -10.5, 0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 2 ", -10.5, 3.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1   2   3   4   5   6    7   8", -8, -2);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 3 ", -10.5, 6.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 4  ", -10.5, 9.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 5 ", -10.5, 12.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 6  ", -10.5, 15.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 7 ", -10.5, 18.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 8", -10.5, 21.5);
}

void ListaPiezas::dibujatnegras()
{
	gluLookAt(0, 7.5, 30,
	0.0, 7.5, 0.0,
	0.0, 1.0, 0.0);
	ETSIDI::setTextColor(255, 0, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy("TURNO DE DEMONIOS", -8.5, 25);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1 ", -10.5, 0);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 2 ", -10.5, 3.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 1   2   3   4   5   6    7   8", -8, -2);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 3 ", -10.5, 6.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 4  ", -10.5, 9.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 5 ", -10.5, 12.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 6  ", -10.5, 15.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 7 ", -10.5, 18.5);
	ETSIDI::setTextColor(255, 255, 255);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 20);
	ETSIDI::printxy(" 8", -10.5, 21.5);
}

int ListaPiezas::switchca(Pieza* p, Vector fin) {

	Vector aux = p->getpos();

	switch (p->getmarca())
	{
	case 0: 
			mover = 1;
			break;

	case 1: 
		mover = 1;
		break;

	case 2: { //TORRE

		//hacia arriba
		
			if (fin.x == p->getpos().x && fin.y > p->getpos().y)
			{
				do
				{
					for (int i = 0; i < 32; i++) {
						if (aux = lista[i]->getpos())
						{
							mover = 0;
						}
						
					}

					aux.y++; 
				} while (aux.y != fin.y);//mover 0 es que NO se puede mover
			}

		//hacia izquierda
			if (fin.x < p->getpos().x && fin.y == p->getpos().y)
			{
				do
				{
					for (int i = 0; i < 32; i++) {
						if (aux = lista[i]->getpos())
						{
							mover = 0;
						}

					}

					aux.x--;
				} while (aux.x != fin.x);//mover 0 es que NO se puede mover
			}

			//hacia derecha
			if (fin.x > p->getpos().x && fin.y == p->getpos().y)
			{
				do
				{
					for (int i = 0; i < 32; i++) {
						if (aux = lista[i]->getpos())
						{
							mover = 0;
						}

					}

					aux.x++;
				} while (aux.x != fin.x);//mover 0 es que NO se puede mover
			}

			//hacia abajo

			if (fin.x == p->getpos().x && fin.y < p->getpos().y)
			{
				do
				{
					for (int i = 0; i < 32; i++) {
						if (aux = lista[i]->getpos())
						{
							mover = 0;
						}

					}

					aux.y--;
				} while (aux.y != fin.y);//mover 0 es que NO se puede mover
			}
			break;
		
				
	}

	case 3: //caballo
		mover = 1;
		break;

	case 4: //alfil
	{
		//arriba derecha

		if (fin.x > p->getpos().x && fin.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x++;
			} while (aux.x != fin.x || aux.y != fin.y);
		}


		//arriba izquierda
		if (fin.x < p->getpos().x && fin.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x--;
			} while (aux.x != fin.x || aux.y != fin.y);
		}

		//abajo derecha

		if (fin.x > p->getpos().x && fin.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y--;
				aux.x++;
			} while (aux.x != fin.x || aux.y != fin.y);
		}

		//abajo izquierda
		if (fin.x < p->getpos().x && fin.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y--;
				aux.x--;
			} while (aux.x != fin.x || aux.y != fin.y);
		}

		
		break;
	}

	case 5: {//reina

		//hacia arriba

		if (fin.x == p->getpos().x && fin.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++) {
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.y++;
			} while (aux.y != fin.y);//mover 0 es que NO se puede mover
		}

		//hacia izquierda
		if (fin.x < p->getpos().x && fin.y == p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++) {
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.x--;
			} while (aux.x != fin.x);//mover 0 es que NO se puede mover
		}

		//hacia derecha
		if (fin.x > p->getpos().x && fin.y == p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++) {
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.x++;
			} while (aux.x != fin.x);//mover 0 es que NO se puede mover
		}

		//hacia abajo

		if (fin.x == p->getpos().x && fin.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++) {
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}

				}

				aux.y--;
			} while (aux.y != fin.y);//mover 0 es que NO se puede mover
		}
		//arriba derecha

		if (fin.x > p->getpos().x && fin.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x++;
			} while (aux.x != fin.x || aux.y != fin.y);
		}


		//arriba izquierda
		if (fin.x < p->getpos().x && fin.y > p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y++;
				aux.x--;
			} while (aux.x != fin.x || aux.y != fin.y);
		}

		//abajo derecha

		if (fin.x > p->getpos().x && fin.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y--;
				aux.x++;
			} while (aux.x != fin.x || aux.y != fin.y);
		}

		//abajo izquierda
		if (fin.x < p->getpos().x && fin.y < p->getpos().y)
		{
			do
			{
				for (int i = 0; i < 32; i++)
				{
					if (aux = lista[i]->getpos())
					{
						mover = 0;
					}
				}

				aux.y--;
				aux.x--;
			} while (aux.x != fin.x || aux.y != fin.y);
		}


		break;
	}

	case 6:{ mover = 1;
		break;}
			
	
	}
	return mover;

}
