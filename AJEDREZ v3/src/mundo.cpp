#include "mundo.h"
#include "freeglut.h"
#include <iostream>

using namespace std;


mundo::mundo()
{
	x = 4.0;
	y = 4.0;
	z = 15.0;
}


void mundo::inicializa()
{

	reinan.setpos(3.5f, 0.5f);
	reinab.setpos(4.5f, 7.5f);

	reyn.setpos(4.5f, 0.5f);
	reyb.setpos(3.5f, 7.5f);

	caballob1.setpos(1.5f, 7.5f);
	caballob2.setpos(6.5f, 7.5f);
	caballon1.setpos(1.5f, 0.5f);
	caballon2.setpos(6.5f, 0.5f);

	torren1.setpos(0.5f, 0.5f);
	torren2.setpos(7.5f, 0.5f);
	torreb1.setpos(0.5f, 7.5f);
	torreb2.setpos(7.5f, 7.5f);

	alfiln1.setpos(2.5f, 0.5f);
	alfiln2.setpos(5.5f, 0.5f);
	alfilb1.setpos(2.5f, 7.5f);
	alfilb2.setpos(5.5f, 7.5f);



	for (int i = 0; i < 8; i++)
	{
		peonn* aux = new peonn(0.5+i, 1.5, 0, 0, 0);
		listapeonn.agregar(aux);
	}

	for (int i = 0; i < 8; i++)
	{
		peon* aux = new peon(0.5 + i, 6.5, 175, 175, 175);
		listapeonb.agregar(aux);
	}
}

void mundo::dibuja() {
	gluLookAt(x, y, z,  // posicion del ojo
		4.0, 4.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	tablero1.Dibuja();
	marco1.dibuja();

	listapeonn.dibuja();
	listapeonb.dibuja();

	reyn.dibuja();
	reyb.dibuja();

	reinan.dibuja();
	reinab.dibuja();

	alfiln1.dibuja();
	alfiln2.dibuja();
	alfilb1.dibuja();
	alfilb2.dibuja();

	caballon1.dibuja();
	caballon2.dibuja();
	caballob1.dibuja();
	caballob2.dibuja();

	torreb1.dibuja();
	torreb2.dibuja();
	torren1.dibuja();
	torren2.dibuja();


}

void mundo::tecla(unsigned char key) {
}




void mundo::mueve() {
	float posx, posy, posxfin, posyfin;
	float posxf, posyf, posxfinf, posyfinf;

	cout << "Dime las coordenadas 'x' e 'y' de la pieza que quieres mover" << endl;
	cin >> posx >> posy;

	cout << "Dime las coordenadas 'x' e 'y' donde quieres mover la pieza" << endl;
	cin >> posxfin >> posyfin;

	posxf = posx - 0.5;
	posyf = posy - 0.5;
	posxfinf = posxfin - 0.5;
	posyfinf = posyfin - 0.5;


	//Comprobacion peon blanco con piezas negras
	int j = listapeonb.compara(posxf, posyf);//peon blanco del que quiero comprobar, el que voy a mover
	if (j < 8) { //algun peon blanco coincide con las posiciones iniciales introducidas
		for (int i = 0; i < 8; i++) {
			if ((listapeonn.getx(i) == posxfinf && listapeonn.gety(i) == posyfinf) || (posxfinf == alfiln1.getx() && posyfinf == alfiln1.gety()) || (posxfinf == alfiln2.getx() && posyfinf == alfiln2.gety()) || (posxfinf == caballon1.getx() && posyfinf == caballon1.gety()) || (posxfinf == caballon2.getx() && posyfinf == caballon2.gety()) || (posxfinf == reinan.getx() && posyfinf == reinan.gety()) || (posxfinf == reyn.getx() && posyfinf == reyn.gety()) || (posxfinf == torren1.getx() && posyfinf == torren1.gety()) || (posxfinf == torren2.getx() && posyfinf == torren2.gety()))
			{//compruebas cada peon negro y el resto de las piezas
				listapeonb.cambiacome(j); //COME=TRUE, AVANZA=FALSE
			}
			else {
				listapeonb.cambiavanza(j); //AVANZA=TRUE,COME=FALSE

			}


		}
	}

	//comprobacion peon negro con piezas blancas
	int r = listapeonn.compara(posxf, posyf);
	if (r < 8) {
		for (int i = 0; i < 8; i++) {
			if ((listapeonb.getx(i) == posxfinf && listapeonb.gety(i) == posyfinf) || (posxfinf == alfilb1.getx() && posyfinf == alfilb1.gety()) || (posxfinf == alfilb2.getx() && posyfinf == alfilb2.gety()) || (posxfinf == caballob1.getx() && posyfinf == caballob1.gety()) || (posxfinf == caballob2.getx() && posyfinf == caballob2.gety()) || (posxfinf == reinab.getx() && posyfinf == reinab.gety()) || (posxfinf == reyb.getx() && posyfinf == reyb.gety()) || (posxfinf == torreb1.getx() && posyfinf == torreb1.gety()) || (posxfinf == torreb2.getx() && posyfinf == torreb2.gety()))
			{
				listapeonn.cambiacome(r); //COME=TRUE, AVANZA=FALSE
			}
			else {
				listapeonn.cambiavanza(r); //AVANZA=TRUE,COME=FALSE
			}

		}

	}


		listapeonb.mueve(posxf, posyf, posxfinf, posyfinf);
		listapeonn.mueve(posxf, posyf, posxfinf, posyfinf);

		alfilb1.mueve(posxf, posyf, posxfinf, posyfinf);
		alfilb2.mueve(posxf, posyf, posxfinf, posyfinf);
		alfiln1.mueve(posxf, posyf, posxfinf, posyfinf);
		alfiln2.mueve(posxf, posyf, posxfinf, posyfinf);

		reinab.mueve(posxf, posyf, posxfinf, posyfinf);
		reinan.mueve(posxf, posyf, posxfinf, posyfinf);

		torreb1.mueve(posxf, posyf, posxfinf, posyfinf);
		torreb2.mueve(posxf, posyf, posxfinf, posyfinf);
		torren1.mueve(posxf, posyf, posxfinf, posyfinf);
		torren2.mueve(posxf, posyf, posxfinf, posyfinf);

		caballob1.mueve(posxf, posyf, posxfinf, posyfinf);
		caballob2.mueve(posxf, posyf, posxfinf, posyfinf);
		caballon1.mueve(posxf, posyf, posxfinf, posyfinf);
		caballon2.mueve(posxf, posyf, posxfinf, posyfinf);
	
}
