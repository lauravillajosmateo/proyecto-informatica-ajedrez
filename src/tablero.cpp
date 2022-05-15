#include "tablero.h"
#include <freeglut.h>

void tablero::Dibuja()
{




    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++)
        {

            if ((i + j) % 2 == 0) {
                glDisable(GL_LIGHTING);
                glColor3ub(255, 255, 255); //blanco
                glBegin(GL_POLYGON);
                glVertex3f(i, j, 0);
                glVertex3f(i, j + 1, 0);
                glVertex3f(i + 1, j + 1, 0);
                glVertex3f(i + 1, j, 0);
                glEnd();

            }
            else {
                glColor3ub(0, 255, 255); //azul
                glBegin(GL_POLYGON);
                glVertex3f(i, j, 0);
                glVertex3f(i, j + 1, 0);
                glVertex3f(i + 1, j + 1, 0);
                glVertex3f(i + 1, j, 0);
                glEnd();

            }


            glEnable(GL_LIGHTING);
        }
    }

}

