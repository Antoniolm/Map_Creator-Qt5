///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#ifndef TEXTUREQLABEL_H
#define TEXTUREQLABEL_H

#include <QVBoxLayout>
#include <QWidget>
#include <advancedqlabel.h>
#include <qpixmap.h>

class TextureQLabel : public QWidget
{
    Q_OBJECT
public:
    explicit TextureQLabel(QString,QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *ev);
    void setImgTexture(QString );
    QString getImgTexture();

signals:
    void clicked();
public slots:
    void slotClicked();

private:
    QLabel *texture,*stateTexture;
    QString imgTexture;
};

#endif // TEXTUREQLABEL_H
