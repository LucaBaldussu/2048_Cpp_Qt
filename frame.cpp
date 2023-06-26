#include "frame.h"
#include <QDebug>
//assegnazione costruttori classe
frame::frame(QWidget *parent) : QWidget(parent) {//costruttore

    srand((unsigned) time(NULL));
    frameGriglia = new QGridLayout(this);

    for(int z = 0; z<casella::area; z++){
        for (int v = 0; v<casella::area; v++){
            matrix[z][v] = new casella(z, v, this);
            frameGriglia->addWidget(matrix[z][v], v, z);
        }
    }
    setLayout(frameGriglia);
    frame::generaRandom();
    frame::generaRandom();
}

//assegnazione metodi della classe

void frame::generaRandom(){//generazione nuova casella in posto vuoto casuale
    if (checkvuote()){
        int randomPosX;
        int randomPosY;
        bool trovata = false;
        while(!trovata){
            randomPosX = rand()%casella::area;
            randomPosY = rand()%casella::area;
            if(matrix[randomPosX][randomPosY]->testo.isEmpty() ){
                matrix[randomPosX][randomPosY]->nuovo();
                trovata = true;
            }
        }
    }
}

void frame::muoviSinistra(){
    for (int y = 0; y<casella::area; y++){
        for (int contatore = 0; contatore<casella::area-1; contatore++){
            for (int x = contatore+1; x>0; x--){
                if (!matrix[x][y]->vuoto()){
                    if (matrix[x-1][y]->vuoto()){
                        matrix[x-1][y]->clona(matrix[x][y]);
                        matrix[x][y]->svuota();
                    }else if (matrix[x-1][y]->valore==matrix[x][y]->valore && matrix[x][y]->moltiplicabile && matrix[x-1][y]->moltiplicabile){
                        matrix[x-1][y]->raddoppia();
                        matrix[x][y]->svuota();
                    }
                }
                //qDebug() << "X: " << x << " mentre Y: " << y;
            }
        }
    }
}

void frame::muoviSu(){
    for (int x = 0; x<casella::area; x++){
        for (int contatore = 0; contatore<casella::area-1; contatore++){
            for (int y = contatore+1; y>0; y--){
                if (!matrix[x][y]->vuoto()){
                    if (matrix[x][y-1]->vuoto()){
                        matrix[x][y-1]->clona(matrix[x][y]);
                        matrix[x][y]->svuota();
                    }else if (matrix[x][y-1]->valore==matrix[x][y]->valore && matrix[x][y]->moltiplicabile && matrix[x][y-1]->moltiplicabile){
                        matrix[x][y-1]->raddoppia();
                        matrix[x][y]->svuota();
                    }
                }
                //qDebug() << "X: " << x << " mentre Y: " << y;
            }
        }
    }
}

void frame::muoviGiu(){
    for (int x = 0; x<casella::area; x++){
        for (int contatore = 0; contatore<casella::area-1; contatore++){
            for (int y = (casella::area-2-contatore); y<(casella::area-1); y++){
                if (!matrix[x][y]->vuoto()){
                    if (matrix[x][y+1]->vuoto()){
                        matrix[x][y+1]->clona(matrix[x][y]);
                        matrix[x][y]->svuota();
                    }else if (matrix[x][y+1]->valore==matrix[x][y]->valore && matrix[x][y]->moltiplicabile && matrix[x][y+1]->moltiplicabile){
                        matrix[x][y+1]->raddoppia();
                        matrix[x][y]->svuota();
                    }
                    }
//                qDebug() << "X: " << x << " mentre Y: " << y;
            }
        }
    }
}

void frame::muoviDestra(){
    for (int y = 0; y<casella::area; y++){
        for (int contatore = 0; contatore<casella::area-1; contatore++){
            for (int x = (casella::area-2-contatore); x<(casella::area-1); x++){
                    if (!matrix[x][y]->vuoto()){
                    if (matrix[x+1][y]->vuoto()){
                        matrix[x+1][y]->clona(matrix[x][y]);
                        matrix[x][y]->svuota();
                    }else if (matrix[x+1][y]->valore==matrix[x][y]->valore && matrix[x][y]->moltiplicabile && matrix[x+1][y]->moltiplicabile){
                        matrix[x+1][y]->raddoppia();
                        matrix[x][y]->svuota();
                    }
                    }
                    //                qDebug() << "X: " << x << " mentre Y: " << y;
            }
        }
    }
}

void frame::fineTurni(){
    for(int z = 0; z<casella::area; z++){
        for (int v = 0; v<casella::area; v++){
                matrix[z][v]->fineTurno();
        }
    }
}

bool frame::checkvuote(){
    for(int z = 0; z<casella::area; z++){
        for (int v = 0; v<casella::area; v++){
                if(matrix[z][v]->vuoto()){
                    return true;
                }
        }
    }
    return false;
}

void frame::keyPressEvent(QKeyEvent *event)//risposta pressione tasti
{
    switch(event->key()){
        case Qt::Key_Left:
        //premuto sinistra
        muoviSinistra();
        fineTurni();
        generaRandom();
        break;

        case Qt::Key_Up:
        //premuto su
        muoviSu();
        fineTurni();
        generaRandom();
        break;

        case Qt::Key_Right:
        //premuto destra
        muoviDestra();
        fineTurni();
        generaRandom();
        break;

        case Qt::Key_Down:
        //premuto giù
        muoviGiu();
        fineTurni();
        generaRandom();
        break;
    }
}
