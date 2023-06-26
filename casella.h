#ifndef CASELLA_H
#define CASELLA_H

#include <QLabel>

class casella : public QLabel
{
    Q_OBJECT
public:
    static const int area = 4;//dimensione area di gioco
    int pos_x;//coordinata x
    int pos_y;//coordinata y
    int valore;//valore della cella
    QString testo;
    casella(int x, int y, QWidget *parent = nullptr);
    void raddoppia();
    bool vuoto();
    void svuota();
    void clona(casella * daclonare);
    bool moltiplicabile;
    void fineTurno();
    void nuovo();
};

#endif // CASELLA_H
