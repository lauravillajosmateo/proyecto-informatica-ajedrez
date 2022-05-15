#include "mundo.h"
#include "freeglut.h"
#include <iostream>

using namespace std;


mundo::mundo()
{
	x = 4.0;
	y = 4.0;
	z = 15.0;
	turnob = 0; //se mueven blancas
}


void mundo::inicializa()
{

	reinan.setpos(3.5f, 0.5f);
	reyb.setpos(4.5f, 7.5f);

	reyn.setpos(4.5f, 0.5f);
	reinab.setpos(3.5f, 7.5f);

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
		peonn* aux = new peonn(0.5 + i, 1.5, 0, 0, 0);
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




void mundo::mueve()
{
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

	cout << "turnob antes de entrar a comparar las piezas comidas. 0->pieza blanca  " << turnob << endl << endl; //variable para ver si tiene que hacer o no las comprobaciones de comer
	if (turnob == 0) {


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

		//peon negro comido por piezas blancas
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((listapeonn.getx(i) == posxfinf && listapeonn.gety(i) == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(j, posxfinf, posyfinf) == true))
					listapeonn.setpos(i, 10, 3);
			}
		}

		//caballos negros comidos por piezas blancas
		for (int i = 0; i < 8; i++) {
			if ((caballon1.getx() == posxfinf && caballon1.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				caballon1.setpos(10, 3);
		}

		for (int i = 0; i < 8; i++) {
			if ((caballon2.getx() == posxfinf && caballon2.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				caballon2.setpos(10, 3);
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




		for (int i = 0; i < 8; i++) {
			if ((alfiln1.getx() == posxfinf && alfiln1.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				alfiln1.setpos(10, 3);
		}


		//reyN

		for (int i = 0; i < 8; i++) {
			if ((reyn.getx() == posxfinf && reyn.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				reyn.setpos(10, 3);
		}

		for (int i = 0; i < 8; i++) {
			if ((alfiln1.getx() == posxfinf && alfiln1.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				alfiln1.setpos(10, 3);
		}



		for (int i = 0; i < 8; i++) {
			if ((alfiln2.getx() == posxfinf && alfiln1.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				alfiln2.setpos(10, 3);
		}



		for (int i = 0; i < 8; i++) {
			if ((torren1.getx() == posxfinf && torren1.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				torren1.setpos(11, 2);
		}

		for (int i = 0; i < 8; i++) {
			if ((torren2.getx() == posxfinf && torren2.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				torren2.setpos(11, 3);
		}

		for (int i = 0; i < 8; i++) {
			if ((reinan.getx() == posxfinf && reinan.gety() == posyfinf) && ((alfilb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb1.getx() && posyf == alfilb1.gety()) || (alfilb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfilb2.getx() && posyf == alfilb2.gety()) || (torreb1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb1.getx() && posyf == torreb1.gety()) || (torreb2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torreb2.getx() && posyf == torreb2.gety()) || (reinab.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinab.getx() && posyf == reinab.gety()) || (reyb.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyb.getx() && posyf == reyb.gety()) || (caballob1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob1.getx() && posyf == caballob1.gety()) || (caballob2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballob2.getx() && posyf == caballob2.gety()) || listapeonb.comprobacioncome(i, posxfinf, posyfinf) == true))
				reinan.setpos(11, 7);
		}


		cout << "valores de los turnos piezas negras.Si es 0 es que se han movido" << alfilb1.getturno() << alfilb2.getturno() << caballob1.getturno() << caballob2.getturno() << torreb1.getturno() << torreb2.getturno() << reyb.getturno() << reinab.getturno() << endl << endl;

	}
	//aquí turnob=1
	if (turnob == 1) {
		//piezas blancas son comidas
		for (int i = 0; i < 8; i++) {
			if ((reyb.getx() == posxfinf && reyb.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyb.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				reyb.setpos(10, 8);
		}

		for (int i = 0; i < 8; i++) {
			if ((alfilb1.getx() == posxfinf && alfilb1.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyb.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				alfilb1.setpos(10, 7);
		}

		for (int i = 0; i < 8; i++) {
			if ((alfilb2.getx() == posxfinf && alfilb2.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyb.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				alfilb2.setpos(11, 7);
		}

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((listapeonb.getx(i) == posxfinf && listapeonb.gety(i) == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyn.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(j, posxfinf, posyfinf) == true))
					listapeonb.setpos(i, 10, 3);
			}
		}


		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if ((listapeonb.getx(i) == posxfinf && listapeonb.gety(i) == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyn.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(j, posxfinf, posyfinf) == true))
					listapeonb.setpos(i, 10, 3);
			}
		}

		//torreb1
		for (int i = 0; i < 8; i++) {
			if ((torreb1.getx() == posxfinf && torreb1.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyn.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				torreb1.setpos(10, 3);
		}

		//torreb2
		for (int i = 0; i < 8; i++) {
			if ((torreb2.getx() == posxfinf && torreb2.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyn.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				torreb2.setpos(10, 3);
		}

		//caballob1

		for (int i = 0; i < 8; i++) {
			if ((caballob1.getx() == posxfinf && caballob1.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyn.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				caballob1.setpos(10, 3);
		}

		//caballob2

		for (int i = 0; i < 8; i++) {
			if ((caballob2.getx() == posxfinf && caballob2.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyn.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				caballob2.setpos(10, 3);
		}

		//reina blanca comida por piezas negras
		for (int i = 0; i < 8; i++) {
			if ((reinab.getx() == posxfinf && reinab.gety() == posyfinf) && ((alfiln1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln1.getx() && posyf == alfiln1.gety()) || (alfiln2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == alfiln2.getx() && posyf == alfiln2.gety()) || (torren1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren1.getx() && posyf == torren1.gety()) || (torren2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == torren2.getx() && posyf == torren2.gety()) || (reinan.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reinan.getx() && posyf == reinan.gety()) || (reyn.mov_correcto(posxfinf, posyfinf) == 1 && posxf == reyn.getx() && posyf == reyn.gety()) || (caballon1.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon1.getx() && posyf == caballon1.gety()) || (caballon2.mov_correcto(posxfinf, posyfinf) == 1 && posxf == caballon2.getx() && posyf == caballon2.gety()) || listapeonn.comprobacioncome(i, posxfinf, posyfinf) == true))
				reinab.setpos(10, 3);
		}

		cout << "valores de los turnos piezas negras.Si es 0 es que se han movido" << alfilb1.getturno() << alfilb2.getturno() << caballob1.getturno() << caballob2.getturno() << torreb1.getturno() << torreb2.getturno() << reyb.getturno() << reinab.getturno() << endl << endl;

	}





	if (alfiln1.getturno() == 0 && alfiln2.getturno() == 0 && caballon1.getturno() == 0 && caballon2.getturno() == 0 && torren1.getturno() == 0 && torren2.getturno() == 0 && reyn.getturno() == 0 && reinan.getturno() == 0 && listapeonn.getturno() == 0)
	{

		//se mueven negras
		listapeonn.mueve(posxf, posyf, posxfinf, posyfinf);
		alfiln1.mueve(posxf, posyf, posxfinf, posyfinf);
		alfiln2.mueve(posxf, posyf, posxfinf, posyfinf);
		reinan.mueve(posxf, posyf, posxfinf, posyfinf);
		torren1.mueve(posxf, posyf, posxfinf, posyfinf);
		torren2.mueve(posxf, posyf, posxfinf, posyfinf);
		caballon1.mueve(posxf, posyf, posxfinf, posyfinf);
		caballon2.mueve(posxf, posyf, posxfinf, posyfinf);
		reyn.mueve(posxf, posyf, posxfinf, posyfinf);

		//una vez se han movido negras el turno pasa a ser 1 de la movida
		if (alfiln1.getturno() == 1 || alfiln2.getturno() == 1 || caballon1.getturno() == 1 || caballon2.getturno() == 1 || torren1.getturno() == 1 || torren2.getturno() == 1 || reyn.getturno() == 1 || reinan.getturno() == 1 || listapeonn.getturno() == 1)
		{

			alfiln1.setturno(1);
			alfiln2.setturno(1);
			caballon1.setturno(1);
			caballon2.setturno(1);
			torren1.setturno(1);
			torren2.setturno(1);
			reinan.setturno(1);
			reyn.setturno(1);
			listapeonn.setturno(1);



			turnob = 0; //se cambia turno a blancas
			cout << "ahora le toca mover a BLANCAS" << endl;

			alfilb1.setturno(0);
			alfilb2.setturno(0);
			caballob1.setturno(0);
			caballob2.setturno(0);
			torreb1.setturno(0);
			torreb2.setturno(0);
			reinab.setturno(0);
			reyb.setturno(0);
			listapeonb.setturno(0);

			cout << "valores de los turnos piezas negras.Aqui tienen que ser 1 porque se han BLOQUEADO" << alfilb1.getturno() << alfilb2.getturno() << caballob1.getturno() << caballob2.getturno() << torreb1.getturno() << torreb2.getturno() << reyb.getturno() << reinab.getturno() << endl << endl;
		}
	}




	//movimiento de piezas blancas
	else if (alfilb1.getturno() == 0 && alfilb2.getturno() == 0 && caballob1.getturno() == 0 && caballob2.getturno() == 0 && torreb1.getturno() == 0 && torreb2.getturno() == 0 && reyb.getturno() == 0 && reinab.getturno() == 0 && listapeonn.getturno() == 0)
	{


		listapeonb.mueve(posxf, posyf, posxfinf, posyfinf);
		alfilb1.mueve(posxf, posyf, posxfinf, posyfinf);
		alfilb2.mueve(posxf, posyf, posxfinf, posyfinf);
		reinab.mueve(posxf, posyf, posxfinf, posyfinf);
		torreb1.mueve(posxf, posyf, posxfinf, posyfinf);
		torreb2.mueve(posxf, posyf, posxfinf, posyfinf);
		caballob1.mueve(posxf, posyf, posxfinf, posyfinf);
		caballob2.mueve(posxf, posyf, posxfinf, posyfinf);
		reyb.mueve(posxf, posyf, posxfinf, posyfinf);

		if (alfilb1.getturno() == 1 || alfilb2.getturno() == 1 || caballob1.getturno() == 1 || caballob2.getturno() == 1 || torreb1.getturno() == 1 || torreb2.getturno() == 1 || reyb.getturno() == 1 || reinab.getturno() == 1 || listapeonb.getturno() == 1)

		{

			alfilb1.setturno(1);
			alfilb2.setturno(1);
			caballob1.setturno(1);
			caballob2.setturno(1);
			torreb1.setturno(1);
			torreb2.setturno(1);
			reinab.setturno(1);
			reyb.setturno(1);
			listapeonb.setturno(1);

			turnob = 1;//turno cambia a negras
			cout << "ahora le toca mover a NEGRAS" << endl;

			alfiln1.setturno(0);
			alfiln2.setturno(0);
			caballon1.setturno(0);
			caballon2.setturno(0);
			torren1.setturno(0);
			torren2.setturno(0);
			reinan.setturno(0);
			reyn.setturno(0);
			listapeonn.setturno(0);

			cout << "valores de los turnos piezas negras.Aqui tienen que ser 0 porque se han DESBLOQUEADO" << alfilb1.getturno() << alfilb2.getturno() << caballob1.getturno() << caballob2.getturno() << torreb1.getturno() << torreb2.getturno() << reyb.getturno() << reinab.getturno() << endl << endl;
		}

	}
}


void mundo::hayjaqueB() //ok
{
	if (caballob1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl; //Cambiar por imagen que salte en pantalla
	if (caballob2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torreb1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torreb2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfilb1.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfilb2.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (reinab.mov_correcto(reyn.getx(), reyn.gety()) == 1)
		cout << "Hay jaque" << endl;

}

void mundo::hayjaqueN() //ok
{
	if (caballon1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (caballon2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torren1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (torren2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfiln1.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (alfiln2.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;
	if (reinan.mov_correcto(reyb.getx(), reyb.gety()) == 1)
		cout << "Hay jaque" << endl;

}
