///////////////////////////////////////////
///
/// @author Antonio David López Machado
///
///////////////////////////////////////////

#include "textureqlabel.h"

TextureQLabel::TextureQLabel(QString textur,QWidget *parent) : QWidget(parent)
{
    imgTexture=textur;
    QVBoxLayout *vBox=new QVBoxLayout();

    texture=new QLabel("");
    texture->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    texture->setMinimumHeight(30);
    texture->setMinimumWidth(30);
    texture->setMaximumHeight(60);
    texture->setMaximumWidth(80);
    texture->setStyleSheet("QLabel {background: blue;}");
    QPixmap pixmap(":/texture/texture/"+imgTexture);
    texture->setPixmap(pixmap);
    texture->show();

    /*stateTexture=new QLabel("");
    stateTexture->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    stateTexture->setMinimumHeight(5);
    stateTexture->setMinimumWidth(5);
    stateTexture->setMaximumHeight(15);
    stateTexture->setMaximumWidth(80);
    stateTexture->setStyleSheet("QLabel {background: red;}");*/


    vBox->setSpacing(0);
    vBox->addWidget(texture);
    //vBox->addWidget(stateTexture);

    this->setLayout(vBox);
    this->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Expanding);
    this->setStyleSheet("QWidget {background: yellow;}");
    //connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));

}

///
/// \brief TextureQLabel::slotClicked
///
void TextureQLabel::slotClicked(){

}

///
/// \brief TextureQLabel::mousePressEvent
/// \param ev
///
void TextureQLabel::mousePressEvent(QMouseEvent *ev){
    emit clicked();
}

///
/// \brief TextureQLabel::setImgTexture
///
void TextureQLabel::setImgTexture(QString textur){
    imgTexture=textur;
}

///
/// \brief TextureQLabel::getImgTexture
///
QString TextureQLabel::getImgTexture(){
    return imgTexture;

}



