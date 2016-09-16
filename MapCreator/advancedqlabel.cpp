///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "advancedqlabel.h"

AdvancedQLabel::AdvancedQLabel(QString imgTextu,int minH,int minW,int maxH,int maxW,QWidget *parent) : QLabel(parent)
{
    setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //setFixedHeight(20);
    setMinimumHeight(minH);
    setMinimumWidth(minW);
    setMaximumHeight(maxH);
    setMaximumWidth(maxW);
    //setFixedWidth(20);
    connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));

    if(imgTextu.isEmpty()){
        setStyleSheet("QLabel {background: gray;border:1px solid black;}");
    }
    else{
        imgTexture=imgTextu;
        QPixmap pixmap(":/texture/texture/"+imgTexture);
        setPixmap(pixmap);
        show();
    }


}

AdvancedQLabel::~AdvancedQLabel(){


}
void AdvancedQLabel::slotClicked(){

}

///
/// \brief AdvancedQLabel::mousePressEvent
/// \param ev
///
void AdvancedQLabel::mousePressEvent(QMouseEvent *ev){

    emit clicked();
}

///
/// \brief AdvancedQLabel::setImgTexture
///
void AdvancedQLabel::setImgTexture(QString textur){
    imgTexture=textur;
}

///
/// \brief AdvancedQLabel::getImgTexture
///
QString AdvancedQLabel::getImgTexture(){
    return imgTexture;

}

////////////////////////
/// \brief AdvancedQLabel::loadTexture
///  Realizara la carga en el QLabel de la imagen
///  si hay una imagen
///////////////////
void AdvancedQLabel::loadTexture(){
    if(!imgTexture.isEmpty()){
        QPixmap pixmap(":/texture/texture/"+imgTexture);
        setPixmap(pixmap.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation));
        show();
    }


}

