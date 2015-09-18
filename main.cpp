#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;
#include "Invasores.h"
#include "Nave.h"


GLint larg = 600;
GLint alt = 400;

Nave nave;
Invasores invasores;



void init(void);
void display(void);
void tiro(int);
void asteroide(int);
void colisao(int);
void keyboard(unsigned char key, int x, int y);


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    //  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(larg, alt);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Cefetoids");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(10, tiro, 1);
    glutTimerFunc(10, asteroide, 1);
    glutKeyboardFunc(keyboard);
    //glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0, larg, 0, alt, -1, 1);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();    
    glColor3f(0.5, 0.5, 1);
        glTranslatef(larg/2 -50, alt/2 -50, 0);
        invasores.desenha();
        nave.desenha();
    glPopMatrix();
              
    glFlush();
    glutSwapBuffers();
}



void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 97:
            nave.gira(1,1) ;
            break;
        case 115:
            nave.gira(-1,1);
            break; 
        case 100:
            nave.atira();
            break;             
    }
}

void tiro(int cont) {
    nave.impulsionaTiro();
    glutPostRedisplay();
    glutTimerFunc(10, tiro, 1);
}

void asteroide(int cont) {
    invasores.moveAsteroides();
    glutPostRedisplay();
    glutTimerFunc(10, asteroide, 1);
}

void colisao(int cont) {

    glutPostRedisplay();
    glutTimerFunc(10, colisao, 1);
}