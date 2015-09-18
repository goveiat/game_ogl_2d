/* 
 * File:   Tiro.h
 * Author: thiago
 *
 * Created on 18 de Setembro de 2015, 08:34
 */

#ifndef TIRO_H
#define	TIRO_H

class Tiro{
private:
    int id;
    float inc; 
    int x;
    int y;
public:
    void inicializa(int id){
        this->id = id;
        inc = 0;
    }    
    void desenha(int id){
        glColor3f(0, 1, 1); 
        glBegin(GL_TRIANGLES);
            glVertex2f(50, 100 - deslocamento() + inc);
            glVertex2f(40, 80 - deslocamento() + inc);
            glVertex2f(60, 80 - deslocamento() + inc);                    
        glEnd(); 
    }
    
    int deslocamento(){
        return 10*(id + 1);
    }
    
    void atirou(){
        inc = 1;       
    }
    
    void move(){
        inc*=1.5;
    }
};

#endif	/* TIRO_H */

