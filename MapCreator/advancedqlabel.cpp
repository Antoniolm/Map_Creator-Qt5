///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "advancedqlabel.h"

AdvancedQLabel::AdvancedQLabel(QString string,QWidget *parent) : QLabel(parent)
{
    setText(string);
    setStyleSheet("QLabel {background: gray;border:1px solid black;}");
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //setFixedHeight(20);
    setMinimumHeight(10);
    setMinimumWidth(10);
    setMaximumHeight(30);
    setMaximumWidth(30);
    //setFixedWidth(20);
    connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));
}

AdvancedQLabel::~AdvancedQLabel(){


}
void AdvancedQLabel::slotClicked(){

}

void AdvancedQLabel::mousePressEvent(QMouseEvent *ev){

    emit clicked();
}

void AdvancedQLabel::operator=(const AdvancedQLabel &label){

}
