/* 
 * File:   Invasores.h
 * Author: thiago
 *
 * Created on 18 de Setembro de 2015, 17:37
 */

#ifndef INVASORES_H
#define	INVASORES_H

#include "Asteroide.h"

class Invasores{
protected:
    static int id;
    int inc;
    int numAsteroides;
    Asteroide * oAsteroide;
public:  
    Invasores(){
        numAsteroides = 1;
        oAsteroide = new Asteroide[numAsteroides];
        for(int i = 0; i < numAsteroides; i++){            
            oAsteroide[i].inicializa(id);
            id++;
        }
    }
    void desenha(){
        for(int i = 0; i < numAsteroides; i++){            
            oAsteroide[i].desenha(20, 300, 300);
        }
    }
    
    void moveAsteroides(){
        for(int i = 0; i < numAsteroides; i++){            
            oAsteroide[i].move();
        }
    }
};

int Invasores::id = 0;

#endif	/* INVASORES_H */

