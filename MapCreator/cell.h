///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#ifndef CELL_H
#define CELL_H

#include <QString>

class Cell
{
public:
    Cell();
    void setImgTexture(QString );
    void setState(QString &);
    QString getImgTexture();
    QString getState();

private:
    QString imgTexture,state;
};

#endif // CELL_H
