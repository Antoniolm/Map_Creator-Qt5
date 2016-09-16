///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#ifndef ADVANCEDQLABEL_H
#define ADVANCEDQLABEL_H

#include <QLabel>

class AdvancedQLabel : public QLabel
{
    Q_OBJECT
public:
    explicit AdvancedQLabel(QString,int minH,int minW,int maxH,int maxW,QWidget *parent = 0);
    ~AdvancedQLabel();
    void mousePressEvent(QMouseEvent *ev);
    void setImgTexture(QString);
    QString getImgTexture();
signals:
    void clicked();
public slots:
    void slotClicked();

private:
    QString imgTexture;
};

#endif // ADVANCEDQLABEL_H
