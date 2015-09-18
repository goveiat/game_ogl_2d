/* 
 * File:   Inimigo.h
 * Author: thiago
 *
 * Created on 18 de Setembro de 2015, 17:32
 */

#ifndef INIMIGO_H
#define	INIMIGO_H

class Inimigo{
protected:
    int id;
    float inc;
    int x;
    int y;
public:
    void inicializa(int id){
        this->id = id;
        inc = 0;
    }
    
};

#endif	/* INIMIGO_H */

