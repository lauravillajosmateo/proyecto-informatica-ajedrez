#include "marco.h"
#include <freeglut.h>



void Marco::dibuja() {

    glBegin(GL_LINES);//abajo
    glColor3f(255, 0, 255);
    glVertex3f(-0.01, -0.01, 0);
    glVertex3f(8.01, -0.01, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(-0.03, -0.03, 0);
    glVertex3f(8.03, -0.03, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(-0.05, -0.05, 0);
    glVertex3f(8.05, -0.05, 0);
    glEnd();

    glBegin(GL_LINES);//izquierda
    glColor3f(255, 0, 255);
    glVertex3f(-0.01, 0, 0);
    glVertex3f(-0.01, 8.01, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(-0.03, 0, 0);
    glVertex3f(-0.03, 8.03, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(-0.05, 0, 0);
    glVertex3f(-0.05, 8.05, 0);
    glEnd();

    glBegin(GL_LINES);//arriba
    glColor3f(255, 0, 255);
    glVertex3f(-0.01, 8.01, 0);
    glVertex3f(8.01, 8.01, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(-0.03, 8.03, 0);
    glVertex3f(8.03, 8.03, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(-0.05, 8.05, 0);
    glVertex3f(8.05, 8.05, 0);
    glEnd();

    glBegin(GL_LINES);//derecha
    glColor3f(255, 0, 255);
    glVertex3f(8.01, 8.01, 0);
    glVertex3f(8.01, -0.01, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(8.03, 8.03, 0);
    glVertex3f(8.03, -0.03, 0);
    glEnd();
    glBegin(GL_LINES);
    glColor3f(255, 0, 255);
    glVertex3f(8.05, 8.05, 0);
    glVertex3f(8.05, -0.05, 0);
    glEnd();



}