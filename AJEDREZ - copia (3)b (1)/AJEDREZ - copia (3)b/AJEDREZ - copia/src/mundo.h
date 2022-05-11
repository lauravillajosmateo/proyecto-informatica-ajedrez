#pragma once

#include "tablero.h"
#include "peon.h"
#include "peonn.h"
#include "ListaPeonNegro.h"
#include "ListaPeonBlanco.h"
#include "rey.h"
#include "reyN.h"
#include "alfil.h"
#include "alfilN.h"
#include "caballo.h"
#include "caballoN.h"
#include "reina.h"
#include "reinaN.h"
#include "torre.h"
#include "torreN.h"
#include "marco.h"


class mundo
{
public:
	float x;
	float y;
	float z;

	ListaPeonNegro listapeonn; //hay 8 peones negros
	ListaPeonBlanco listapeonb; //hay 8 peones blancos
	rey reyb;
	reyN reyn;

	reina reinab;
	reinaN reinan;

	caballo caballob1;
	caballo caballob2;
	caballoN caballon1;
	caballoN caballon2;

	torre torreb1;
	torre torreb2;
	torreN torren1;
	torreN torren2;

	alfil alfilb1;
	alfil alfilb2;
	alfilN alfiln1;
	alfilN alfiln2;

	Marco marco1;
	
	


	mundo();
	void inicializa();
	void dibuja();
	void mueve();
	void tecla(unsigned char key);
	
	tablero tablero1;

};