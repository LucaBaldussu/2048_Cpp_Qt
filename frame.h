#ifndef FRAME_H
#define FRAME_H

#include <QWidget>
#include <random>
#include "casella.h"
#include <QGridlayout>
#include <QKeyEvent>

class frame : public QWidget
{//dichiarazione frame di gioco
    Q_OBJECT//necessario per la definizione di slots nuovi
public:
    frame(QWidget *parent = nullptr);
    casella * matrix[casella::area][casella::area];//matrice di widget di x=n e y=n dimensioni
    QGridLayout * frameGriglia;
protected:
    void keyPressEvent(QKeyEvent *event);
    void muoviGiu();
    void muoviSu();
    void muoviDestra();
    void muoviSinistra();
    void fineTurni();
    bool checkvuote();

private slots://dichiarazione slots ossia metodi collegabili a signals
   // void genera(int matrix[][]);
private:
    void generaRandom();
    QLabel *lbl;
};

#endif // FRAME_H
