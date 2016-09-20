///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#ifndef CELL_H
#define CELL_H

#include <QString>

using namespace std;

class Cell
{
public:
    Cell();
    void setImgTexture(QString );
    void setState(QString &);
    void setPosition(int,int);
    QString getImgTexture();
    QString getState();
    pair<int,int> getPosition();
    bool hasTexture();
    void clear();

private:
    QString imgTexture,state;
    pair<int,int> position; //Posición de la celda <height,width>
};

#endif // CELL_H
