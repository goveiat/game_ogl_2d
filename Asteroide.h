/* 
 * File:   Asteroide.h
 * Author: thiago
 *
 * Created on 18 de Setembro de 2015, 16:52
 */

#ifndef ASTEROIDE_H
#define	ASTEROIDE_H
#define PI 3.1415926535897932384626433832795

#include "Inimigo.h"


class Asteroide : public Inimigo {
private:
    float raio;
public:    
    void desenha(float raio, int x, int y){
        this->raio = raio;
        this->x = x+inc;
        this->y = y+inc;
        glPushMatrix();
        glBegin(GL_POLYGON);
            for(double i = 0; i < 2 * PI; i += PI / 6){
                glVertex3f(cos(i) * raio + this->x, sin(i) * raio + this->y, 0.0);
            }
        glEnd();
        glPopMatrix();
    }
    
    void move(){
        inc -= 0.8;
    }
};


#endif	/* ASTEROIDE_H */

