/* programa TELEJOGO */
/* Prof. Marco Antonio G. de Carvalho, UNICAMP-2006 */
/* EXEMPLO DE ANIMACAO */

#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

GLint movebola = 0;
GLint moveq = 0;
GLint direcao = 1;
GLint larg = 600;
GLint alt = 400;
GLint giro = 0;
GLint acres = 0;
GLint st = 0;



void init(void);
void display(void);
void bola(int passo);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    //  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(larg, alt);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Atari");
    init();
    glutDisplayFunc(display);
    glutTimerFunc(10, bola, 1);
    glutKeyboardFunc(keyboard);
    //glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0, 600, 0, 400, -1, 1);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
        glTranslatef(larg/2 -50, alt/2 -50, 0);
        glRotatef(30, 0, 0, 1);
        glPushMatrix();
            glTranslatef(50, 33, 0);
            glRotatef(giro, 0, 0, 1);
            glTranslatef(-50, -33, 0);
            glColor3f(1, 1, 1);
            glBegin(GL_TRIANGLES);
                glVertex2f(0, 0);
                glVertex2f(100, 0);
                glVertex2f(50, 100);
            glEnd(); 
            glColor3f(1, 1, 0);
            glBegin(GL_TRIANGLES);
                glVertex2f(50, 100);
                glVertex2f(40, 80);
                glVertex2f(60, 80);                    
            glEnd();              
        glPopMatrix(); 
    glPopMatrix();
              
            

    

     glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 65:
            giro = giro + 1 + sqrt(giro);
            break;
        case 66:
            giro = giro - 1 - sqrt(abs(giro));
            break; 
        case 67:
            st = 1;
            break;             
    }
}

void bola(int passo) {
    acres++;
    glutPostRedisplay();
    glutTimerFunc(10, bola, 1);

}