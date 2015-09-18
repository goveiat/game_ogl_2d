/* 
 * File:   Nave.h
 * Author: thiago
 *
 * Created on 18 de Setembro de 2015, 08:16
 */

#ifndef NAVE_H
#define	NAVE_H

#include "Tiro.h"

class Nave{
private:
    int giro;
    int numTiros;
    int proxTiro;
    Tiro * oTiros;
public:
    
    Nave(){
        numTiros = 5;
        giro = 0;
        proxTiro = 0;
        oTiros = new Tiro[numTiros];
        for(int i = 0; i < numTiros; i++){
            oTiros[i].inicializa(i);
        }
    }
    
    void desenha(){
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
            glColor3f(1, 0, 0);
            glBegin(GL_TRIANGLES);
                glVertex2f(50, 100);
                glVertex2f(40, 80);
                glVertex2f(60, 80);                    
            glEnd();
            for(int i = 0; i < numTiros; i++){
                oTiros[i].desenha(i);
            }
        glPopMatrix();     
    }
    
    void atira(){
        if(proxTiro < numTiros){
            oTiros[proxTiro].atirou();
            proxTiro++;      
        }
    }    
    void gira(float multiplicador, float somador){
        giro += multiplicador*(somador + sqrt(abs(giro)));
    }
    
    void impulsionaTiro(){
        for(int i = 0; i < numTiros; i++){
            oTiros[i].move();
        }
    }
    
    int get_numTiros(){
        return numTiros;
    }

};


#endif	/* NAVE_H */

