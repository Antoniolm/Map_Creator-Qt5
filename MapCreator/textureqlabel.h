///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#ifndef TEXTUREQLABEL_H
#define TEXTUREQLABEL_H

#include <QVBoxLayout>
#include <advancedqlabel.h>
#include <qpixmap.h>

class TextureQLabel : public QVBoxLayout
{
    Q_OBJECT
public:
    explicit TextureQLabel(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *texture,*stateTexture;
};

#endif // TEXTUREQLABEL_H
