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
    //connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));

    if(imgTextu.isEmpty()){
        setStyleSheet("QLabel {background: gray;border:1px solid black;}");
    }
    else{
        imgTexture=imgTextu;
        QPixmap pixmap(":/texture/texture/"+imgTexture);
        pixmap=pixmap.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio, Qt::FastTransformation);
        setPixmap(pixmap);
        setGeometry(50,50,pixmap.width(),pixmap.height());
        show();
    }


}

AdvancedQLabel::~AdvancedQLabel(){


}
void AdvancedQLabel::slotClicked(){

}

//////////////////////
/// \brief AdvancedQLabel::mousePressEvent
/// \param ev
/// Signal creado para darle la funcionalidad de clickeo sobre nuestro QLabel
/////////////////////
void AdvancedQLabel::mousePressEvent(QMouseEvent *ev){
    if(ev->buttons() == Qt::RightButton && ev->buttons()!=Qt::LeftButton){
        imgTexture.clear();
        QPixmap pixmap("");
        setPixmap(pixmap);
    }
}

//////////////////////
/// \brief AdvancedQLabel::mouseMoveEvent
/// \param ev
/// Signal creado para darle la funcionalidad de movimiento del raton sobre nuestro QLabel
/////////////////////
void AdvancedQLabel::mouseMoveEvent(QMouseEvent *ev){
    if(ev->buttons() != Qt::RightButton && ev->buttons()==Qt::LeftButton){
        emit move();
    }
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
        setPixmap(pixmap.scaled(this->width()-2,this->height()-3,Qt::IgnoreAspectRatio, Qt::FastTransformation));
        show();
    }
}

///////////////////////////
/// \brief AdvancedQLabel::isTexture
/// \return
/// Método para saber si la celda tiene una textura o no
/////////////////////
bool AdvancedQLabel::hasTexture(){
    bool salida=true;
    if(imgTexture.isEmpty())
        salida=false;

    return salida;
}

////////////////////
/// \brief AdvancedQLabel::clear
/// Método para limpiar nuestro objecto
/// sin perder su configuración inicial
////////////////////
void AdvancedQLabel::clear(){
    imgTexture.clear();
    QPixmap pixmap("");
    setPixmap(pixmap);
}
