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
    explicit AdvancedQLabel(QString,QWidget *parent = 0);
    ~AdvancedQLabel();
    void mousePressEvent(QMouseEvent *ev);
signals:
    void clicked();
public slots:
    void slotClicked();

};

#endif // ADVANCEDQLABEL_H
